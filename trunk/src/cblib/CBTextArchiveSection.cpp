#include "CBTextArchiveSection.h"
#include <wx/sstream.h>
#include <wx/mstream.h>

CBTextArchiveSection::CBTextArchiveSection(wxByte *buffer,wxUint32 num)
{
	writableBuffer=NULL;
	size=num;
	texts=new wxString[size];
	for(size_t i=0;i<size;i++){
		wxUint32 pos=wxINT32_SWAP_ON_LE(((wxUint32*)buffer)[i]);
		
		if(i<size-1){ //vediamo se il testo è unicode
			wxUint32 pos2=wxINT32_SWAP_ON_LE(((wxUint32*)buffer)[i+1]); //puntatore successivo

			wxASSERT_MSG(pos2>=pos,_("No ascending pointers!")); //devo avere puntatori consecutivi
			if((pos2-pos)>1&&(pos2-pos)%2==0&&buffer[pos]==0){ //probabilmente unicode
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
		if(text[i]!='\n') //carattere normale
			temp+=text[i];
		else{ //a capo
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
		if(texts[i][k]=='<'&&texts[i][k+1]=='n'&&texts[i][k+2]=='>'){ //tag a capo
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
	if(writableBuffer)
		return writableBuffer;
	
	wxMemoryOutputStream outBuf; //buffer del testo
	wxUint32* pointersBuf=new wxUint32[size]; //buffer dei puntatori
	wxUint32 curPos=size*sizeof(wxUint32);

	for(size_t i=0;i<size;i++){ //per ogni blocco di testo null terminated
		wxUint32 strBufSize=0;
		bool unicode;
		char* strBuf=GetBuf(i,&strBufSize,&unicode); //converto il testo in dati e prendo la loro dimensione
		
		pointersBuf[i]=curPos; //setto il puntatore attuale
		outBuf.Write(strBuf,strBufSize); //scrivo i dati del testo

		if(unicode){
			outBuf.PutC(0); //fine stringa
			outBuf.PutC(0); //fine stringa
			curPos+=(strBufSize+2); //+2 per il fine stringa
		}else{
			outBuf.PutC(0); //fine stringa
			curPos+=(strBufSize+1); //+1 per il fine stringa
		}

		delete[] strBuf; //elimino il buffer restituito
	}
	
	wxUint32 pointersSize=size*sizeof(wxUint32);
	*len=pointersSize+outBuf.GetLength();
	writableBuffer=new char[(size_t)len]; //buffer dati finale
	
	for(size_t i=0;i<size;i++) //copio l'header con i puntatori
		((wxUint32*)writableBuffer)[i]=wxINT32_SWAP_ON_LE(pointersBuf[i]);
		
	//scrivo il testo
	outBuf.CopyTo(&writableBuffer[pointersSize],outBuf.GetLength());

	delete[] pointersBuf; //non serve più
	
	return writableBuffer;
}

void CBTextArchiveSection::FreeBuffer()
{
	if(writableBuffer)
		delete[] writableBuffer;
	writableBuffer=NULL;
}

char* CBTextArchiveSection::GetBuf(size_t i,wxUint32* size,bool* unicode)
{
	char* buffer=NULL;

	if(!texts[i].IsEmpty()&&texts[i][0]=='<'){ //controllo il tag UNICODE
		size_t pos=texts[i].find('>');
		wxASSERT_MSG(pos!=wxString::npos,_("Unclosed tag!"));
		if(texts[i](0,pos+1)==wxT("<UNICODE>")){ //testo unicode
			*size=(texts[i].Length()-9)*2; //9 è la dimensione di <UNICODE>
			buffer=new char[(size_t)size];
			strcpy(buffer,(const char*)texts[i].Right(texts[i].Length()-9).mb_str(wxConvISO8859_1)); //metto la stringa in ISO
			//converto in UNICODE
			for(size_t j=0;j<*size/2;j++){
				buffer[*size-1-j*2]=buffer[*size/2-1-j]; //metto il carattere
				buffer[*size-j*2-2]=0x00; //secondo byte del carattere unicode
			}
			*unicode=true;
			return buffer;
		}
	}
	
	//testo non unicode
	*size=texts[i].Length();
	buffer=new char[(size_t)size];
	strcpy(buffer,(const char*)texts[i].mb_str(wxConvISO8859_1));

	*unicode=false;
	return buffer;
}
