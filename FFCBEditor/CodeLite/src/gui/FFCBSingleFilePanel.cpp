#include "FFCBSingleFilePanel.h"

FFCBSingleFilePanel::FFCBSingleFilePanel( wxWindow* parent )
:
SingleFilePanel( parent )
{

}

void FFCBSingleFilePanel::OnApplyChanges( wxCommandEvent& event )
{
	wxString value=textField->GetValue();
	file->GetTextSection()->SetText(value);
	file->SaveTo(fileName);
}

void FFCBSingleFilePanel::SetFile(CBSingleFile* f,wxString& fn)
{
	file=f;
	textField->SetValue(file->GetTextSection()->GetText());
	fileName=fn;
}
