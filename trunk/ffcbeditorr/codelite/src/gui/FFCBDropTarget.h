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


#ifndef __FFCBDROP_TARGET__
#define __FFCBDROP_TARGET__

#include "FFCBFileDropHandler.h"
#include <wx/dnd.h>

class FFCBDropTarget : public wxFileDropTarget
{
public:
	FFCBDropTarget(FFCBFileDropHandler* handler);
	
	virtual bool OnDropFiles(wxCoord,wxCoord,const wxArrayString&);
	
protected:
	FFCBFileDropHandler* handler;
};

#endif