#ifndef __FFCBTextArchivePanel__
#define __FFCBTextArchivePanel__

/**
@file
Subclass of TextArchivePanel, which is generated by wxFormBuilder.
*/

#include "cbgui.h"
#include "../cblib/CBTextArchive.h"

/** Implementing TextArchivePanel */
class FFCBTextArchivePanel : public TextArchivePanel
{
protected:
	// Handlers for TextArchivePanel events.
	void OnPrevText( wxCommandEvent& event );
	void OnNextText( wxCommandEvent& event );
	void OnApply( wxCommandEvent& event );
	void OnSaveAll( wxCommandEvent& event );
	
public:
	/** Constructor */
	FFCBTextArchivePanel( wxWindow* parent );

	void SetEditInfo(CBTextArchive* file,size_t sectionId,wxString fileName);

private:
	CBTextArchive* file;
	size_t sectionId;
	wxString fileName;
	size_t curText;
};

#endif // __FFCBTextArchivePanel__
