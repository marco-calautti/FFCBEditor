///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __cbgui__
#define __cbgui__

#include <wx/intl.h>

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/checkbox.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/treectrl.h>
#include <wx/splitter.h>
#include <wx/frame.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class NullPanel
///////////////////////////////////////////////////////////////////////////////
class NullPanel : public wxPanel 
{
	private:
	
	protected:
		wxStaticText* m_staticText2;
	
	public:
		NullPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL );
		~NullPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SingleFilePanel
///////////////////////////////////////////////////////////////////////////////
class SingleFilePanel : public wxPanel 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnApplyChanges( wxCommandEvent& event ){ OnApplyChanges( event ); }
		
	
	protected:
		wxTextCtrl* textField;
		wxButton* applyButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnApplyChanges( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		SingleFilePanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL );
		~SingleFilePanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class TextArchivePanel
///////////////////////////////////////////////////////////////////////////////
class TextArchivePanel : public wxPanel 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnPrevText( wxCommandEvent& event ){ OnPrevText( event ); }
		void _wxFB_OnNextText( wxCommandEvent& event ){ OnNextText( event ); }
		void _wxFB_OnTextSelected( wxCommandEvent& event ){ OnTextSelected( event ); }
		void _wxFB_OnCheckDuplicate( wxCommandEvent& event ){ OnCheckDuplicate( event ); }
		void _wxFB_OnApply( wxCommandEvent& event ){ OnApply( event ); }
		void _wxFB_OnSaveAll( wxCommandEvent& event ){ OnSaveAll( event ); }
		
	
	protected:
		enum
		{
			wxID_PREV_BUTTON = 1000,
			wxID_NEXT_BUTTON,
			wxID_TEXT_SELECTION,
			wxID_DUPLICATE_CHECK,
			wxID_SAVE_BUTTON,
			wxID_SAVE_ALL,
		};
		
		wxButton* prevTextButton;
		wxStaticText* staticSectionIdx;
		wxStaticText* staticSep;
		wxStaticText* staticTotal;
		wxButton* nextTextButton;
		wxBoxSizer* customSizer;
		wxStaticText* m_staticText8;
		wxChoice* textSelectionChoice;
		wxTextCtrl* textField;
		wxCheckBox* duplicateCheckBox;
		wxButton* applyButton;
		wxButton* saveAllButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnPrevText( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnNextText( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnTextSelected( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCheckDuplicate( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnApply( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSaveAll( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		TextArchivePanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 554,256 ), long style = wxTAB_TRAVERSAL );
		~TextArchivePanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnExit( wxCloseEvent& event ){ OnExit( event ); }
		void _wxFB_OnClickOpen( wxCommandEvent& event ){ OnClickOpen( event ); }
		void _wxFB_OnClickFolder( wxCommandEvent& event ){ OnClickFolder( event ); }
		void _wxFB_OnClickFolderDb( wxCommandEvent& event ){ OnClickFolderDb( event ); }
		void _wxFB_OnClickExit( wxCommandEvent& event ){ OnClickExit( event ); }
		void _wxFB_OnClickPreferences( wxCommandEvent& event ){ OnClickPreferences( event ); }
		void _wxFB_OnAbout( wxCommandEvent& event ){ OnAbout( event ); }
		void _wxFB_OnItemClicked( wxTreeEvent& event ){ OnItemClicked( event ); }
		void _wxFB_OnItemRightClick( wxTreeEvent& event ){ OnItemRightClick( event ); }
		
	
	protected:
		enum
		{
			wxID_MENU_OPEN = 1000,
			wxID_MENU_FOLDER,
			wxID_MENU_FOLDER_DB,
			wxID_MENU_PREFERENCES,
			wxID_FILES_TREE,
		};
		
		wxMenuBar* menuBar;
		wxMenu* fileMenu;
		wxMenu* editMenu;
		wxMenu* helpMenu;
		wxSplitterWindow* splitter;
		wxPanel* leftPanel;
		wxTreeCtrl* filesTree;
		wxPanel* rightPanel;
		NullPanel* nullPanel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExit( wxCloseEvent& event ){ event.Skip(); }
		virtual void OnClickOpen( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnClickFolder( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnClickFolderDb( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnClickExit( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnClickPreferences( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnItemClicked( wxTreeEvent& event ){ event.Skip(); }
		virtual void OnItemRightClick( wxTreeEvent& event ){ event.Skip(); }
		
	
	public:
		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Final Fantasy Crystal Bearers Editor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 850,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~MainFrame();
		void splitterOnIdle( wxIdleEvent& )
		{
		splitter->SetSashPosition( 250 );
		splitter->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::splitterOnIdle ), NULL, this );
		}
		
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PreferencesDialog
///////////////////////////////////////////////////////////////////////////////
class PreferencesDialog : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnExit( wxCloseEvent& event ){ OnExit( event ); }
		void _wxFB_OnClickBrowseHex( wxCommandEvent& event ){ OnClickBrowseHex( event ); }
		void _wxFB_OnClickOk( wxCommandEvent& event ){ OnClickOk( event ); }
		void _wxFB_OnClickCancel( wxCommandEvent& event ){ OnClickCancel( event ); }
		
	
	protected:
		enum
		{
			wxID_BROWSE_HEX = 1000,
		};
		
		wxStaticText* m_staticText6;
		wxTextCtrl* hexTextField;
		wxButton* browseHexButton;
		wxButton* okButton;
		wxButton* cancelButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExit( wxCloseEvent& event ){ event.Skip(); }
		virtual void OnClickBrowseHex( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnClickOk( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnClickCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		PreferencesDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Preferences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 536,117 ), long style = wxDEFAULT_DIALOG_STYLE );
		~PreferencesDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PreviewDialog
///////////////////////////////////////////////////////////////////////////////
class PreviewDialog : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnExit( wxCloseEvent& event ){ OnExit( event ); }
		void _wxFB_OnPreview( wxCommandEvent& event ){ OnPreview( event ); }
		void _wxFB_OnOk( wxCommandEvent& event ){ OnOk( event ); }
		void _wxFB_OnCancel( wxCommandEvent& event ){ OnCancel( event ); }
		
	
	protected:
		wxButton* previewButton;
		wxChoice* choiceBox;
		wxButton* okButton;
		wxButton* cancelButton;
		wxStaticText* m_staticText5;
		wxTextCtrl* fileDescriptionField;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExit( wxCloseEvent& event ){ event.Skip(); }
		virtual void OnPreview( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		PreviewDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,95 ), long style = wxDEFAULT_DIALOG_STYLE );
		~PreviewDialog();
	
};

#endif //__cbgui__
