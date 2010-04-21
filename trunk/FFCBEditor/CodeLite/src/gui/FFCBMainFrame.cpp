#include "FFCBDropTarget.h"
#include "FFCBMainFrame.h"
#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/dir.h>

#include "CBItemData.h"
#include "FFCBPreviewDialog.h"
#include "FFCBPreferencesDialog.h"

#include "../cblib/CBSingleFile.h"
#include "../cblib/CBTextArchive.h"
#include "../common/DBManager.h"
#include "../common/common.h"
#include "res/icon.xpm"

FFCBMainFrame::FFCBMainFrame( wxWindow* parent )
:
MainFrame( parent )
{
	wxIcon icon(icon_xpm);
	SetIcon(icon);

	filesTree->AddRoot(_("Opened files"));
	singleFilePanel=new FFCBSingleFilePanel(rightPanel);
	rightPanel->GetSizer()->Add(singleFilePanel, 1, wxALL|wxEXPAND, 5 );
	singleFilePanel->Show(false);

	archivePanel=new FFCBTextArchivePanel(rightPanel);
	rightPanel->GetSizer()->Add(archivePanel, 1, wxALL|wxEXPAND, 5 );
	archivePanel->Show(false);
	
	filesTree->SetDropTarget(new FFCBDropTarget(this));
}


void FFCBMainFrame::OnClickOpen( wxCommandEvent& event )
{
	wxFileDialog dialog(this);
	int res=dialog.ShowModal();

	if(res!=wxID_OK) return;

	wxString fileName=dialog.GetPath();
	
	CheckAndOpenFile(fileName);
}

void FFCBMainFrame::OnClickFolder( wxCommandEvent& event )
{
	wxDirDialog dialog(this);
	int res=dialog.ShowModal();

	if(res!=wxID_OK) return;

	wxArrayString names;
	wxDir::GetAllFiles(dialog.GetPath(),&names,wxEmptyString,wxDIR_FILES);

	for(size_t i=0;i<names.GetCount();i++)
		CheckAndOpenFile(names[i]);
	
}
void FFCBMainFrame::OnClickFolderDb( wxCommandEvent& event )
{
	wxDirDialog dialog(this);
	int res=dialog.ShowModal();

	if(res!=wxID_OK) return;

	wxArrayString names;
	wxDir::GetAllFiles(dialog.GetPath(),&names,wxEmptyString,wxDIR_FILES);

	DBManager* manager=DBManager::GetInstance();
	for(size_t i=0;i<names.GetCount();i++){
		wxFileName fn(names[i]);
		wxString fullName=fn.GetFullName();
		FileType type=manager->GetFileType(fullName);
		if(type!=NO_FILE)
			OpenFile(names[i],type);
	}

}
void FFCBMainFrame::CheckAndOpenFile(wxString& fileName)
{
	OpenFile(fileName,CheckFileType(fileName));
		
}

void FFCBMainFrame::OpenFile(wxString& fileName,FileType type)
{
	wxFileName fn(fileName);
	switch(type){
		//this file contains only one text section
		case SINGLE_FILE:
		{
			CBSingleFile* file=new CBSingleFile(fileName);
			wxString name;
			wxString fullName=fn.GetFullName();
			name << wxT("[") << fn.GetFullName() << wxT("] ") << DBManager::GetInstance()->GetFileDescription(fullName);
			wxTreeItemId itmId=filesTree->AppendItem(filesTree->GetRootItem(),name);
			
			CBItemData* parentData=new CBItemData();
			parentData->SetType(CB_SINGLE_FILE);
			parentData->SetString(fileName);
			parentData->SetData(file);

			filesTree->SetItemData(itmId,parentData);

			CBItemData* itmData=new CBItemData();


			itmData->SetType(CB_TEXT_SECTION);
			itmData->SetSectionIndex(0);

			itmId=filesTree->AppendItem(itmId,_("Text Section"));
			
			filesTree->SetItemData(itmId,itmData);

		}
		break;

		//this file is a text archive
		case TEXT_ARCHIVE:
		{
			CBTextArchive* file=new CBTextArchive(fileName);

			wxString name;
			wxString fullName=fn.GetFullName();
			name << wxT("[") << fn.GetFullName() << wxT("] ") << DBManager::GetInstance()->GetFileDescription(fullName);

			wxTreeItemId parentId=filesTree->AppendItem(filesTree->GetRootItem(),name);
			
			CBItemData* parentData=new CBItemData();
			parentData->SetType(CB_TEXT_ARCHIVE);
			parentData->SetString(fileName);
			parentData->SetData(file);

			filesTree->SetItemData(parentId,parentData);

			for(size_t i=0;i<file->Size();i++){
				CBItemData* itmData=new CBItemData();

				itmData->SetType(CB_TEXT_SECTION);
				itmData->SetSectionIndex(i);

				wxTreeItemId curId=filesTree->AppendItem(parentId,wxString::Format(_("Text Section %d"),i+1));
			
				filesTree->SetItemData(curId,itmData);
			}
		}
		break;
	}
}

void FFCBMainFrame::OnItemClicked( wxTreeEvent& event )
{
	wxTreeItemId id=event.GetItem();
	if(!filesTree->GetItemData(id))
		return;

	CBItemData* data=(CBItemData*)filesTree->GetItemData(id);

	switch(data->GetType()){
		case CB_TEXT_SECTION:
		{
			wxTreeItemId parentId=filesTree->GetItemParent(id);
			CBItemData* parentData=(CBItemData*)filesTree->GetItemData(parentId);

			switch(parentData->GetType()){
				case CB_SINGLE_FILE:
				{
					archivePanel->Show(false);
					nullPanel->Show(false);
					wxString name=parentData->GetString(); //filename
					singleFilePanel->SetFile((CBSingleFile*)parentData->GetData(),name);
					singleFilePanel->Show(true);
				}

				break;

				case CB_TEXT_ARCHIVE:
					singleFilePanel->Show(false);
					nullPanel->Show(false);
					wxString name=parentData->GetString(); //filename
					archivePanel->SetEditInfo((CBTextArchive*)parentData->GetData(),data->GetSectionIndex(),name);
					archivePanel->Show(true);

				break;
			}

			rightPanel->Layout();
		}
		break;
		
		default: //file name node
		{
			wxFileName fn(data->GetString());
			wxString fullName=fn.GetFullName();
			DBManager* manager=DBManager::GetInstance();
			wxString descr=manager->GetFileDescription(fullName);
			wxString newDescr=wxGetTextFromUser(_("Edit file description:"),fullName,descr);
			manager->SetFileDescription(fullName,newDescr);
			
			wxString name;
			name << wxT("[") << fullName << wxT("] ") << newDescr;

			filesTree->SetItemText(id,name);
			
		}
	}
}

void FFCBMainFrame::OnClickPreferences( wxCommandEvent& event)
{
	FFCBPreferencesDialog* pDialog=new FFCBPreferencesDialog(this);
	pDialog->ShowModal();
}

void FFCBMainFrame::OnExit( wxCloseEvent& event )
{
	Destroy();
}

void FFCBMainFrame::OnClickExit( wxCommandEvent& event )
{
	Destroy();
}

void FFCBMainFrame::OnAbout( wxCommandEvent& event )
{
	wxMessageBox(wxT("Final Fantasy Crystal Bearers Text Editor v0.1.\nPhoenix (SadNES cITy Translations)."),
				 wxT("Info"),
				 wxICON_INFORMATION,
				 this);
}
FileType FFCBMainFrame::CheckFileType(wxString& fileName)
{
	FileType type;
	wxFileName fn(fileName);
	DBManager* manager=DBManager::GetInstance();

	//check if this file doesn't contain text
	if(NotContainsText(fileName)) return NO_FILE;
	
	wxString fullName=fn.GetFullName();
	//maybe, this file contains text
	if(!manager->Contains(fullName)){
		//let the user choose
		FFCBPreviewDialog dialog(this,fileName);
		type=dialog.GetFileType();
	}else
		return manager->GetFileType(fullName);

	return type;
}

void FFCBMainFrame::HandleFileDrop(wxString& filename)
{
	CheckAndOpenFile(filename);
}