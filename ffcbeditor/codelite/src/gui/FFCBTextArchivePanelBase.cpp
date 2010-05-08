#include "FFCBTextArchivePanelBase.h"
#include <wx/filename.h>
#include "../common/ConfigManager.h"

FFCBTextArchivePanelBase::FFCBTextArchivePanelBase( wxWindow* parent )
:
TextArchivePanel( parent )
{
	duplicateCheckBox->SetValue(
	ConfigManager::GetInstance()->GetParameterBool(ConfigManager::TRANSLATE_DUPLICATE_KEY)
	);
}

void FFCBTextArchivePanelBase::UpdateView()
{
	//sets current index
	staticSectionIdx->SetLabel(wxString::Format(wxT("%d"),curText+1));
	textSelectionChoice->SetSelection(curText);
	//sets text
	textField->SetValue(GetTextSection(sectionId)->GetText(curText));
	
	
	this->Layout();	
}

void FFCBTextArchivePanelBase::OnPrevText( wxCommandEvent& event )
{
	SaveCurrentText();
	
	if(curText==0)
		curText=GetTextSection(sectionId)->Size()-1;
	else
		curText--;

	UpdateView();
}

void FFCBTextArchivePanelBase::OnNextText( wxCommandEvent& event )
{
	SaveCurrentText();
	
	if(curText==GetTextSection(sectionId)->Size()-1)
		curText=0;
	else
		curText++;

	
	UpdateView();
}

void FFCBTextArchivePanelBase::OnTextSelected( wxCommandEvent& event )
{
	SaveCurrentText();
	curText=event.GetSelection();
	UpdateView();
}
void FFCBTextArchivePanelBase::OnApply( wxCommandEvent& event )
{
	SaveCurrentText();
	
	textSelectionChoice->SetSelection(curText);
	
}

void FFCBTextArchivePanelBase::OnSaveAll( wxCommandEvent& event )
{
	OnApply(event);
	wxFileName fn(fileName);
	wxString fullName=fn.GetFullName();
	SaveFile(fullName);
}

void FFCBTextArchivePanelBase::OnCheckDuplicate( wxCommandEvent& event )
{
	ConfigManager::GetInstance()->SetParameter(ConfigManager::TRANSLATE_DUPLICATE_KEY,event.IsChecked());
}

void FFCBTextArchivePanelBase::PopulateView(size_t i)
{
	staticTotal->SetLabel(wxString::Format(wxT("%d"),GetTextSection(i)->Size()));
	
	//populating choice box
	textSelectionChoice->Clear();
	for(size_t j=0;j<GetTextSection(i)->Size();j++){
		wxString text=GetTextSection(i)->GetText(j);
		if(text.Length()>25)
			textSelectionChoice->Append(wxString::Format(_("String %d (%s...)"),j+1,text.Left(25).c_str()));
		else if(text.Length()>0)
			textSelectionChoice->Append(wxString::Format(_("String %d (%s)"),j+1,text.c_str()));
		else
			textSelectionChoice->Append(wxString::Format(_("String %d ()"),j+1));
	}
}

void FFCBTextArchivePanelBase::SaveCurrentText()
{
	wxString text=textField->GetValue();
	
	
	bool tDuplicate=ConfigManager::GetInstance()->GetParameterBool(ConfigManager::TRANSLATE_DUPLICATE_KEY);
	
	if(tDuplicate){
		wxString origText=GetTextSection(sectionId)->GetText(curText);
		for(size_t i=0;i<GetTextSection(sectionId)->Size();i++){
			wxString cur=GetTextSection(sectionId)->GetText(i);
			if(cur==origText){
				GetTextSection(sectionId)->SetText(i,text);
				if(text.Length()>25)
					textSelectionChoice->SetString(i,wxString::Format(_("String %d (%s...)"),i+1,text.Left(25).c_str()));
				else if(text.Length()>0)
					textSelectionChoice->SetString(i,wxString::Format(_("String %d (%s)"),i+1,text.c_str()));
				else
					textSelectionChoice->SetString(i,wxString::Format(_("String %d ()"),i+1));
			}
		}
			
	}else{
		GetTextSection(sectionId)->SetText(curText,text);
		
		if(text.Length()>25)
			textSelectionChoice->SetString(curText,wxString::Format(_("String %d (%s...)"),curText+1,text.Left(25).c_str()));
		else if(text.Length()>0)
			textSelectionChoice->SetString(curText,wxString::Format(_("String %d (%s)"),curText+1,text.c_str()));
		else
			textSelectionChoice->SetString(curText,wxString::Format(_("String %d ()"),curText+1));
	}
}
