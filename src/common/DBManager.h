#ifndef __DB_MANAGER__
#define __DB_MANAGER__

#include <wx/wx.h>
#include <wx/xml/xml.h>
#include "common.h"

#define DB_FILE_NAME wxT("filesdb.xml")
#define STR_SINGLE_FILE wxT("SINGLE_FILE")
#define STR_TEXT_ARCHIVE wxT("TEXT_ARCHIVE")

#define ALREADY_EXISTS -1
#define IO_ERROR -2
#define SUCCESS 0

class DBManager : public wxObject
{
private:
	static DBManager* instance;
	wxXmlDocument doc;
	//costruttore privato per evitare che possa essere creata un'istanza
	DBManager();

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