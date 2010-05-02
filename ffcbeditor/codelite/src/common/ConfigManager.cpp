#include "ConfigManager.h"

ConfigManager* ConfigManager::instance=NULL;
const wxString ConfigManager::HEX_EDITOR_KEY=wxT("Hex Editor");

ConfigManager::ConfigManager()
{
	config=new wxConfig(wxT("FFCBEditor"));
	config->SetPath(wxT("/Preferences"));

#ifdef __WXMSW__
	if(!config->Exists(HEX_EDITOR_KEY))
		config->Write(HEX_EDITOR_KEY,wxT("cygnus.exe"));
#endif

}

ConfigManager::~ConfigManager()
{
	if(config)
		delete config;
}

ConfigManager* ConfigManager::GetInstance()
{
	if(!instance)
		instance=new ConfigManager();
	return instance;
}

void ConfigManager::SetParameter(const wxString& key,wxString& val)
{
	config->Write(key,val);
	config->Flush();
}

wxString ConfigManager::GetParameter(const wxString& key)
{
	return config->Read(key);
}