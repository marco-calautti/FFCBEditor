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


#ifndef __CB_SINGLE_FILE_TEXT_SECTION__
#define __CB_SINGLE_FILE_TEXT_SECTION__

#include "CBTextSection.h"


//This text section contains only one text block. Access to Text with GetText method is preferred
class CBSingleFileTextSection : public CBTextSection
{
public:
	//constructors/destructor
	CBSingleFileTextSection(wxByte* buffer); //constructs text section from a buffer of bytes
	virtual ~CBSingleFileTextSection(); //destructor

	//derived CBTextSection methods
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
