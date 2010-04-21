#ifndef __COMMON__
#define __COMMON__

#include <wx/wx.h>
#include <wx/file.h>
#include <wx/dir.h>

#define HEADERS_PATH wxT("headers")

#define HEADER_BUFFER_SIZE 100 //max 100 bytes

static wxByte headerBuffer[HEADER_BUFFER_SIZE]; 
static wxByte curHeaderBuffer[HEADER_BUFFER_SIZE]; 

enum FileType{
	SINGLE_FILE,
	TEXT_ARCHIVE,
	NO_FILE
};


static bool NotContainsText(wxString& fileName)
{
	wxFile temp(fileName);
	size_t read=temp.Read(headerBuffer,HEADER_BUFFER_SIZE);
	temp.Close();
	if(read==0) return true; //il file è vuoto

	wxArrayString names;
	wxDir::GetAllFiles(HEADERS_PATH,&names,wxT("*.hex"),wxDIR_FILES);

	for(size_t i=0;i<names.GetCount();i++){
		wxFile file(names[i]);
		//assumo che gli header non siano superiori a 100 bytes
		size_t size=file.Read(curHeaderBuffer,HEADER_BUFFER_SIZE);

		if(read>=size){ //se tutto il file è più piccolo dell'header corrente, è inutile confrontare
			if(memcmp(curHeaderBuffer,headerBuffer,size)==0)
				return true;
		}
		file.Close();
	}

	return false;
}

#endif