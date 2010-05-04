#include <wx/wfstream.h>
#include "CBFREBArchive.h"
#include <stdio.h>

CBFREBArchive::CBFREBArchive(wxString& filename)
{
	fileArchive=new wxFile(filename,wxFile::read_write);
	wxFileInputStream input(*fileArchive);
	Initialize(input);
}

CBFREBArchive::CBFREBArchive(const wxChar* filename)
{
	fileArchive=new wxFile(filename,wxFile::read_write);
	wxFileInputStream input(*fileArchive);
	Initialize(input);
}

CBFREBArchive::CBFREBArchive(wxFile* file)
{
	fileArchive=file;
	wxFileInputStream input(*file);
	Initialize(input);
}

CBFREBArchive::~CBFREBArchive()
{
	if(files)
		delete[] files;
	if(fileArchive)
		delete fileArchive;
}

void CBFREBArchive::Initialize(wxInputStream& input)
{
	containsEEVB=false;
	wxByte headerBuffer[FREB_HEADER_SIZE]; //buffer containing temporary header data
	wxByte fileRecordBuffer[FREB_FILE_RECORD_SIZE]; //buffer containing temporary file record data
	
	input.Read(headerBuffer,FREB_HEADER_SIZE); //read the header
	
	if(strcmp((const char*)headerBuffer,FREB_MAGIC)) //check valid FREB header
		return;
	
	//copy unknonwn (not useful data)
	for(size_t i=0;i<0x34;i++)
		header.unknown[i]=headerBuffer[i+4];
	
	//copy number of files inside archvie
	header.fileCount=wxINT32_SWAP_ON_LE(*((wxUint32*)&headerBuffer[0x38]));
	
	//copy unknown flags
	header.flags=wxINT32_SWAP_ON_LE(*((wxUint32*)&headerBuffer[0x38+4]));
	
	//allocate file record buffer
	files=new FREBFileRecord[header.fileCount];
	
	
	for(size_t i=0;i<header.fileCount;i++){
		//read current file record to buffer
		input.Read(fileRecordBuffer,FREB_FILE_RECORD_SIZE);
		
		//copy values (we cannot read directly the struct due of the endianess and compiler alignment strategies. We want to be cross-platform :P)
		files[i].flags1=wxINT32_SWAP_ON_LE(*((wxUint32*)(&fileRecordBuffer[0])));
		files[i].filesize=wxINT32_SWAP_ON_LE(*((wxUint32*)(&fileRecordBuffer[4])));
		files[i].fileoffset=wxINT32_SWAP_ON_LE(*((wxUint32*)(&fileRecordBuffer[8])));
		files[i].padding1=wxINT32_SWAP_ON_LE(*((wxUint32*)(&fileRecordBuffer[12])));
		files[i].filename=wxString((const char*)&fileRecordBuffer[16],wxConvISO8859_1,0x10);
		files[i].flags2=wxINT32_SWAP_ON_LE(*((wxUint32*)(&fileRecordBuffer[32])));
		files[i].padding2=wxINT32_SWAP_ON_LE(*((wxUint32*)(&fileRecordBuffer[36])));
		
		if(i<header.fileCount-1)
			wxASSERT_MSG(files[i].flags1!=FREB_EEVB_FLAGS,wxT("Supposed EEVB flags are not valid or EEVB is not always the last file!"));
	}
	
	if(files[header.fileCount-1].flags1==FREB_EEVB_FLAGS) //this FREB contains an EEVB file (not sure)
		containsEEVB=true;
}

size_t CBFREBArchive::GetFileCount()
{
	return header.fileCount;
}

wxInputStream* CBFREBArchive::GetFileInputStream(size_t fileIndex)
{
	return new FREBFileInputStream(fileArchive,files[fileIndex].fileoffset,files[fileIndex].filesize);
}

wxInputStream* CBFREBArchive::GetEEVBInputStream()
{
	if(containsEEVB)
		return GetFileInputStream(header.fileCount-1);
	return NULL;
}

FREBFileRecord& CBFREBArchive::GetFileRecord(size_t fileIndex)
{
	return files[fileIndex];
}

void CBFREBArchive::Close()
{
	fileArchive->Close();
}


bool CBFREBArchive::ContainsEEVB()
{
	return containsEEVB;
}


bool CBFREBArchive::WriteEVVBFile(wxInputStream& stream)
{
	fileArchive->Seek(files[header.fileCount-1].fileoffset);
	wxByte buffer[2048];
	while(!stream.Eof()){
		stream.Read(buffer,2048);
		size_t read=stream.LastRead();
		fileArchive->Write(buffer,read);
	}
	fileArchive->Flush();
	return true;
}



CBFREBArchive::FREBFileInputStream::FREBFileInputStream(wxFile* fileArchive,wxFileOffset seekStart,wxUint32 fileSize)
{
	this->seekStart=seekStart;
	this->fileSize=fileSize;
	stream=new wxFileInputStream(*fileArchive);
	stream->SeekI(seekStart);
}

CBFREBArchive::FREBFileInputStream::~FREBFileInputStream()
{
	if(stream)
		delete stream;
}

size_t CBFREBArchive::FREBFileInputStream::OnSysRead(void* buffer, size_t bufsize)
{
	wxUint32 remainingBytes=fileSize-(stream->TellI()-seekStart);
	if(remainingBytes>=bufsize){
		stream->Read(buffer,bufsize);
	}else{
		stream->Read(buffer,remainingBytes);
	}
	
	return stream->LastRead();
	
}