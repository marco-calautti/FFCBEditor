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


#ifndef __COMMON__
#define __COMMON__

#include <wx/wx.h>
#include <wx/file.h>
#include <wx/filename.h>
#include <wx/dir.h>
#include "../cblib/CBFREBArchive.h"
#include "../cblib/CBEEVBFile.h"


#define __FFCB_VERSION__ wxT("1.0")
#define __FFCB_LICENSE__ _("This program is free software: you can redistribute it\n" \
							"and/or modify it under the terms of the GNU General\n" \
							"Public License as published by the Free Software Foundation,\n" \
							"version 2.0.")
#define __FFCB_NAME__ wxT("Final Fantasy Crystal Bearers Text Editor")
#define __FFCB_WEBSITE__ wxT("http://code.google.com/p/ffcbeditor/")
#define __FFCB_COPYRIGHT__ wxT("(C) 2010 Phoenix <phoenix_87_c@hotmail.com>")

#define HEADERS_PATH wxT("headers")

#define HEADER_BUFFER_SIZE 100 //max 100 bytes

static wxByte headerBuffer[HEADER_BUFFER_SIZE]; 
static wxByte curHeaderBuffer[HEADER_BUFFER_SIZE]; 

enum FileType{
	SINGLE_FILE=0,
	TEXT_ARCHIVE,
	FREB_ARCHIVE,
	EEVB_FILE,
	NO_FILE
};


static bool NotContainsText(wxString& fileName)
{
	wxFile temp(fileName);
	size_t read=temp.Read(headerBuffer,HEADER_BUFFER_SIZE);
	temp.Close();
	if(read==0) return true; //file is empty

	wxArrayString names;
	wxDir::GetAllFiles(HEADERS_PATH,&names,wxT("*.hex"),wxDIR_FILES);

	for(size_t i=0;i<names.GetCount();i++){
		wxFile file(names[i]);
		//each header is max 100 bytes in size
		size_t size=file.Read(curHeaderBuffer,HEADER_BUFFER_SIZE);

		if(read>=size){ //we check only if the file is bigger or equal in size
			if(memcmp(curHeaderBuffer,headerBuffer,size)==0)
				return true;
		}
		file.Close();
	}

	//checking if it's a FREB archive containing text
	CBFREBArchive archive(fileName);
	if(!archive.IsOk())
		return false; //this can be another type of file
	
	if(!archive.ContainsEEVB())
		return true;
	
	wxString tmpName=wxFileName::CreateTempFileName(wxT("eevb"));
	wxFileOutputStream outStream(tmpName);
	wxInputStream* stream=archive.GetEEVBInputStream();
	outStream.Write(*stream);
	outStream.Close();
	delete stream;
	archive.Close();
	
	CBEEVBFile eevb(tmpName);
	bool isDummy=eevb.IsDummy();
	bool containsText=eevb.ContainsText();
	eevb.Close();
	wxRemoveFile(tmpName);
	
	return isDummy||!containsText;
}

#endif
