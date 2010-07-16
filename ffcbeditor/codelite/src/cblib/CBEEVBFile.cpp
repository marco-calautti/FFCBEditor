#include <wx/wfstream.h>
#include "CBEEVBFile.h"
#include "CBEEVBTextSection.h"
#include <stdio.h>

CBEEVBFile::CBEEVBFile(wxString& fileName)
{
	file=new wxFile(fileName,wxFile::read_write);
	wxFileInputStream stream(*file);
	Initialize(stream);
}


CBEEVBFile::CBEEVBFile(const wxChar* fileName)
{
	file=new wxFile(fileName,wxFile::read_write);
	wxFileInputStream stream(*file);
	Initialize(stream);
}

CBEEVBFile::CBEEVBFile(wxFile* file)
{
	this->file=file;
	wxFileInputStream stream(*file);
	Initialize(stream);
}

void CBEEVBFile::Initialize(wxInputStream& stream)
{
	wxByte headerBuffer[EEVB_HEADER_SIZE];
	stream.Read(headerBuffer,EEVB_HEADER_SIZE);
	isOk=true;
	containsText=false;
	sections=NULL;
	if(strcmp((const char*)headerBuffer,EEVB_MAGIC)){
		isOk=false;
		return;
	}
	
	header.unknown=wxINT16_SWAP_ON_LE(*((wxUint16*)&headerBuffer[4]));
	header.dummy=headerBuffer[6];
	
	if(header.dummy==0) return;
	
	
	//positioning to read text blocks pointers
	stream.SeekI(EEVB_POINTERS_START);
	
	//text blocks pointers array
	wxUint32 pointers[EEVB_NUM_POINTERS+1]; //+1 because we need the last pointer to calculate last buffer size
	
	//reading text blocks pointers
	stream.Read(pointers,(EEVB_NUM_POINTERS+1)*4);
	
	if(pointers[0]==0)
		return;
		
	//swapping for portability
	for(size_t i=0;i<EEVB_NUM_POINTERS+1;i++)
		pointers[i]=wxINT32_SWAP_ON_LE(pointers[i]);
	
	//allocating text sections array
	sections=new CBMultiLanguageTextSection*[EEVB_NUM_POINTERS];
	
	//ready to create TextSections
	for(size_t i=0;i<EEVB_NUM_POINTERS;i++){
		stream.SeekI(pointers[i]); //seeking to read text section
		
		wxASSERT_MSG(pointers[i+1]>=pointers[i],wxT("pointers must be consecutive!"));
		wxUint32 size=pointers[i+1]-pointers[i];
		
		wxByte* buffer=new wxByte[size];
		stream.Read(buffer,size);
		sections[i]=new CBEEVBTextSection(buffer,size,pointers[i]); //create text section
		if(sections[i]->Size()>0)
			containsText=true;
		delete[] buffer;
	}
	curLang=ALL_LANGUAGES;
}

CBEEVBFile::~CBEEVBFile()
{
	if(sections){
		for(size_t i=0;i<EEVB_NUM_POINTERS;i++)
			delete sections[i];
		delete[] sections;
	}
	if(file)
		delete file;
}

CBMultiLanguageTextSection* CBEEVBFile::operator [](size_t i)
{
	return sections[i];
}

size_t CBEEVBFile::Size()
{
	return EEVB_NUM_POINTERS;
}

void CBEEVBFile::SetLanguage(LanguageType lng)
{
	for(size_t i=0;i<EEVB_NUM_POINTERS;i++)
		sections[i]->SetLanguage(lng);
	curLang=lng;
}

bool CBEEVBFile::IsDummy()
{
	return header.dummy==0;
}

void CBEEVBFile::Close()
{
	file->Close();
}

int CBEEVBFile::Save()
{
	//we should save EEVB_NUM_POINTERS text sections. But as for now, we know we
	//have only one text section. Just to keep saving simple:
	LanguageType oldLang=curLang;
	SetLanguage(ALL_LANGUAGES);
	
	file->Seek(EEVB_POINTERS_START);
	wxUint32 sectionStart;
	wxUint32 lastPointer;
	file->Read(&sectionStart,4);
	sectionStart=wxINT32_SWAP_ON_LE(sectionStart);
	file->Read(&lastPointer,4);
	lastPointer=wxINT32_SWAP_ON_LE(lastPointer);
	
	wxUint32 allowedSize=lastPointer-sectionStart;
	
	file->Seek(sectionStart);
	
	wxUint32 size;
	char* buffer=sections[0]->GetWritableBuffer(&size);
	
	if(size>allowedSize){
		sections[0]->FreeBuffer();
		SetLanguage(oldLang);
		return EEVB_SECTIONS_TOO_BIG;
	}
		
	file->Write(buffer,size);
	file->Flush();
	sections[0]->FreeBuffer();

	SetLanguage(oldLang);
	
	return EEVB_SAVE_SUCCESSFUL;
}

int CBEEVBFile::TrimAndSave(LanguageType lang)
{
	if(lang==ALL_LANGUAGES)
		return Save();
		
	wxString empty;
	CBMultiLanguageTextSection* section=sections[0];
	LanguageType oldLang=curLang;
	if(lang!=JAPANESE_LANGUAGE){
		section->SetLanguage(JAPANESE_LANGUAGE);
		for(size_t i=0;i<section->Size();i++)
			section->SetText(i,empty);
	}
	
	if(lang!=ENGLISH_LANGUAGE){
		section->SetLanguage(ENGLISH_LANGUAGE);
		for(size_t i=0;i<section->Size();i++)
			section->SetText(i,empty);
	}
	
	if(lang!=GERMAN_LANGUAGE){
		section->SetLanguage(GERMAN_LANGUAGE);
		for(size_t i=0;i<section->Size();i++)
			section->SetText(i,empty);
	}
	
	if(lang!=FRENCH_LANGUAGE){
		section->SetLanguage(FRENCH_LANGUAGE);
		for(size_t i=0;i<section->Size();i++)
			section->SetText(i,empty);
	}
	
	if(lang!=SPANISH_LANGUAGE){
		section->SetLanguage(SPANISH_LANGUAGE);
		for(size_t i=0;i<section->Size();i++)
			section->SetText(i,empty);
	}
	section->SetLanguage(oldLang);
	
	return Save();
}

bool CBEEVBFile::ContainsText()
{
	return containsText;
}

bool CBEEVBFile::IsOk()
{
	return isOk;
}
