///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 25 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __BBBGUI_H__
#define __BBBGUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
class PanelDisplay;
class wxBitmapToggleButton;

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/bmpbuttn.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define ID_CLEAR 1000

///////////////////////////////////////////////////////////////////////////////
/// Class BBBGui
///////////////////////////////////////////////////////////////////////////////
class BBBGui : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* m_menubar1;
		wxMenu* file;
		wxMenu* edit;
		wxPanel* m_panel1;
		wxStaticText* m_staticText1;
		wxChoice* mode;
		wxStaticText* m_staticText2;
		wxSpinCtrl* moves;
		wxStaticText* linesText;
		wxSpinCtrl* lines;
		wxStaticText* startingLinesText;
		wxSpinCtrl* startingLines;
		wxButton* m_button1;
		wxButton* m_button2;
		PanelDisplay* panel_display;
		wxBitmapToggleButton* m_bpButton1;
		wxBitmapToggleButton* m_bpButton2;
		wxBitmapToggleButton* m_bpButton3;
		wxBitmapToggleButton* m_bpButton4;
		wxBitmapToggleButton* m_bpButton5;
		wxBitmapToggleButton* m_bpButton6;
		wxBitmapToggleButton* m_bpButton7;
		wxBitmapToggleButton* m_bpButton8;
		wxBitmapToggleButton* m_bpButton9;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClear( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSetMode( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMovesUpdate( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnLinesUpdate( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnStartingLinesUpdate( wxSpinEvent& event ) { event.Skip(); }
		virtual void IsSolvable( wxCommandEvent& event ) { event.Skip(); }
		virtual void AllSolutions( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		BBBGui( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Bottomless Block Builder"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,288 ), long style = wxCAPTION|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxSYSTEM_MENU|wxTAB_TRAVERSAL );
		
		~BBBGui();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SolutionsGui
///////////////////////////////////////////////////////////////////////////////
class SolutionsGui : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText6;
		wxSpinCtrl* solution_choice;
		wxTextCtrl* solution_text;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnUpdateSolution( wxSpinEvent& event ) { event.Skip(); }
		
	
	public:
		
		SolutionsGui( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Solutions"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 160,240 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~SolutionsGui();
	
};

#endif //__BBBGUI_H__
