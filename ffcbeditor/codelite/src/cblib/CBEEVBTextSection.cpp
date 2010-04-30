#include "CBEEVBTextSection.h"
#include <stdio.h>

const char CBEEVBTextSection::EEVB_KEY[]={0x4A,0xA5,0x52,0x29,0x94,0xCA,0xE5,0x72,0x39,0x1C,0x8E,0xC7,
										  0x63,0x31,0x98,0x4C,0x26,0x93,0x49,0xA4,0x52,0xA9,0x54,0x2A,
										  0x15,0x0A,0x05,0x02,0x01};
										  
										  
CBEEVBTextSection::CBEEVBTextSection(wxByte* buffer,wxUint32 size,wxUint32 baseOffset)
{
	writableBuffer=NULL;
	lng=ALL_LANGUAGES;
	if(((wxUint32*)buffer)[0]==0){
		delegateSection=NULL;
		return;
	}
	
	wxByte* newBuffer=new wxByte[size];
	memcpy(newBuffer,buffer,size);
	
	wxUint32 totPointers=(wxINT32_SWAP_ON_LE(*((wxUint32*)&newBuffer[0]))-baseOffset)/4;
	wxUint32* u32buffer=(wxUint32*)newBuffer;
	
	//relativizing pointers
	for(size_t i=0;i<totPointers;i++){
		u32buffer[i]=wxINT32_SWAP_ON_LE(wxINT32_SWAP_ON_LE(u32buffer[i])-baseOffset);
	}
	
	char* textBuffer=(char*)&newBuffer[totPointers*4];
	
	//decrypting text data
	for(size_t i=0;i<size-totPointers*4;i++){
		textBuffer[i]^=EEVB_KEY[i%29];
	}
	
	//done, creating text section
	delegateSection=new CBTextArchiveSection(newBuffer,totPointers);
	
	delete[] newBuffer;
}

CBEEVBTextSection::~CBEEVBTextSection()
{
	if(delegateSection)
		delete delegateSection;
}

wxString CBEEVBTextSection::GetText()
{
	//caller must check size first
	if(delegateSection){
		return GetText(0);
	}
	return wxEmptyString;
}

void CBEEVBTextSection::SetText(wxString& text)
{
	if(delegateSection){
		SetText(0,text);
	}
	//else do nothing
}
wxString CBEEVBTextSection::GetText(size_t i)
{
	if(delegateSection){
		if(lng!=ALL_LANGUAGES)
			return delegateSection->GetText(i*SUPPORTED_LANGUAGES+lng);
		else
			return delegateSection->GetText(i);
	}
}

void CBEEVBTextSection::SetText(size_t i,wxString& text)
{
	if(delegateSection){
		if(lng!=ALL_LANGUAGES)
			delegateSection->SetText(i*SUPPORTED_LANGUAGES+lng,text);
		else
			delegateSection->SetText(i,text);
	}
	//else do nothing
}

char* CBEEVBTextSection::GetWritableBuffer(wxUint32* size)
{
	if(!delegateSection){
		return NULL;
	}
	
	if(writableBuffer)
		return delegateSection->GetWritableBuffer(size);
	
	char* buffer=delegateSection->GetWritableBuffer(size);
	wxUint32* u32buffer=(wxUint32*)buffer;
	
	//absolutizing pointers
	for(size_t i=0;i<delegateSection->Size();i++){
		u32buffer[i]=wxINT32_SWAP_ON_LE(wxINT32_SWAP_ON_LE(u32buffer[i])+baseOffset);
	}
	
	char* textBuffer=&buffer[delegateSection->Size()*4];
	
	//crypting text data
	for(size_t i=0;i<*size-delegateSection->Size()*4;i++){
		textBuffer[i]^=EEVB_KEY[i%29];
	}
	
	writableBuffer=buffer;
	return writableBuffer;
}

void CBEEVBTextSection::FreeBuffer()
{
	if(delegateSection){
		delegateSection->FreeBuffer();
		writableBuffer=NULL;
	}
}

size_t CBEEVBTextSection::Size()
{
	if(delegateSection){
		if(lng!=ALL_LANGUAGES)
			return delegateSection->Size()/SUPPORTED_LANGUAGES;
		else
			return delegateSection->Size();
	}
	return 0;
}

void CBEEVBTextSection::SetLanguage(LanguageType l)
{
	lng=l;
}

LanguageType CBEEVBTextSection::GetLanguage()
{
	return lng;
}
