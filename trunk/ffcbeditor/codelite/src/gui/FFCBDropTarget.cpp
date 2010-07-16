#include "FFCBDropTarget.h"

FFCBDropTarget::FFCBDropTarget(FFCBFileDropHandler* handler) : wxFileDropTarget()
{
	this->handler=handler;
}

bool FFCBDropTarget::OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames)
{
	for(int i=0;i<filenames.size();i++)
		handler->HandleFileDrop(filenames[i]);
		
	return true;
}
