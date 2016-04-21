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
	
	wxString m_choice1Choices[] = { wxT("Puzzle"), wxT("Mission") };
	int m_choice1NChoices = sizeof( m_choice1Choices ) / sizeof( wxString );
	m_choice1 = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice1NChoices, m_choice1Choices, 0 );
	m_choice1->SetSelection( 0 );
	fgSizer1->Add( m_choice1, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText2 = new wxStaticText( m_panel1, wxID_ANY, wxT("Lines:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer1->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spinCtrl1 = new wxSpinCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 11, 1000, 11 );
	fgSizer1->Add( m_spinCtrl1, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText4 = new wxStaticText( m_panel1, wxID_ANY, wxT("Starting Lines"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer1->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spinCtrl3 = new wxSpinCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 11, 0 );
	fgSizer1->Add( m_spinCtrl3, 0, wxALL, 5 );
	
	m_staticText3 = new wxStaticText( m_panel1, wxID_ANY, wxT("Moves:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer1->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spinCtrl2 = new wxSpinCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 1000000, 0 );
	fgSizer1->Add( m_spinCtrl2, 1, wxALL|wxEXPAND, 5 );
	
	
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
	m_choice1->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BBBGui::OnSetMode ), NULL, this );
	m_spinCtrl1->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BBBGui::OnLinesUpdate ), NULL, this );
}

BBBGui::~BBBGui()
{
	// Disconnect Events
	m_choice1->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BBBGui::OnSetMode ), NULL, this );
	m_spinCtrl1->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BBBGui::OnLinesUpdate ), NULL, this );
	
}
