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


#ifndef __TAG_MANAGER__
#define __TAG_MANAGER__

#include <wx/xml/xml.h>
#include <wx/wx.h>

#define TAGS_FILE_NAME wxT("tags.xml")

class TagManager : public wxObject
{
	static TagManager* instance;
	wxXmlDocument doc;
	
	TagManager();
	TagManager(const TagManager&){}
	TagManager& operator=(const TagManager&)
	{
		return *instance;
	}
	
public:
	static TagManager* GetInstance();
	bool GetTagValues(const wxString& tag,wxString* value,wxString* translation);

};

#endif
