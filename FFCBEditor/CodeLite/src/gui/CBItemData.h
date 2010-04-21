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


#ifndef __CB_ITEM_DATA__
#define __CB_ITEM_DATA__

#include <wx/treectrl.h>

#define CB_SINGLE_FILE 1
#define CB_TEXT_ARCHIVE 2
#define CB_TEXT_SECTION 3

class CBItemData : public wxTreeItemData
{
public:

	CBItemData();
	virtual ~CBItemData();

	void SetType(int type);
	int GetType();

	void* GetData();
	void SetData(void* data);

	size_t GetSectionIndex();
	void SetSectionIndex(size_t sectionIdx);

	wxString GetString();
	void SetString(wxString str);

private:
	int type;
	void* data;
	size_t sectionIdx;
	wxString str;
};

#endif