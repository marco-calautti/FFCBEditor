#ifndef __FFCBFILE_DROP_HANDLER__
#define __FFCBFILE_DROP_HANDLER__
#include <wx/object.h>

class FFCBFileDropHandler : public wxObject
{
public:
	virtual void HandleFileDrop(wxString& filename)=0;
};
#endif