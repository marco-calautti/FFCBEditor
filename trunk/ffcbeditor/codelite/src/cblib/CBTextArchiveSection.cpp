#include "CBTextArchiveSection.h"
#include <wx/sstream.h>
#include <wx/mstream.h>

CBTextArchiveSection::CBTextArchiveSection(wxByte *buffer,wxUint32 num)
{
	Init(buffer,num);
}
void CBTextArchiveSection::Init(wxByte *buffer,wxUint32 num)
{
	writableBuffer=NULL;
	size=num;
	texts=new wxString[size];
	for(size_t i=0;i<size;i++){
		wxUint32 pos=wxINT32_SWAP_ON_LE(((wxUint32*)buffer)[i]);
		
		if(i<size-1){ //is unicode?
			wxUint32 pos2=wxINT32_SWAP_ON_LE(((wxUint32*)buffer)[i+1]); //next pointer

			wxASSERT_MSG(pos2>=pos,_("No ascending pointers!")); //we are assuming there are only consecutive pointers
			if((pos2-pos)>1&&(pos2-pos)%2==0&&buffer[pos]==0){ //probably unicode
				char* isoBuf=new char[(pos2-pos)/2];
				for(size_t j=0;j<(pos2-pos)/2;j++){
					wxASSERT_MSG(buffer[pos+j*2]==0,_("Unicode identification is not valid!"));
					isoBuf[j]=buffer[pos+j*2+1];
				}
				texts[i]=wxT("<UNICODE>")+wxString(isoBuf,wxConvISO8859_1);
				delete[] isoBuf;
				continue;
			}
		}
		texts[i]=wxString((const char*)&buffer[pos],wxConvISO8859_1);
	}	
}

CBTextArchiveSection::~CBTextArchiveSection()
{
	if(texts)
		delete[] texts;
	if(writableBuffer)
		delete[] writableBuffer;
}

wxString CBTextArchiveSection::GetText()
{
	return GetText(0);
}

void CBTextArchiveSection::SetText(wxString &text)
{
	/*wxStringInputStream strIn(text);
	wxTextInputStream input(strIn);
	
	bool nullFound=false;
	size_t j=0;
	wxString curStr;
	wxString line=input.ReadLine();

	while(strIn.LastRead()!=0){

		for(size_t i=0;i<line.Length();i++){
			if(line[i]=='<'){ //trovato un tag (quello che mi interessa è NULL)
				size_t pos=line.find('>',i);
				wxASSERT_MSG(pos!=wxString::npos,wxT("Tag non chiuso!"));
				if(line(i,pos+1-i)==wxT("<NULL>")){
					nullFound=true;
					break;
				}else
					curStr+=line[i];

			}else
				curStr+=line[i];
		}

		if(!nullFound){
			curStr+=wxT("<n>");
			line=input.ReadLine();
		}else{
			texts[j++]=curStr;
			curStr.Clear();
			nullFound=false;
			line=input.ReadLine();
			while(line.IsEmpty()&&strIn.LastRead()!=0)
				line=input.ReadLine();
		}
	}
	*/
	SetText(0,text);
	
}

wxString CBTextArchiveSection::GetText(size_t i)
{
	return Parse(i);
}

void CBTextArchiveSection::SetText(size_t j,wxString& text)
{
	wxString temp;
	
	for(size_t i=0;i<text.Length();i++){
		if(text[i]!='\n') //normal char
			temp+=text[i];
		else{ //carriage return
			temp+=wxT("<n>");
		}
	}
	
	texts[j]=temp;

	if(writableBuffer)
		delete[] writableBuffer;

	writableBuffer=NULL;
}

size_t CBTextArchiveSection::Size()
{
	return size;
}

wxString CBTextArchiveSection::Parse(size_t i)
{
	wxString result;
	size_t k=0;
	while(k<texts[i].Length()){
		if(texts[i][k]=='<'&&texts[i][k+1]=='n'&&texts[i][k+2]=='>'){ //carriage return
			result+='\n';
			k+=3;
		}else{
			result+=texts[i][k];
			k++;
		}
	}

	return result;
}

char* CBTextArchiveSection::GetWritableBuffer(wxUint32* len)
{
	if(writableBuffer){
		*len=curBufferSize;
		return writableBuffer;
	}
		
	
	wxMemoryOutputStream outBuf; //text buffer
	wxUint32* pointersBuf=new wxUint32[size]; //pointers buffer
	wxUint32 curPos=size*sizeof(wxUint32);

	for(size_t i=0;i<size;i++){ //for each null terminated text block
		wxUint32 strBufSize=0;
		bool unicode;
		char* strBuf=GetBuf(i,&strBufSize,&unicode); //converts text to binary data and retrieves size
		
		pointersBuf[i]=curPos; //setting current pointer
		outBuf.Write(strBuf,strBufSize); //writing text data
		
		if(unicode){
			outBuf.PutC(0); //end of string
			outBuf.PutC(0); //end of string
			curPos+=(strBufSize+2); 
		}else{
			outBuf.PutC(0); //fine stringa
			curPos+=(strBufSize+1);
		}
		
		if(strBuf)
			delete[] strBuf; //frees memory
	}
	
	wxUint32 pointersSize=size*sizeof(wxUint32);
	*len=pointersSize+outBuf.GetLength();
	curBufferSize=*len;
	writableBuffer=new char[*len]; //final data buffer
	
	for(size_t i=0;i<size;i++) //copying pointers header
		((wxUint32*)writableBuffer)[i]=wxINT32_SWAP_ON_LE(pointersBuf[i]);
		
	//writing text
	outBuf.CopyTo(&writableBuffer[pointersSize],outBuf.GetLength());

	delete[] pointersBuf; //frees memory
	
	return writableBuffer;
}

void CBTextArchiveSection::FreeBuffer()
{
	if(writableBuffer)
		delete[] writableBuffer;
	writableBuffer=NULL;
	curBufferSize=0;
}

char* CBTextArchiveSection::GetBuf(size_t i,wxUint32* bufSize,bool* unicode)
{
	char* strBuf=NULL;

	if(!texts[i].IsEmpty()&&texts[i][0]=='<'){ //checking UNICODE tag
		size_t pos=texts[i].find('>');
		wxASSERT_MSG(pos!=wxString::npos,_("Unclosed tag!"));
		if(texts[i](0,pos+1)==wxT("<UNICODE>")){ //unicode text
			*bufSize=(texts[i].Length()-9)*2; //<UNICODE> is 9 in size
			strBuf=new char[*bufSize+1];
			strcpy(strBuf,(const char*)texts[i].Right(texts[i].Length()-9).mb_str(wxConvISO8859_1)); //converting string to ISO8859
			//converting to UNICODE
			for(size_t j=0;j<(*bufSize)/2;j++){
				strBuf[*bufSize-1-j*2]=strBuf[(*bufSize)/2-1-j]; //storing character
				strBuf[*bufSize-j*2-2]=0x00; //second byte of UNICODE char
			}
			*unicode=true;
			return strBuf;
		}
	}
	
	//no UNICODE text
	*bufSize=texts[i].Length();
		
	strBuf=new char[*bufSize+1];
	strcpy(strBuf,(const char*)texts[i].mb_str(wxConvISO8859_1));

	*unicode=false;
	return strBuf;
}
