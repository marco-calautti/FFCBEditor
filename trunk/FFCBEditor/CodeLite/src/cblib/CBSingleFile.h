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


//Copyright (C) 2010 Phoenix. 
//
//This program is free software: you can redistribute it and/or modify 
//it under the terms of the GNU General Public License as published by 
//the Free Software Foundation, version 2.0. 
//
//This program is distributed in the hope that it will be useful, 
//but WITHOUT ANY WARRANTY; without even the implied warranty of 
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
//GNU General Public License 2.0 for more details. 
//
//A copy of the GPL 2.0 should have been included with the program. 
//If not, see http://www.gnu.org/licenses/ 
//
//Official SVN repository and contact information can be found at 
//http://code.google.com/p/ffcbeditor/


#ifndef __CB_SINGLE_FILE__
#define __CB_SINGLE_FILE__

#include <wx/object.h> 
#include <wx/string.h> 
#include <wx/stream.h> 
#include <wx/buffer.h>
#include <wx/wx.h>
#include "CBTextSection.h"

#define HEADER_SIZE 12

class CBSingleFile : public wxObject
{
public:

	//constructors/destructor
	CBSingleFile(wxString& fileName); //constructor from file
	CBSingleFile(const wxChar* fileName);
	CBSingleFile(wxInputStream& input); //constructor from stream
	virtual ~CBSingleFile(); //destructor

	//public methods
	CBTextSection* GetTextSection(); //returns the unique text section this file contains
	int SaveTo(wxString& fileName); //stores changes to file
	int SaveTo(const wxChar* fileName); 
	int SaveTo(wxOutputStream& output); //stores changes to stream

	
private:

	//member variables
	CBTextSection* textSection;
	wxMemoryBuffer* unknownSection1;
	wxMemoryBuffer* unknownSection2;

	//private methods
	void Initialize(wxInputStream& input);
	wxUint32 GetPaddingSize(wxUint32 curSize);
};

#endif
