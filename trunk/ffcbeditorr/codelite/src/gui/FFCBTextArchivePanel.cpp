#include "FFCBTextArchivePanel.h"

FFCBTextArchivePanel::FFCBTextArchivePanel( wxWindow* parent )
:
TextArchivePanel( parent )
{

}

void FFCBTextArchivePanel::OnPrevText( wxCommandEvent& event )
{
	if(curText==0)
		curText=(*file)[sectionId]->Size()-1;
	else
		curText--;

	//sets current index
	staticSectionIdx->SetLabel(wxString::Format(wxT("%d"),curText+1));

	//sets text
	textField->SetValue((*file)[sectionId]->GetText(curText));

	this->Layout();
}

void FFCBTextArchivePanel::OnNextText( wxCommandEvent& event )
{
	if(curText==(*file)[sectionId]->Size()-1)
		curText=0;
	else
		curText++;

	//sets current index
	staticSectionIdx->SetLabel(wxString::Format(wxT("%d"),curText+1));

	//sets text
	textField->SetValue((*file)[sectionId]->GetText(curText));
	this->Layout();
}

void FFCBTextArchivePanel::OnApply( wxCommandEvent& event )
{
	wxString value=textField->GetValue();
	(*file)[sectionId]->SetText(curText,value);
}
void FFCBTextArchivePanel::OnSaveAll( wxCommandEvent& event )
{
	OnApply(event);
	file->SaveTo(fileName);
}
void FFCBTextArchivePanel::SetEditInfo(CBTextArchive* f,size_t i,wxString fn)
{
	file=f;
	sectionId=i;
	fileName=fn;
	curText=0;
	staticSectionIdx->SetLabel(wxString::Format(wxT("%d"),curText+1));
	staticTotal->SetLabel(wxString::Format(wxT("%d"),(*file)[i]->Size()));
	textField->SetValue((*file)[i]->GetText()); //sets first text block
}