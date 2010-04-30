#include <wx/wfstream.h>
#include "CBEEVBFile.h"
#include "CBEEVBTextSection.h"
#include <stdio.h>

CBEEVBFile::CBEEVBFile(wxString& fileName)
{
	file=new wxFile(fileName);
	wxFileInputStream stream(*file);
	Initialize(stream);
}


CBEEVBFile::CBEEVBFile(const wxChar* fileName)
{
	file=new wxFile(fileName);
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
	
	if(strcmp((const char*)headerBuffer,EEVB_MAGIC))
		return; //not an EEVB file
	header.unknown=wxINT16_SWAP_ON_LE(*((wxUint16*)&headerBuffer[4]));
	header.dummy=headerBuffer[6];
	
	//positioning to read text blocks pointers
	stream.SeekI(EEVB_POINTERS_START);
	
	//text blocks pointers array
	wxUint32 pointers[EEVB_NUM_POINTERS+1]; //+1 because we need the last pointer to calculate last buffer size
	
	//reading text blocks pointers
	stream.Read(pointers,(EEVB_NUM_POINTERS+1)*4);
	
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
		delete[] buffer;
	}
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
}

bool CBEEVBFile::IsDummy()
{
	return header.dummy==0;
}

void CBEEVBFile::Close()
{
	file->Close();
}