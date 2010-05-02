#include "FFCBSingleFilePanel.h"
#include "../common/FileManager.h"
#include "../common/common.h"
#include <wx/filename.h>

FFCBSingleFilePanel::FFCBSingleFilePanel( wxWindow* parent )
:
SingleFilePanel( parent )
{

}

void FFCBSingleFilePanel::OnApplyChanges( wxCommandEvent& event )
{
	wxString value=textField->GetValue();
	file->GetTextSection()->SetText(value);
	wxFileName fn(fileName);
	wxString fullName=fn.GetFullName();
	wxString backupName=FileManager::GetBackupFilePath(fullName,SINGLE_FILE);
	file->SaveTo(backupName);
}

void FFCBSingleFilePanel::SetFile(CBSingleFile* f,wxString& fn)
{
	file=f;
	textField->SetValue(file->GetTextSection()->GetText());
	fileName=fn;
}
