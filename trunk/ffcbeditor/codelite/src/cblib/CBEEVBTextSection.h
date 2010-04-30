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

#ifndef __CBEEVB_TEXT_SECTION__
#define __CBEEVB_TEXT_SECTION__

#include "CBMultiLanguageTextSection.h"
#include "CBTextArchiveSection.h"
#include <wx/stream.h>

class CBEEVBTextSection : public CBMultiLanguageTextSection
{
public:
	
	//constructor/destructor
	CBEEVBTextSection(wxByte* buffer,wxUint32 size,wxUint32 baseOffset);
	virtual ~CBEEVBTextSection();
	
	//inherited methods
	virtual wxString GetText();
	virtual void SetText(wxString& text);

	virtual wxString GetText(size_t i);
	virtual void SetText(size_t i,wxString& text);

	virtual char* GetWritableBuffer(wxUint32* len);
	virtual void FreeBuffer();
	virtual size_t Size();
	
	virtual void SetLanguage(LanguageType lng);
	virtual LanguageType GetLanguage();
	
private:
	static const char EEVB_KEY[];
	wxUint32 baseOffset;
	CBTextArchiveSection* delegateSection;
	char* writableBuffer;
	LanguageType lng;
};

#endif
