#ifndef __CB_TEXT_ARCHIVE__
#define __CB_TEXT_ARCHIVE__

#include "CBTextSection.h"
#include <wx/wx.h>
#include <wx/stream.h>

class CBTextArchive : public wxObject
{
public:

	//costruttori/distruttore
	CBTextArchive(wxString& fileName);
	CBTextArchive(const wxChar* fileName);
	CBTextArchive(wxInputStream& input);
	virtual ~CBTextArchive();

	//operatori
	CBTextSection* operator[](size_t i);
	
	//metodi
	size_t Size();
	int SaveTo(wxString& fileName); //salva su file i dati
	int SaveTo(const wxChar* fileName); //salva su file i dati
	int SaveTo(wxOutputStream& output); //salva su stream i dati

private:

	//metodi privati
	void Initialize(wxInputStream& input);
	//variabili
	size_t size;
	CBTextSection** sections; //array di textsection
};

#endif