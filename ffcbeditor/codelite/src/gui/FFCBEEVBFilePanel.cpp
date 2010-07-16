#include "FFCBEEVBFilePanel.h"
#include "../common/FileManager.h"
#include "../common/common.h"
#include "../cblib/CBMultiLanguageTextSection.h"

BEGIN_EVENT_TABLE( FFCBEEVBFilePanel, FFCBTextArchivePanelBase )
	EVT_CHOICE( wxID_LANGUAGE_SELECTION, FFCBEEVBFilePanel::OnLanguageSelected )
END_EVENT_TABLE()



FFCBEEVBFilePanel::FFCBEEVBFilePanel(wxWindow* parent)
: FFCBTextArchivePanelBase(parent)
{
	
	languageChoice=new wxChoice( this, wxID_LANGUAGE_SELECTION);
	languageChoice->Append(_("All languages"));
	languageChoice->Append(_("Japanese"));
	languageChoice->Append(_("English"));
	languageChoice->Append(_("German"));
	languageChoice->Append(_("French"));
	languageChoice->Append(_("Spanish"));
	languageChoice->SetSelection(2); //default to english
	curLang=ENGLISH_LANGUAGE;
	customSizer->Add( languageChoice, 1, wxEXPAND|wxRIGHT, 5 );
}

CBTextSection* FFCBEEVBFilePanel::GetTextSection(size_t idx)
{
	return (*file)[idx];
}

void FFCBEEVBFilePanel::SaveFile(wxString& fullName)
{
	switch(file->Save()){
		case CBEEVBFile::EEVB_IO_ERROR:
		{
			wxMessageBox(_("Cannot write changes to file:\nIO Error occurred!"),_("Warning"),wxOK,this);
		}	
		break;
		
		case CBEEVBFile::EEVB_SECTIONS_TOO_BIG:
		{
			int res=wxMessageBox(_("Cannot write changes to file:\nCurrent text sections are too big!\n\nWould you like to save only currently selected language?"),_("Warning"),wxYES_NO,this);
			if(res==wxYES){
				switch(file->TrimAndSave(curLang)){
					case CBEEVBFile::EEVB_IO_ERROR:
					{
						wxMessageBox(_("Cannot write changes to file:\nIO Error occurred!"),_("Warning"),wxOK,this);
					}
					break;
					
					case CBEEVBFile::EEVB_SECTIONS_TOO_BIG:
					{
						wxMessageBox(_("This should never happen :(.\nTrimming other languages is not enough!"),_("Warning"),wxOK,this);
					}
					break;
				}
			}
		}
		break;
	}
}

void FFCBEEVBFilePanel::OnLanguageSelected(wxCommandEvent& event)
{
	switch(event.GetSelection()){
		case 0: //all
			curLang=ALL_LANGUAGES;
		break;
		
		case 1: //jap
			curLang=JAPANESE_LANGUAGE;
		break;
		
		case 2: //eng
			curLang=ENGLISH_LANGUAGE;
		break;
		
		case 3: //ger
			curLang=GERMAN_LANGUAGE;
		break;
		
		case 4: //fre
			curLang=FRENCH_LANGUAGE;
		break;
		
		case 5: //spa
			curLang=SPANISH_LANGUAGE;
		break;
	}
	file->SetLanguage(curLang);
	if(curText>(*file)[sectionId]->Size())
		curText=0;
	PopulateView(sectionId);
	UpdateView();
}

void FFCBEEVBFilePanel::SetEditInfo(CBEEVBFile* f,size_t i,wxString fn)
{
	file=f;
	sectionId=i;
	fileName=fn;
	curText=0;
	file->SetLanguage(ENGLISH_LANGUAGE);
	languageChoice->SetSelection(2); //default to english
	curLang=ENGLISH_LANGUAGE;
	PopulateView(i);
	UpdateView();
}
