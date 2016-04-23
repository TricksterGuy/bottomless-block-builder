///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 25 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "PanelDisplay.hpp"
#include "wx/tglbtn.h"

#include "BBBGui.h"

///////////////////////////////////////////////////////////////////////////

BBBGui::BBBGui( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar1 = new wxMenuBar( 0 );
	file = new wxMenu();
	wxMenuItem* open;
	open = new wxMenuItem( file, wxID_OPEN, wxString( wxT("Open") ) + wxT('\t') + wxT("Ctrl+O"), wxEmptyString, wxITEM_NORMAL );
	file->Append( open );
	
	wxMenuItem* save;
	save = new wxMenuItem( file, wxID_SAVE, wxString( wxT("Save") ) + wxT('\t') + wxT("Ctrl+S"), wxEmptyString, wxITEM_NORMAL );
	file->Append( save );
	
	wxMenuItem* exit;
	exit = new wxMenuItem( file, wxID_EXIT, wxString( wxT("Exit") ) + wxT('\t') + wxT("Alt+F4"), wxEmptyString, wxITEM_NORMAL );
	file->Append( exit );
	
	m_menubar1->Append( file, wxT("File") ); 
	
	edit = new wxMenu();
	wxMenuItem* clear;
	clear = new wxMenuItem( edit, ID_CLEAR, wxString( wxT("Clear") ) + wxT('\t') + wxT("Ctrl+C"), wxEmptyString, wxITEM_NORMAL );
	edit->Append( clear );
	
	m_menubar1->Append( edit, wxT("Edit") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 4, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxHORIZONTAL );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1 = new wxStaticText( m_panel1, wxID_ANY, wxT("Mode:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer1->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString modeChoices[] = { wxT("Puzzle"), wxT("Mission") };
	int modeNChoices = sizeof( modeChoices ) / sizeof( wxString );
	mode = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, modeNChoices, modeChoices, 0 );
	mode->SetSelection( 0 );
	mode->Enable( false );
	
	fgSizer1->Add( mode, 1, wxALL|wxEXPAND, 5 );
	
	linesText = new wxStaticText( m_panel1, wxID_ANY, wxT("Lines:"), wxDefaultPosition, wxDefaultSize, 0 );
	linesText->Wrap( -1 );
	linesText->Hide();
	
	fgSizer1->Add( linesText, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	lines = new wxSpinCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 11, 1000, 11 );
	lines->Hide();
	
	fgSizer1->Add( lines, 1, wxALL|wxEXPAND, 5 );
	
	startingLinesText = new wxStaticText( m_panel1, wxID_ANY, wxT("Starting Lines"), wxDefaultPosition, wxDefaultSize, 0 );
	startingLinesText->Wrap( -1 );
	startingLinesText->Hide();
	
	fgSizer1->Add( startingLinesText, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	startingLines = new wxSpinCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 11, 11 );
	startingLines->Hide();
	
	fgSizer1->Add( startingLines, 0, wxALL, 5 );
	
	m_staticText3 = new wxStaticText( m_panel1, wxID_ANY, wxT("Moves:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer1->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	moves = new wxSpinCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 1000000, 0 );
	fgSizer1->Add( moves, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer3->Add( fgSizer1, 0, 0, 5 );
	
	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 5, 2, 0, 0 );
	
	m_bpButton1 = new wxBitmapToggleButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer2->Add( m_bpButton1, 0, wxALL, 5 );
	
	m_bpButton2 = new wxBitmapToggleButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer2->Add( m_bpButton2, 0, wxALL, 5 );
	
	m_bpButton3 = new wxBitmapToggleButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer2->Add( m_bpButton3, 0, wxALL, 5 );
	
	m_bpButton4 = new wxBitmapToggleButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer2->Add( m_bpButton4, 0, wxALL, 5 );
	
	m_bpButton5 = new wxBitmapToggleButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer2->Add( m_bpButton5, 0, wxALL, 5 );
	
	m_bpButton6 = new wxBitmapToggleButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer2->Add( m_bpButton6, 0, wxALL, 5 );
	
	m_bpButton7 = new wxBitmapToggleButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer2->Add( m_bpButton7, 0, wxALL, 5 );
	
	m_bpButton8 = new wxBitmapToggleButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer2->Add( m_bpButton8, 0, wxALL, 5 );
	
	m_bpButton9 = new wxBitmapToggleButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer2->Add( m_bpButton9, 0, wxALL, 5 );
	
	
	bSizer3->Add( gSizer2, 0, 0, 5 );
	
	
	bSizer2->Add( bSizer3, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	panel_display = new PanelDisplay( m_panel1, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	panel_display->SetMinSize( wxSize( 128,192 ) );
	
	bSizer4->Add( panel_display, 1, wxALL, 5 );
	
	
	bSizer2->Add( bSizer4, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_panel3 = new wxPanel( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer5->Add( m_panel3, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer2->Add( bSizer5, 1, wxEXPAND, 5 );
	
	
	m_panel1->SetSizer( bSizer2 );
	m_panel1->Layout();
	bSizer2->Fit( m_panel1 );
	bSizer1->Add( m_panel1, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( open->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BBBGui::OnLoad ) );
	this->Connect( save->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BBBGui::OnSave ) );
	this->Connect( exit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BBBGui::OnExit ) );
	this->Connect( clear->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BBBGui::OnClear ) );
	mode->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BBBGui::OnSetMode ), NULL, this );
	lines->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BBBGui::OnLinesUpdate ), NULL, this );
	startingLines->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BBBGui::OnStartingLinesUpdate ), NULL, this );
	moves->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BBBGui::OnMovesUpdate ), NULL, this );
}

BBBGui::~BBBGui()
{
	// Disconnect Events
	this->Disconnect( wxID_OPEN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BBBGui::OnLoad ) );
	this->Disconnect( wxID_SAVE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BBBGui::OnSave ) );
	this->Disconnect( wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BBBGui::OnExit ) );
	this->Disconnect( ID_CLEAR, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BBBGui::OnClear ) );
	mode->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BBBGui::OnSetMode ), NULL, this );
	lines->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BBBGui::OnLinesUpdate ), NULL, this );
	startingLines->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BBBGui::OnStartingLinesUpdate ), NULL, this );
	moves->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BBBGui::OnMovesUpdate ), NULL, this );
	
}
