#include <wx/msgdlg.h>
#include "FFCBTextCtrl.h"

BEGIN_EVENT_TABLE( FFCBTextCtrl, wxTextCtrl )
	EVT_ENTER_WINDOW(FFCBTextCtrl::OnMouseOver )
	EVT_MOTION(FFCBTextCtrl::OnMouseOver)
END_EVENT_TABLE()

FFCBTextCtrl::FFCBTextCtrl(wxWindow* parent,wxWindowID id) : 
	wxTextCtrl(parent,id,wxEmptyString,wxDefaultPosition,wxDefaultSize, wxHSCROLL|wxTE_MULTILINE)
{
	
}

void FFCBTextCtrl::OnMouseOver(wxMouseEvent& event)
{
	wxTextCoord col,row;
	wxTextCtrlHitTestResult res=HitTest(event.GetPosition(),&col,&row);
	if(res==wxTE_HT_UNKNOWN){
		event.Skip();
		return;
	}
	wxString tag=GetTagValue(col,row);
	this->SetToolTip(tag);
}

wxString FFCBTextCtrl::GetTagValue(wxTextCoord col,wxTextCoord row)
{
	wxTextCoord start,end;
	wxString line=GetLineText(row);
	//finding '<'
	for(int i=col;i>=0;i--){
		if(i<col&&line[i]=='>') //we are not inside a tag
			return wxEmptyString;
		if(line[i]=='<'){ //found
			start=i;
			break;
		}
	}
	
	//finding '>' (if we are here, we must find only '>'
	for(int i=col;i<line.Length();i++){
		if(line[i]=='>'){ //found
			end=i;
			break;
		}
	}
	wxString tag=line.SubString(start,end);
	
	//TO-DO: here we should use some TagManager...
	//wxString value=TagManager::GetInstance()->GetValue(tag);
	//return value;
	//just for now return the tag value
	return tag;
}
