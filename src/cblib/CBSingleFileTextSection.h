#ifndef __CB_SINGLE_FILE_TEXT_SECTION__
#define __CB_SINGLE_FILE_TEXT_SECTION__

#include "CBTextSection.h"

//classe concreta che si occupa del mapping del testo nei file singoli
//questa sezione di testo contiene solo un blocco testuale, quindi si preferisce accedervi con il metodo GetText
class CBSingleFileTextSection : public CBTextSection
{
public:
	//costruttori/distruttore
	CBSingleFileTextSection(wxByte* buffer); //carica il testo da buffer di byte
	virtual ~CBSingleFileTextSection(); //distruttore

	//metodi derivati da CBTextSection
	virtual wxString GetText();
	virtual void SetText(wxString& text);

	virtual wxString GetText(size_t i);
	virtual void SetText(size_t i,wxString& text);

	virtual char* GetWritableBuffer(wxUint32* size);
	virtual void FreeBuffer();
	virtual size_t Size();

private:
	wxString text;
	char* writableBuffer;

};

#endif