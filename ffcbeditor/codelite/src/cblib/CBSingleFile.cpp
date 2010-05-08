#include "CBSingleFile.h"
#include "CBSingleFileTextSection.h"
#include <wx/wfstream.h>

CBSingleFile::CBSingleFile(wxString& fileName)
{
	wxFileInputStream stream(fileName);
	Initialize(stream);
}

CBSingleFile::CBSingleFile(const wxChar* fileName)
{
	wxFileInputStream stream(fileName);
	Initialize(stream);
}

CBSingleFile::CBSingleFile(wxInputStream& input)
{
	Initialize(input);
}

void CBSingleFile::Initialize(wxInputStream& input)
{
	unknownSection1=NULL;
	unknownSection2=NULL;
	size_t size=input.GetSize();
	wxByte* buffer=new wxByte[size];
	
	input.Read(buffer,size); 
	
	wxUint32 textPointer=wxINT32_SWAP_ON_LE(((wxUint32*)buffer)[0]); //wii's CPU is big endian
	
	textSection=new CBSingleFileTextSection(&buffer[textPointer]); //creating text section

	wxUint32 secondPointer=wxINT32_SWAP_ON_LE(((wxUint32*)buffer)[1]);
	wxUint32 thirdPointer=wxINT32_SWAP_ON_LE(((wxUint32*)buffer)[2]);

	if(secondPointer!=0){ //second section exists
		wxUint32 sectionSize=0;
		if(thirdPointer!=0){ //last section exsists
			sectionSize=thirdPointer-secondPointer;

			//loading third section
			wxUint32 lastSectionSize=size-thirdPointer;
			unknownSection2=new wxMemoryBuffer(lastSectionSize);
			unknownSection2->AppendData(&buffer[thirdPointer],lastSectionSize);
		}else{ //second section doesn't exists
			sectionSize=size-secondPointer;
		}

		unknownSection1=new wxMemoryBuffer(sectionSize);
		unknownSection1->AppendData(&buffer[secondPointer],sectionSize);
	}

	delete[] buffer;

}
CBSingleFile::~CBSingleFile()
{
	if(textSection)
		delete textSection;
	if(unknownSection1)
		delete unknownSection1;
	if(unknownSection2)
		delete unknownSection2;
}

CBTextSection* CBSingleFile::GetTextSection()
{
	return textSection;
}

int CBSingleFile::SaveTo(wxString& fileName){
	wxFileOutputStream stream(fileName);
	return SaveTo(stream);
}

int CBSingleFile::SaveTo(const wxChar* fileName){
	wxFileOutputStream stream(fileName);
	return SaveTo(stream);
}

int CBSingleFile::SaveTo(wxOutputStream& output)
{
	wxUint32* header=new wxUint32[HEADER_SIZE/sizeof(wxUint32)];
	wxUint32 len;
	char* buf=textSection->GetWritableBuffer(&len);

	header[0]=HEADER_SIZE;
	if(unknownSection1)
		header[1]=header[0]+GetPaddingSize(len+1)+len+1; //len+1: Null terminated string
	else
		header[1]=0;
	
	if(unknownSection2)
		header[2]=header[1]+unknownSection1->GetDataLen();
	else
		header[2]=0;
	
	header[0]=wxINT32_SWAP_ON_LE(header[0]);
	header[1]=wxINT32_SWAP_ON_LE(header[1]);
	header[2]=wxINT32_SWAP_ON_LE(header[2]);

	output.Write(header,HEADER_SIZE);

	output.Write(buf,len);
	output.PutC(NULL);
	for(wxUint32 i=0;i<GetPaddingSize(len+1);i++)
		output.PutC(NULL);

	if(unknownSection1)
		output.Write(unknownSection1->GetData(),unknownSection1->GetDataLen());
	if(unknownSection2)
		output.Write(unknownSection2->GetData(),unknownSection2->GetDataLen());
	
	textSection->FreeBuffer();
	delete[] header;
	return 0;
}

wxUint32 CBSingleFile::GetPaddingSize(wxUint32 curSize)
{
	//Really 0x20 bytes of padding are needed?
	if(curSize%0x20==0)
		return 0;
	
	return (0x20 - curSize%0x20);
}
