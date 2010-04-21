#ifndef __CB_TEXT_ARCHIVE_SECTION__
#define __CB_TEXT_ARCHIVE_SECTION__

#include <wx/wx.h>
#include "CBTextSection.h"

class CBTextArchiveSection : public CBTextSection
{
public:

	//costruttori/distruttore
	CBTextArchiveSection(wxByte* buffer,wxUint32 num);
	virtual ~CBTextArchiveSection();

	//metodi ereditati
	virtual wxString GetText();
	virtual void SetText(wxString& text);

	virtual wxString GetText(size_t i);
	virtual void SetText(size_t i,wxString& text);

	virtual char* GetWritableBuffer(wxUint32* len);
	virtual void FreeBuffer();
	virtual size_t Size();

private:

	//metodi di utilità
	wxString Parse(size_t i);
	char* GetBuf(size_t i,wxUint32* size,bool* unicode);
	wxString* texts;
	char* writableBuffer;
	size_t size;

};
#endif