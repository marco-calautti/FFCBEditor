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

#ifndef __FFCB_TEXT_ARCHIVE_PANEL__
#define __FFCB_TEXT_ARCHIVE_PANEL__

#include "FFCBTextArchivePanelBase.h"

class FFCBTextArchivePanel : public FFCBTextArchivePanelBase
{
public:
	/** Constructor */
	FFCBTextArchivePanel( wxWindow* parent );
	
	void SetEditInfo(CBTextArchive* f,size_t i,wxString fn);
	
private:
	CBTextArchive* file;
	
	void SaveFile(wxString& fullName);
	CBTextSection* GetTextSection(size_t idx);
};
#endif
