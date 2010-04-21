#ifndef __FFCBDROP_TARGET__
#define __FFCBDROP_TARGET__

#include "FFCBFileDropHandler.h"
#include <wx/dnd.h>

class FFCBDropTarget : public wxFileDropTarget
{
public:
	FFCBDropTarget(FFCBFileDropHandler* handler);
	
	virtual bool OnDropFiles(wxCoord,wxCoord,const wxArrayString&);
	
protected:
	FFCBFileDropHandler* handler;
};

#endif