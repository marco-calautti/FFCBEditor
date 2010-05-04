#include "FFCBTextArchivePanel.h"
#include "../common/FileManager.h"
#include "../common/common.h"

FFCBTextArchivePanel::FFCBTextArchivePanel(wxWindow* parent)
: FFCBTextArchivePanelBase(parent)
{
	
}

void FFCBTextArchivePanel::SetEditInfo(CBTextArchive* f,size_t i,wxString fn)
{
	file=f;
	sectionId=i;
	fileName=fn;
	curText=0;
	PopulateView(i);
	UpdateView();
}

void FFCBTextArchivePanel::SaveFile(wxString& fullName)
{
	wxString backupName=FileManager::GetBackupFilePath(fullName,TEXT_ARCHIVE);
	file->SaveTo(backupName);
}

CBTextSection* FFCBTextArchivePanel::GetTextSection(size_t idx)
{
	return (*file)[idx];
}