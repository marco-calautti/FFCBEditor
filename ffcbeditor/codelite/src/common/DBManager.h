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


#ifndef __DB_MANAGER__
#define __DB_MANAGER__

#include <wx/wx.h>
#include <wx/xml/xml.h>
#include "common.h"

#define DB_FILE_NAME wxT("filesdb.xml")
#define STR_SINGLE_FILE wxT("SINGLE_FILE")
#define STR_TEXT_ARCHIVE wxT("TEXT_ARCHIVE")
#define STR_FREB_ARCHIVE wxT("FREB_ARCHIVE")

#define ALREADY_EXISTS -1
#define IO_ERROR -2
#define SUCCESS 0

class DBManager : public wxObject
{
private:
	static DBManager* instance;
	wxXmlDocument doc;
	//private constructor (singleton)
	DBManager();
	DBManager(const DBManager&){}
	DBManager& operator=(const DBManager&)
	{
		return *instance;
	}

public:
	

	//pattern singleton
	static DBManager* GetInstance();

	bool Contains(wxString& fileName);
	FileType GetFileType(wxString& fileName);
	wxString GetFileDescription(wxString& fileName);
	int SetFileDescription(wxString& fileName,wxString& description);
	int AddFile(wxString& fileName,FileType type,wxString description=wxString());
	int GetFileNames(wxArrayString* arrStr);
};

#endif
