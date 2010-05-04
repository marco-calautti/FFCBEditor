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

#ifndef __FILE_MANAGER__
#define __FILE_MANAGER__

#include <wx/wx.h>
#include "../cblib/CBSingleFile.h"
#include "../cblib/CBTextArchive.h"
#include "../cblib/CBFREBArchive.h"
#include "../cblib/CBEEVBFile.h"
#include "common.h"

#include <map>

#define BACKUPS_BASE_PATH wxT("backups")
#define SINGLE_FILES_PATH wxT("backups/single/")
#define TEXT_ARCHIVES_PATH wxT("backups/archives/")
#define EEVB_FILES_PATH wxT("backups/eevbs/")

using namespace std;
class FileManager : public wxObject
{
	FileManager();
	
public:
	static FileManager* GetInstance();
	
	//if exists, returns the SingleFile object associated to "fileName".
	//returns NULL otherwise.
	CBSingleFile* GetSingleFile(wxString& fileName);
	
	//if exists, returns the TextArchiveFile object associated to "fileName".
	//returns NULL otherwise.
	CBTextArchive* GetTextArchive(wxString& fileName);
	
	//if exists, returns the EEVBFile object associated to "fileName".
	//returns NULL otherwise.
	//In details: fileName represent the FREB archive file containing this EEVB file.
	CBEEVBFile* GetEEVBFile(wxString& fileName);
	
	//if exists, returns the SingleFile object associated to "fileName".
	//If doesn't exists, creates a backup for this file and returns the SingleFile object associated.
	CBSingleFile* CreateSingleFileBackup(wxString& filePath);
	
	//if exists, returns the TextArchive object associated to "fileName".
	//If doesn't exists, creates a backup for this file and returns the TextArchive object associated.
	CBTextArchive* CreateTextArchiveBackup(wxString& filePath);
	
	//if exists, returns the EEVBFile object associated to "fileName".
	//If doesn't exists, creates a backup for this file and returns the EEVBFile object associated.
	//if this FREB archive doesn't contain an EEVB file, NULL will be returned.
	CBEEVBFile* CreateEEVBFileBackup(wxString& filePath);
	
	//Returns true if fileName was previously backed up, false otherwise.
	bool ExistsBackup(wxString& fileName);
	
	//if exists a backup file and is different from his original counterpart, changes will
	//be propacated to the original file (this method will return true).
	//If the file desn't exist or were not made changes, nothing happens (this method will
	//return false).
	bool StoreChangesToOriginal(wxString& filePath);
	
	static wxString GetBackupFilePath(wxString& fileName,FileType type);
	
private:
	static FileManager* instance;
	map<wxString,CBSingleFile*> singlesMap;
	map<wxString,CBTextArchive*> archivesMap;
	map<wxString,CBEEVBFile*> eevbsMap;
};
#endif

