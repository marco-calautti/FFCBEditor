#include "FFCBPreferencesDialog.h"
#include "../common/ConfigManager.h"
#include <wx/file.h>

FFCBPreferencesDialog::FFCBPreferencesDialog( wxWindow* parent )
:
PreferencesDialog( parent )
{
	ConfigManager* manager=ConfigManager::GetInstance();
	wxString editor=manager->GetParameter(ConfigManager::HEX_EDITOR_KEY);
	hexTextField->SetValue(editor);
}

void FFCBPreferencesDialog::OnExit( wxCloseEvent& event )
{
	Destroy();
}

void FFCBPreferencesDialog::OnClickBrowseHex( wxCommandEvent& event )
{
	wxFileDialog dialog(this);
	if(dialog.ShowModal()!=wxID_OK)
		return;

	hexTextField->SetValue(dialog.GetPath());

}

void FFCBPreferencesDialog::OnClickOk( wxCommandEvent& event )
{
	if(ValidData()){
		UpdateConfigs();
		Destroy();
	}else
		wxMessageBox(_("Some data is invalid!"),_T("Warning"),wxICON_EXCLAMATION,this);
}

void FFCBPreferencesDialog::OnClickCancel( wxCommandEvent& event )
{
	Destroy();
}

bool FFCBPreferencesDialog::ValidData()
{
	return wxFile::Exists(hexTextField->GetValue());
}

void FFCBPreferencesDialog::UpdateConfigs()
{
	ConfigManager* manager=ConfigManager::GetInstance();
	wxString value=hexTextField->GetValue();
	manager->SetParameter(ConfigManager::HEX_EDITOR_KEY,value);
}