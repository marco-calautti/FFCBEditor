#include "FFCBPreviewDialog.h"
#include <wx/utils.h>
#include <wx/filename.h>
#include <wx/msgdlg.h>
#include "../common/DBManager.h"
#include "../common/ConfigManager.h"

FFCBPreviewDialog::FFCBPreviewDialog( wxWindow* parent,wxString f )
:
PreviewDialog( parent )
{
	fileName=f;
	choiceBox->AppendString(CHOICE_UNKNOWN);
	choiceBox->AppendString(CHOICE_SINGLE_FILE);
	choiceBox->AppendString(CHOICE_TEXT_ARCHIVE);
	choiceBox->SetSelection(0);
	wxFileName fn(fileName);
	SetTitle(fn.GetFullName());
}

void FFCBPreviewDialog::OnExit( wxCloseEvent& event )
{
	type=NO_FILE;
	Destroy();
}

void FFCBPreviewDialog::OnPreview( wxCommandEvent& event )
{
	wxString command;
	ConfigManager* manager=ConfigManager::GetInstance();
	wxString hexEditor=manager->GetParameter(ConfigManager::HEX_EDITOR_KEY);

	command << hexEditor << wxT(" ") << wxT("\"") << fileName<<wxT("\"");
	wxExecute(command);
}

void FFCBPreviewDialog::OnOk( wxCommandEvent& event )
{

	switch(choiceBox->GetSelection()){
		case 0: //unknown
			type=NO_FILE;
		break;

		case 1: //single
			type=SINGLE_FILE;
		break;

		case 2: //archive
			type=TEXT_ARCHIVE;
		break;
	}
	
	if(type!=NO_FILE){
		wxFileName fn(fileName);
		wxString fullName=fn.GetFullName();
		int res=wxMessageBox(wxString::Format(_("Would you like to add %s to the DB?"),fullName.c_str()),_("Question"),wxYES_NO,this);
		if(res==wxYES){
			DBManager* manager=DBManager::GetInstance();
			wxString value=fileDescriptionField->GetValue();
			manager->AddFile(fullName,type,value);
		}
	}
	Destroy();
}

void FFCBPreviewDialog::OnCancel( wxCommandEvent& event )
{
	type=NO_FILE;
	Destroy();
}

FileType FFCBPreviewDialog::GetFileType()
{
	ShowModal();
	return type;
}