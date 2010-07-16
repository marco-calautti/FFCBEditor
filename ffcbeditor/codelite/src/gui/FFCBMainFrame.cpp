#include "FFCBDropTarget.h"
#include "FFCBMainFrame.h"
#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/dir.h>
#include <wx/aboutdlg.h>

#include "CBItemData.h"
#include "FFCBPreviewDialog.h"
#include "FFCBPreferencesDialog.h"

#include "../cblib/CBSingleFile.h"
#include "../cblib/CBTextArchive.h"
#include "../common/DBManager.h"
#include "../common/common.h"
#include "../common/FileManager.h"
#include "res/icon.xpm"


BEGIN_EVENT_TABLE( FFCBMainFrame, MainFrame )
	EVT_MENU( wxID_BACKUP, FFCBMainFrame::OnBackup )
END_EVENT_TABLE()

FFCBMainFrame::FFCBMainFrame( wxWindow* parent )
:
MainFrame( parent )
{
	wxIcon icon(icon_xpm);
	SetIcon(icon);

	filesTree->AddRoot(_("Opened files"));
	
	//preparing single file panel
	singleFilePanel=new FFCBSingleFilePanel(rightPanel);
	rightPanel->GetSizer()->Add(singleFilePanel, 1, wxALL|wxEXPAND, 5 );
	singleFilePanel->Show(false);

	//preparing text archive panel
	archivePanel=new FFCBTextArchivePanel(rightPanel);
	rightPanel->GetSizer()->Add(archivePanel, 1, wxALL|wxEXPAND, 5 );
	archivePanel->Show(false);
	
	//preparing FREB archive panel
	eevbPanel=new FFCBEEVBFilePanel(rightPanel);
	rightPanel->GetSizer()->Add(eevbPanel, 1, wxALL|wxEXPAND, 5 );
	eevbPanel->Show(false);
	
	filesTree->SetDropTarget(new FFCBDropTarget(this));
	
	backupMenu=new wxMenu();
	backupMenu->Append(wxID_BACKUP,_("Synchronize Backup!"));
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
			CBSingleFile* file=FileManager::GetInstance()->CreateSingleFileBackup(fileName); //new CBSingleFile(fileName);
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
			CBTextArchive* file=FileManager::GetInstance()->CreateTextArchiveBackup(fileName);//new CBTextArchive(fileName);

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
		//this file is a FREB archive
		case FREB_ARCHIVE:
		{
			CBEEVBFile* file=FileManager::GetInstance()->CreateEEVBFileBackup(fileName);
			wxString name;
			wxString fullName=fn.GetFullName();
			name << wxT("[") << fn.GetFullName() << wxT("] ") << DBManager::GetInstance()->GetFileDescription(fullName);

			wxTreeItemId parentId=filesTree->AppendItem(filesTree->GetRootItem(),name);
			
			CBItemData* parentData=new CBItemData();
			parentData->SetType(CB_EEVB_FILE);
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
					eevbPanel->Show(false);
					nullPanel->Show(false);
					wxString name=parentData->GetString(); //filename
					singleFilePanel->SetFile((CBSingleFile*)parentData->GetData(),name);
					singleFilePanel->Show(true);
				}

				break;

				case CB_TEXT_ARCHIVE:
				{
					singleFilePanel->Show(false);
					eevbPanel->Show(false);
					nullPanel->Show(false);
					wxString name=parentData->GetString(); //filename
					archivePanel->SetEditInfo((CBTextArchive*)parentData->GetData(),data->GetSectionIndex(),name);
					archivePanel->Show(true);
				}
				break;
				
				case CB_EEVB_FILE:
				{
					singleFilePanel->Show(false);
					nullPanel->Show(false);
					archivePanel->Show(false);
					wxString name=parentData->GetString(); //filename
					eevbPanel->SetEditInfo((CBEEVBFile*)parentData->GetData(),data->GetSectionIndex(),name);
					eevbPanel->Show(true);
				}
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

void FFCBMainFrame::OnItemRightClick(wxTreeEvent& event)
{
	selectedId=event.GetItem();
	
	if(filesTree->GetItemData(selectedId)){
		CBItemData* data=(CBItemData*)filesTree->GetItemData(selectedId);
		if(data->GetType()==CB_TEXT_SECTION)
			return;
	}
	
	PopupMenu(backupMenu,event.GetPoint());
}

void FFCBMainFrame::OnBackup(wxCommandEvent& event)
{
	//file node
	if(filesTree->GetItemData(selectedId)){
		CBItemData* data=(CBItemData*)filesTree->GetItemData(selectedId);
		wxString filePath=data->GetString();
		FileManager::GetInstance()->StoreChangesToOriginal(filePath);
	}else{
		//root node, we synchronize all files
		wxTreeItemIdValue cookie=0;
		wxTreeItemId child=filesTree->GetFirstChild(selectedId,cookie);
		while(child.IsOk()){
			CBItemData* data=(CBItemData*)filesTree->GetItemData(child);
			wxString filePath=data->GetString();
			FileManager::GetInstance()->StoreChangesToOriginal(filePath);
			child=filesTree->GetNextChild(selectedId,cookie);
		}
	}
	
	wxMessageBox(_("Synchronization successful!"),_("Notice"),wxOK,this);
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
	wxAboutDialogInfo info;
	info.AddDeveloper(wxT("Phoenix (SadNES cITy Translations)"));
	info.SetLicense(__FFCB_LICENSE__);
	info.SetName(__FFCB_NAME__);
	info.SetVersion(__FFCB_VERSION__);
	info.SetWebSite(__FFCB_WEBSITE__);
	info.SetCopyright(__FFCB_COPYRIGHT__);
	
	wxAboutBox(info);
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
		
		//check if this is a FREB file
		CBFREBArchive archive(fileName);
		if(archive.IsOk()){ //this is a freb archive, and must contain text
			archive.Close();
			manager->AddFile(fullName,FREB_ARCHIVE);
			return FREB_ARCHIVE;
		}
		archive.Close();
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
