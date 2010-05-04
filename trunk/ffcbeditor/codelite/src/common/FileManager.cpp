#include <wx/wfstream.h>
#include <wx/filename.h>
#include "FileManager.h"
#include <wx/dir.h>

FileManager* FileManager::instance=NULL;

FileManager::FileManager()
{
	
	/*wxArrayString names;
	
	//loading SingleFiles backups
	wxDir::GetAllFiles(SINGLE_FILES_PATH,&names,wxEmptyString,wxDIR_FILES);
	for(size_t i=0;i<names.Count();i++)
		CreateSingleFileBackup(names[i]);
	
	names.Clear();
	//loading TextArchive backups
	wxDir::GetAllFiles(TEXT_ARCHIVES_PATH,&names,wxEmptyString,wxDIR_FILES);
	for(size_t i=0;i<names.Count();i++)
		CreateTextArchiveBackup(names[i]);
		
	names.Clear();
	//loading EEVBFiles backups
	wxDir::GetAllFiles(EEVB_FILES_PATH,&names,wxEmptyString,wxDIR_FILES);
	for(size_t i=0;i<names.Count();i++)
		CreateEEVBFileBackup(names[i]);
	*/
}

FileManager* FileManager::GetInstance()
{
	if(!instance)
		instance=new FileManager();
	return instance;
}

CBSingleFile* FileManager::GetSingleFile(wxString& fileName)
{
	map<wxString,CBSingleFile*>::iterator it=singlesMap.find(fileName);
	if(it!=singlesMap.end())
		return it->second;
	
	//check if backup file exists
	wxString backupPath=GetBackupFilePath(fileName,SINGLE_FILE);
	if(!wxFile::Exists(backupPath)){
		return NULL;
	}
	CBSingleFile* file=new CBSingleFile(backupPath);
	singlesMap[fileName]=file;
	return file;
}

CBSingleFile* FileManager::CreateSingleFileBackup(wxString& filePath)
{
	wxFileName fn(filePath);
	wxString fileName=fn.GetFullName();
	CBSingleFile* file=GetSingleFile(fileName);
	if(file)
		return file;
	
	//we must create the backup file
	wxString backupPath=GetBackupFilePath(fileName,SINGLE_FILE);
	wxCopyFile(filePath,backupPath);
	return GetSingleFile(fileName);
}

CBTextArchive* FileManager::GetTextArchive(wxString& fileName)
{
	map<wxString,CBTextArchive*>::iterator it=archivesMap.find(fileName);
	if(it!=archivesMap.end())
		return it->second;
	
	//check if backup file exists
	wxString backupPath=GetBackupFilePath(fileName,TEXT_ARCHIVE);
	if(!wxFile::Exists(backupPath)){
		return NULL;
	}
	CBTextArchive* file=new CBTextArchive(backupPath);
	archivesMap[fileName]=file;
	return file;
}

CBTextArchive* FileManager::CreateTextArchiveBackup(wxString& filePath)
{
	wxFileName fn(filePath);
	wxString fileName=fn.GetFullName();
	CBTextArchive* file=GetTextArchive(fileName);
	if(file)
		return file;
	
	//we must create the backup file
	wxString backupPath=GetBackupFilePath(fileName,TEXT_ARCHIVE);
	wxCopyFile(filePath,backupPath);
	return GetTextArchive(fileName);
}

CBEEVBFile* FileManager::GetEEVBFile(wxString& fileName)
{
	map<wxString,CBEEVBFile*>::iterator it=eevbsMap.find(fileName);
	if(it!=eevbsMap.end())
		return it->second;
	
	//check if backup file exists
	wxString backupPath=GetBackupFilePath(fileName,EEVB_FILE);
	if(!wxFile::Exists(backupPath)){
		return NULL;
	}
	CBEEVBFile* file=new CBEEVBFile(backupPath);
	eevbsMap[fileName]=file;
	return file;
}

CBEEVBFile* FileManager::CreateEEVBFileBackup(wxString& filePath)
{
	
	wxFileName fn(filePath);
	wxString fileName=fn.GetFullName();
	CBEEVBFile* file=GetEEVBFile(fileName);
	if(file)
		return file;
	
	//we must create the backup file
	wxString backupPath=GetBackupFilePath(fileName,EEVB_FILE);
	CBFREBArchive archive(filePath);
	if(!archive.ContainsEEVB()) return NULL;
	wxFileOutputStream output(backupPath);
	output.Write(*archive.GetEEVBInputStream());
	output.Close();
	archive.Close();
	
	return GetEEVBFile(fileName);
}

bool FileManager::ExistsBackup(wxString& fileName)
{
	return GetSingleFile(fileName)||GetTextArchive(fileName)||GetEEVBFile(fileName);
}

bool FileManager::StoreChangesToOriginal(wxString& filePath)
{
	//TO-DO: Implement this
	wxFileName fn(filePath);
	wxString fullName=fn.GetFullName();
	wxString backupPath;
	
	backupPath=GetBackupFilePath(fullName,SINGLE_FILE);
	if(wxFile::Exists(backupPath)){
		//just copy backup to original
		wxCopyFile(backupPath,filePath);
		return true;
	}
		
	backupPath=GetBackupFilePath(fullName,TEXT_ARCHIVE);
	if(wxFile::Exists(backupPath)){
		//just copy backup to original
		wxCopyFile(backupPath,filePath);
		return true;
	}
		
	backupPath=GetBackupFilePath(fullName,EEVB_FILE);
	if(wxFile::Exists(backupPath)){
		wxFileInputStream input(backupPath);
		CBFREBArchive freb(filePath);
		freb.WriteEVVBFile(input);
		freb.Close();
	}
	
	return false;
}

wxString FileManager::GetBackupFilePath(wxString& fileName,FileType type)
{
	wxString res;
	switch(type){
		case SINGLE_FILE:
			res=SINGLE_FILES_PATH+fileName;
		break;
		case TEXT_ARCHIVE:
			res=TEXT_ARCHIVES_PATH+fileName;
		break;
		case EEVB_FILE:
			res=EEVB_FILES_PATH+fileName;
		break;
	}
	
	return res;
}