///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "cbgui.h"

///////////////////////////////////////////////////////////////////////////

NullPanel::NullPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Select a section to edit on the left"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText2->Wrap( -1 );
	bSizer11->Add( m_staticText2, 1, wxALIGN_CENTER|wxALL, 5 );

	this->SetSizer( bSizer11 );
	this->Layout();
	bSizer11->Fit( this );
}

NullPanel::~NullPanel()
{
}

BEGIN_EVENT_TABLE( SingleFilePanel, wxPanel )
	EVT_BUTTON( wxID_APPLY, SingleFilePanel::_wxFB_OnApplyChanges )
END_EVENT_TABLE()

SingleFilePanel::SingleFilePanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Text to edit:") ), wxVERTICAL );

	textField = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_MULTILINE );
	sbSizer1->Add( textField, 1, wxALL|wxEXPAND, 1 );

	bSizer4->Add( sbSizer1, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	applyButton = new wxButton( this, wxID_APPLY, _("Apply Changes"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( applyButton, 0, wxALL, 5 );

	bSizer4->Add( bSizer5, 0, wxALIGN_RIGHT, 5 );

	this->SetSizer( bSizer4 );
	this->Layout();
	bSizer4->Fit( this );
}

SingleFilePanel::~SingleFilePanel()
{
}

BEGIN_EVENT_TABLE( TextArchivePanel, wxPanel )
	EVT_BUTTON( wxID_PREV_BUTTON, TextArchivePanel::_wxFB_OnPrevText )
	EVT_BUTTON( wxID_NEXT_BUTTON, TextArchivePanel::_wxFB_OnNextText )
	EVT_BUTTON( wxID_SAVE_BUTTON, TextArchivePanel::_wxFB_OnApply )
	EVT_BUTTON( wxID_SAVE_ALL, TextArchivePanel::_wxFB_OnSaveAll )
END_EVENT_TABLE()

TextArchivePanel::TextArchivePanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Select String:") ), wxVERTICAL );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	prevTextButton = new wxButton( this, wxID_PREV_BUTTON, _("<<"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( prevTextButton, 1, wxALL, 5 );

	staticSectionIdx = new wxStaticText( this, wxID_ANY, _("#"), wxDefaultPosition, wxDefaultSize, 0 );
	staticSectionIdx->Wrap( -1 );
	bSizer10->Add( staticSectionIdx, 0, wxALIGN_CENTER, 5 );

	staticSep = new wxStaticText( this, wxID_ANY, _("/"), wxDefaultPosition, wxDefaultSize, 0 );
	staticSep->Wrap( -1 );
	bSizer10->Add( staticSep, 0, wxALIGN_CENTER, 5 );

	staticTotal = new wxStaticText( this, wxID_ANY, _("##"), wxDefaultPosition, wxDefaultSize, 0 );
	staticTotal->Wrap( -1 );
	bSizer10->Add( staticTotal, 0, wxALIGN_CENTER, 5 );

	nextTextButton = new wxButton( this, wxID_NEXT_BUTTON, _(">>"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( nextTextButton, 1, wxALL, 5 );

	sbSizer2->Add( bSizer10, 1, wxEXPAND, 5 );

	bSizer8->Add( sbSizer2, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Text to edit:") ), wxVERTICAL );

	textField = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_MULTILINE );
	sbSizer3->Add( textField, 1, wxALL|wxEXPAND, 5 );

	bSizer8->Add( sbSizer3, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	applyButton = new wxButton( this, wxID_SAVE_BUTTON, _("Apply Changes of Current Text"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( applyButton, 0, wxALL, 5 );

	saveAllButton = new wxButton( this, wxID_SAVE_ALL, _("Save ALL"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( saveAllButton, 0, wxALL, 5 );

	bSizer8->Add( bSizer9, 0, wxALIGN_RIGHT, 5 );

	this->SetSizer( bSizer8 );
	this->Layout();
}

TextArchivePanel::~TextArchivePanel()
{
}

BEGIN_EVENT_TABLE( MainFrame, wxFrame )
	EVT_CLOSE( MainFrame::_wxFB_OnExit )
	EVT_MENU( wxID_MENU_OPEN, MainFrame::_wxFB_OnClickOpen )
	EVT_MENU( wxID_MENU_FOLDER, MainFrame::_wxFB_OnClickFolder )
	EVT_MENU( wxID_MENU_FOLDER_DB, MainFrame::_wxFB_OnClickFolderDb )
	EVT_MENU( wxID_EXIT, MainFrame::_wxFB_OnClickExit )
	EVT_MENU( wxID_MENU_PREFERENCES, MainFrame::_wxFB_OnClickPreferences )
	EVT_MENU( wxID_ABOUT, MainFrame::_wxFB_OnAbout )
	EVT_TREE_ITEM_ACTIVATED( wxID_FILES_TREE, MainFrame::_wxFB_OnItemClicked )
END_EVENT_TABLE()

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	menuBar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	wxMenuItem* openMenuItem;
	openMenuItem = new wxMenuItem( fileMenu, wxID_MENU_OPEN, wxString( _("Open...") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( openMenuItem );

	wxMenuItem* openFolderMenuItem;
	openFolderMenuItem = new wxMenuItem( fileMenu, wxID_MENU_FOLDER, wxString( _("Open Folder...") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( openFolderMenuItem );

	wxMenuItem* openFolderDbMenuItem;
	openFolderDbMenuItem = new wxMenuItem( fileMenu, wxID_MENU_FOLDER_DB, wxString( _("Open DB Files from Folder...") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( openFolderDbMenuItem );

	fileMenu->AppendSeparator();

	wxMenuItem* exitMenuItem;
	exitMenuItem = new wxMenuItem( fileMenu, wxID_EXIT, wxString( _("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( exitMenuItem );

	menuBar->Append( fileMenu, _("File") );

	editMenu = new wxMenu();
	wxMenuItem* preferencesItem;
	preferencesItem = new wxMenuItem( editMenu, wxID_MENU_PREFERENCES, wxString( _("Preferences...") ) , wxEmptyString, wxITEM_NORMAL );
	editMenu->Append( preferencesItem );

	menuBar->Append( editMenu, _("Edit") );

	helpMenu = new wxMenu();
	wxMenuItem* aboutMenuItem;
	aboutMenuItem = new wxMenuItem( helpMenu, wxID_ABOUT, wxString( _("About") ) , wxEmptyString, wxITEM_NORMAL );
	helpMenu->Append( aboutMenuItem );

	menuBar->Append( helpMenu, _("Help") );

	this->SetMenuBar( menuBar );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	splitter = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_3DSASH|wxSP_NO_XP_THEME );
	splitter->Connect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::splitterOnIdle ), NULL, this );
	leftPanel = new wxPanel( splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	filesTree = new wxTreeCtrl( leftPanel, wxID_FILES_TREE, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	bSizer3->Add( filesTree, 1, wxEXPAND, 5 );

	leftPanel->SetSizer( bSizer3 );
	leftPanel->Layout();
	bSizer3->Fit( leftPanel );
	rightPanel = new wxPanel( splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* rightPanelSizer;
	rightPanelSizer = new wxBoxSizer( wxHORIZONTAL );

	nullPanel=new NullPanel(rightPanel);
	rightPanelSizer->Add( nullPanel, 1, wxALL|wxEXPAND, 5 );

	rightPanel->SetSizer( rightPanelSizer );
	rightPanel->Layout();
	rightPanelSizer->Fit( rightPanel );
	splitter->SplitVertically( leftPanel, rightPanel, 250 );
	bSizer1->Add( splitter, 1, wxEXPAND, 5 );

	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

MainFrame::~MainFrame()
{
}

BEGIN_EVENT_TABLE( PreferencesDialog, wxDialog )
	EVT_CLOSE( PreferencesDialog::_wxFB_OnExit )
	EVT_BUTTON( wxID_BROWSE_HEX, PreferencesDialog::_wxFB_OnClickBrowseHex )
	EVT_BUTTON( wxID_OK, PreferencesDialog::_wxFB_OnClickOk )
	EVT_BUTTON( wxID_CANCEL, PreferencesDialog::_wxFB_OnClickCancel )
END_EVENT_TABLE()

PreferencesDialog::PreferencesDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Preferences") ), wxHORIZONTAL );

	m_staticText6 = new wxStaticText( this, wxID_ANY, _("Hex Editor for Preview:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	sbSizer4->Add( m_staticText6, 0, wxALL, 5 );

	hexTextField = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( hexTextField, 1, wxTOP, 2 );

	browseHexButton = new wxButton( this, wxID_BROWSE_HEX, _("Browse..."), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( browseHexButton, 0, wxLEFT, 2 );

	bSizer13->Add( sbSizer4, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	okButton = new wxButton( this, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( okButton, 0, wxALL, 5 );

	cancelButton = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( cancelButton, 0, wxALL, 5 );

	bSizer13->Add( bSizer14, 0, wxALIGN_RIGHT, 5 );

	this->SetSizer( bSizer13 );
	this->Layout();
}

PreferencesDialog::~PreferencesDialog()
{
}

BEGIN_EVENT_TABLE( PreviewDialog, wxDialog )
	EVT_CLOSE( PreviewDialog::_wxFB_OnExit )
	EVT_BUTTON( wxID_PREVIEW, PreviewDialog::_wxFB_OnPreview )
	EVT_BUTTON( wxID_OK, PreviewDialog::_wxFB_OnOk )
	EVT_BUTTON( wxID_CANCEL, PreviewDialog::_wxFB_OnCancel )
END_EVENT_TABLE()

PreviewDialog::PreviewDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	previewButton = new wxButton( this, wxID_PREVIEW, _("Open Preview"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( previewButton, 1, wxALL, 5 );

	wxArrayString choiceBoxChoices;
	choiceBox = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choiceBoxChoices, 0 );
	choiceBox->SetSelection( 0 );
	bSizer11->Add( choiceBox, 0, wxALL, 5 );

	okButton = new wxButton( this, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( okButton, 0, wxALL, 5 );

	cancelButton = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( cancelButton, 0, wxALL, 5 );

	bSizer10->Add( bSizer11, 0, wxALIGN_RIGHT|wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5 = new wxStaticText( this, wxID_ANY, _("File Description:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer12->Add( m_staticText5, 0, wxALIGN_CENTER|wxALL, 5 );

	fileDescriptionField = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( fileDescriptionField, 1, wxALIGN_CENTER|wxBOTTOM|wxRIGHT|wxTOP, 5 );

	bSizer10->Add( bSizer12, 0, wxEXPAND, 5 );

	this->SetSizer( bSizer10 );
	this->Layout();
}

PreviewDialog::~PreviewDialog()
{
}
