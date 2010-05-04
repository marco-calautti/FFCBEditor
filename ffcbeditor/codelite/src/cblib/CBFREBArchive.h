//Copyright (C) 2010 Phoenix. 

//This program is free software: you can redistribute it and/or modify 
//it under the terms of the GNU General Public License as published by 
//the Free Software Foundation, version 2.0. 

//This program is distributed in the hope that it will be useful, 
//but WITHOUT ANY WARRANTY; without even the implied warranty of 
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
//GNU General Public License 2.0 for more details. 

//A copy of the GPL 2.0 should have been included with the program. 
//If not, see http://www.gnu.org/licenses/ 

//Official SVN repository and contact information can be found at 
//http://code.google.com/p/ffcbeditor/


//FREB Archive class. If a FREB archive contains an EEVB file, this file is (should be) the last file.
#ifndef __CB_FREB_ARCHIVE__
#define __CB_FREB_ARCHIVE__

#include <wx/stream.h>
#include <wx/wfstream.h>
#include <wx/wx.h>

#define FREB_MAGIC "FREB"
#define FREB_HEADER_SIZE 0x40
#define FREB_FILE_RECORD_SIZE 0x28
#define FREB_EEVB_FLAGS	0x00060000

typedef struct{
	wxByte unknown[0x34];
	wxUint32 fileCount;
	wxUint32 flags;
}FREBHeader;

typedef struct{
	wxUint32 flags1;
	wxUint32 filesize;
	wxUint32 fileoffset;
	wxUint32 padding1;
	wxString filename;
	wxUint32 flags2;
	wxUint32 padding2;
}FREBFileRecord;

class CBFREBArchive : public wxObject
{
public:

	CBFREBArchive(wxString& filename);
	CBFREBArchive(const wxChar* fileName);
	CBFREBArchive(wxFile* file);
	virtual ~CBFREBArchive();
	
	size_t GetFileCount();
	wxInputStream* GetFileInputStream(size_t fileIndex);
	wxInputStream* GetEEVBInputStream();
	
	bool WriteEVVBFile(wxInputStream& stream);
	FREBFileRecord& GetFileRecord(size_t fileIndex);
	bool ContainsEEVB();
	void Close();
	
private:
	void Initialize(wxInputStream& input);
	
	//members 
	FREBHeader header;
	FREBFileRecord* files;
	wxFile* fileArchive;
	bool containsEEVB;
	
	//inner classes
private:

	class FREBFileInputStream : public wxInputStream
	{
		public:
			FREBFileInputStream(wxFile* fileArchive,wxFileOffset seekStart,wxUint32 fileSize);
			virtual ~FREBFileInputStream();
		protected:
			size_t OnSysRead(void* buffer, size_t bufsize); 

		private:
			wxFileOffset seekStart;
			wxUint32 fileSize;
			wxFileInputStream* stream; //delegation
	};
	
};


#endif