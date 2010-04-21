#ifndef __CB_TEXT_SECTION__
#define __CB_TEXT_SECTION__

#include <wx/object.h> //contiene la definizione di wxObject
#include <wx/string.h> //contiene la definizione di wxString

//classe astratta (nessuna implementazione) che verrà estesa dalle sottoclassi
//serve a definire i metodi necessari alla gestione di una sezione di testo
//basterà ridefinire i metodi SetText e GetText, che si occuperanno del passaggio di formato
//da file wii a script per l'editing e viceversa
class CBTextSection : public wxObject
{
public:

	//metodi virtuali "puri" (=0 --> nessuna implementazione possibile, solo ereditando)
	virtual wxString GetText() = 0; //restituisce il primo testo in un formato user-editable (per accedere a più testi, usare la funzione corrispondente)
	virtual void SetText(wxString& text) = 0; //imposta il primo testo user-editable, convertendolo in formato wii.
	
	virtual wxString GetText(size_t i) = 0; //restituisce il testo in posizione i in un formato user-editable
	virtual void SetText(size_t i,wxString& text) = 0; //imposta il testo formato user-editable in posizione i ,convertendolo in formato wii.
	
	virtual char* GetWritableBuffer(wxUint32* size)=0; //restituisce l'array di char da scrivere in uscita (es. file)
	virtual void FreeBuffer()=0; //libera dalla memoria il buffer attuale								 
	virtual size_t Size()=0; //restituisce il numero di blocchi di testo contenuti
};

#endif
