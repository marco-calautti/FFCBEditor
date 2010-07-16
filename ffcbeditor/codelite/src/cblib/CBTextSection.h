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


#ifndef __CB_TEXT_SECTION__
#define __CB_TEXT_SECTION__

#include <wx/object.h> 
#include <wx/string.h> 

//abstract classc
//defines methods to manage a text section (pointers+text)
//Implementing SetText and GetText is mandatory to convert between wii binary data and user-readable test

class CBTextSection : public wxObject
{
public:

	//pure virtual methods (
	virtual wxString GetText() = 0; //returns the first text-block in a user-readable format (use GetText(size_t i) for others text block, if any)
	virtual void SetText(wxString& text) = 0; //receives a user-readable text block converting it to wii binary data ready to be written to file/stream
	
	virtual wxString GetText(size_t i) = 0; //rreturns the user-readable text block at index i
	virtual void SetText(size_t i,wxString& text) = 0; //receives a user-readable text block converting it to wii binary data at position i ready to be written to file/stream
	
	virtual char* GetWritableBuffer(wxUint32* size)=0; //returns the buffer containing all text blocks in binary form to be written to file/stream
	virtual void FreeBuffer()=0; //deletes the writable buffer							 
	virtual size_t Size()=0; //returns the number of text block in this text section
	virtual ~CBTextSection(){}
};

#endif
