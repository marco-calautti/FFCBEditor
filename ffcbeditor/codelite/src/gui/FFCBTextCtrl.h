#ifndef __FFCB_TEXT_CTRL__
#define __FFCB_TEXT_CTRL__

#include <wx/textctrl.h>

class FFCBTextCtrl : public wxTextCtrl
{
	DECLARE_EVENT_TABLE()
public:
	FFCBTextCtrl(wxWindow* parent,wxWindowID id);
	virtual void OnMouseOver(wxMouseEvent& event);
private:
	wxString GetTagValue(wxTextCoord col,wxTextCoord row);
};
#endif
