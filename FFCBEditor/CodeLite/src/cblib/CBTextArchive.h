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


#ifndef __CB_TEXT_ARCHIVE__
#define __CB_TEXT_ARCHIVE__

#include "CBTextSection.h"
#include <wx/wx.h>
#include <wx/stream.h>

class CBTextArchive : public wxObject
{
public:

	//constructors/destructor
	CBTextArchive(wxString& fileName);
	CBTextArchive(const wxChar* fileName);
	CBTextArchive(wxInputStream& input);
	virtual ~CBTextArchive();

	//operators
	CBTextSection* operator[](size_t i);
	
	//methods
	size_t Size();
	int SaveTo(wxString& fileName); //stores chages to file
	int SaveTo(const wxChar* fileName); 
	int SaveTo(wxOutputStream& output); //stores changes to stream

private:

	//private methods
	void Initialize(wxInputStream& input);
	
	//member variables
	size_t size;
	CBTextSection** sections; //text section array
};

#endif