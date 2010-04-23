#include "CBSingleFileTextSection.h"

CBSingleFileTextSection::CBSingleFileTextSection(wxByte *buffer)
{
	writableBuffer=NULL;
	text=wxString((const char*)buffer,wxConvISO8859_1);
}

CBSingleFileTextSection::~CBSingleFileTextSection()
{
	if(writableBuffer)
		delete[] writableBuffer;
}

wxString CBSingleFileTextSection::GetText()
{
	wxString result;
	size_t i=0;
	while(i<text.Length()){
		if(text[i]=='<'&&text[i+1]=='n'&&text[i+2]=='>'){ //carriage return
			result+='\n';
			i+=3;
		}else{
			result+=text[i];
			i++;
		}
	}

	return result;
}

char* CBSingleFileTextSection::GetWritableBuffer(wxUint32* size)
{
	if(writableBuffer){
		*size=text.Length();
		return writableBuffer;
	} 

	writableBuffer=new char[text.Length()+1];
	strcpy(writableBuffer,(const char*)text.mb_str(wxConvISO8859_1));
	*size=text.Length();
	return writableBuffer;
}

void CBSingleFileTextSection::FreeBuffer()
{
	if(writableBuffer)
		delete[] writableBuffer;
	writableBuffer=NULL;
}

void CBSingleFileTextSection::SetText(wxString &text)
{
	wxString temp;
	
	for(size_t i=0;i<text.Length();i++){
		if(text[i]!='\n') //normal char
			temp+=text[i];
		else{ //carriage return
			temp+=wxT("<n>");
		}
	}

	this->text=temp;

	if(writableBuffer)
		delete[] writableBuffer;

	writableBuffer=NULL;
}

wxString CBSingleFileTextSection::GetText(size_t i)
{
	return wxEmptyString;
}
void CBSingleFileTextSection::SetText(size_t i, wxString &text)
{
	
}
size_t CBSingleFileTextSection::Size()
{
	return 1; //this type of file contains only one text section
}
