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