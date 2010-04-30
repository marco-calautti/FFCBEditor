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

#ifndef __CBEEVBFILE__
#define __CBEEVBFILE__

#include <wx/stream.h>
#include <wx/wx.h>
#include <wx/file.h>
#include "CBMultiLanguageTextSection.h"


#define EEVB_MAGIC "EEVB"
#define EEVB_HEADER_SIZE 0x7
#define EEVB_POINTERS_START 0x20 //0x14
#define EEVB_NUM_POINTERS	1

typedef struct{
	wxUint16 unknown;
	wxByte dummy;
} EEVBHeader;

class CBEEVBFile : public wxObject
{
public:
	
	//constructors/destructor
	CBEEVBFile(wxString& fileName);
	CBEEVBFile(const wxChar* fileName);
	CBEEVBFile(wxFile* file);
	virtual ~CBEEVBFile();
	
	//operators
	CBMultiLanguageTextSection* operator[](size_t i);
	
	//methods
	size_t Size();
	void SetLanguage(LanguageType lng);
	bool IsDummy();
	void Close();
	
private:

	//private methods
	void Initialize(wxInputStream& stream);
	
	//members
	wxFile* file;
	CBMultiLanguageTextSection** sections;
	EEVBHeader header;
};


#endif

