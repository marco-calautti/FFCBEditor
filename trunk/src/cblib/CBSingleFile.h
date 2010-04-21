#ifndef __CB_SINGLE_FILE__
#define __CB_SINGLE_FILE__

#include <wx/object.h> //contiene la definizione di wxObject
#include <wx/string.h> //contiene la definizione di wxString
#include <wx/stream.h> //contiene la definizione sugli input stream su file
#include <wx/buffer.h>
#include <wx/wx.h>
#include "CBTextSection.h"

#define HEADER_SIZE 12 //numero di bytes dell'header

//classe concreta che modella il singolo file contente testo e altra roba
class CBSingleFile : public wxObject
{
public:

	//costruttori/distruttore
	CBSingleFile(wxString& fileName); //costruttore, carica da file
	CBSingleFile(const wxChar* fileName);
	CBSingleFile(wxInputStream& input); //costruttore, carica da stream
	virtual ~CBSingleFile(); //distruttore (chiamato quando si usa delete su un oggetto)

	//metodi pubblici della classe
	CBTextSection* GetTextSection(); //carica la sezione di testo del file
	int SaveTo(wxString& fileName); //salva su file i dati
	int SaveTo(const wxChar* fileName); //salva su file i dati
	int SaveTo(wxOutputStream& output); //salva su stream i dati

	
private:

	//variabili di istanza della classe
	CBTextSection* textSection;
	wxMemoryBuffer* unknownSection1;
	wxMemoryBuffer* unknownSection2;

	//metodi privati
	void Initialize(wxInputStream& input);
	wxUint32 GetPaddingSize(wxUint32 curSize);
};

#endif
