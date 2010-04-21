#ifndef __CB_FREB_ARCHIVE__
#define __CB_FREB_ARCHIVE__

#include <wx/stream.h>
#include <wx/wfstream.h>
#include <wx/wx.h>

#define FREB_MAGIC "FREB"
#define FREB_HEADER_SIZE 0x40
#define FREB_FILE_RECORD_SIZE 0x28

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
	FREBFileRecord& GetFileRecord(size_t fileIndex);
	void Close();
	
private:
	void Initialize(wxInputStream& input);
	
	//members 
	FREBHeader header;
	FREBFileRecord* files;
	wxFile* fileArchive;
	
	
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