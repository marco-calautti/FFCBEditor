#include "FFCBTextArchivePanel.h"
#include "../common/common.h"
#include "../common/FileManager.h"
#include <wx/filename.h>

FFCBTextArchivePanel::FFCBTextArchivePanel( wxWindow* parent )
:
TextArchivePanel( parent )
{

}

void FFCBTextArchivePanel::UpdateView()
{
	//sets current index
	staticSectionIdx->SetLabel(wxString::Format(wxT("%d"),curText+1));
	textSelectionChoice->SetSelection(curText);
	//sets text
	textField->SetValue((*file)[sectionId]->GetText(curText));
	
	
	this->Layout();	
}

void FFCBTextArchivePanel::OnPrevText( wxCommandEvent& event )
{
	if(curText==0)
		curText=(*file)[sectionId]->Size()-1;
	else
		curText--;

	UpdateView();
}

void FFCBTextArchivePanel::OnNextText( wxCommandEvent& event )
{
	if(curText==(*file)[sectionId]->Size()-1)
		curText=0;
	else
		curText++;

	UpdateView();
}

void FFCBTextArchivePanel::OnTextSelected( wxCommandEvent& event )
{
	curText=event.GetSelection();
	UpdateView();
}
void FFCBTextArchivePanel::OnApply( wxCommandEvent& event )
{
	wxString value=textField->GetValue();
	(*file)[sectionId]->SetText(curText,value);
}

void FFCBTextArchivePanel::OnSaveAll( wxCommandEvent& event )
{
	OnApply(event);
	wxFileName fn(fileName);
	wxString fullName=fn.GetFullName();
	wxString backupName=FileManager::GetBackupFilePath(fullName,TEXT_ARCHIVE);
	file->SaveTo(backupName);
}

void FFCBTextArchivePanel::SetEditInfo(CBTextArchive* f,size_t i,wxString fn)
{
	file=f;
	sectionId=i;
	fileName=fn;
	curText=0;
	staticSectionIdx->SetLabel(wxString::Format(wxT("%d"),curText+1));
	staticTotal->SetLabel(wxString::Format(wxT("%d"),(*file)[i]->Size()));
	
	//populating choice box
	textSelectionChoice->Clear();
	for(size_t j=0;j<(*file)[i]->Size();j++){
		wxString text=(*file)[i]->GetText(j);
		if(text.Length()>25)
			textSelectionChoice->Append(wxString::Format(_("String %d (%s...)"),j+1,text.Left(25).c_str()));
		else if(text.Length()>0)
			textSelectionChoice->Append(wxString::Format(_("String %d (%s)"),j+1,text.c_str()));
		else
			textSelectionChoice->Append(wxString::Format(_("String %d ()"),j+1));
	}
	textSelectionChoice->SetSelection(curText);
	textField->SetValue((*file)[i]->GetText()); //sets first text block
}