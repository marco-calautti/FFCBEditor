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


#ifndef __CONFIG_MANAGER__
#define __CONFIG_MANAGER__

#include <wx/wx.h>
#include <wx/config.h>

class ConfigManager : public wxObject
{
private:
	static ConfigManager* instance;
	ConfigManager();

public:
	static ConfigManager* GetInstance();

	static const wxString HEX_EDITOR_KEY;

	void SetParameter(const wxString& key,wxString& val);
	wxString GetParameter(const wxString& key);

private:
	wxConfig* config;
};
#endif