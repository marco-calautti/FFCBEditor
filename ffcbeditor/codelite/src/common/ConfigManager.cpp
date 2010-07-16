#include "ConfigManager.h"

ConfigManager* ConfigManager::instance=NULL;
const wxString ConfigManager::HEX_EDITOR_KEY=wxT("Hex Editor");
const wxString ConfigManager::TRANSLATE_DUPLICATE_KEY=wxT("Translate Duplicate");
ConfigManager::ConfigManager()
{
	config=new wxConfig(wxT("FFCBEditor"));
	config->SetPath(wxT("/Preferences"));

#ifdef __WXMSW__
	if(!config->Exists(HEX_EDITOR_KEY))
		config->Write(HEX_EDITOR_KEY,wxT("cygnus.exe"));
#endif
	
	if(!config->Exists(TRANSLATE_DUPLICATE_KEY))
		config->Write(TRANSLATE_DUPLICATE_KEY,true);

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

void ConfigManager::SetParameter(const wxString& key,bool val)
{
	config->Write(key,val);
	config->Flush();
}

wxString ConfigManager::GetParameter(const wxString& key)
{
	return config->Read(key);
}

bool ConfigManager::GetParameterBool(const wxString& key)
{
	bool val;
	config->Read(key,&val);
	return val;
}
