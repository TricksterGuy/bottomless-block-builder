#include "BBBFrame.hpp"
#include "PanelDisplay.hpp"
#include <wx/tglbtn.h>
#include <wx/filedlg.h>
#include <cstdio>

extern std::vector<wxBitmap> panelImages;

BBBFrame::BBBFrame() : BBBGui(NULL)
{
    m_bpButton1->SetBitmap(panelImages[1]);
    m_bpButton2->SetBitmap(panelImages[2]);
    m_bpButton3->SetBitmap(panelImages[3]);
    m_bpButton4->SetBitmap(panelImages[4]);
    m_bpButton5->SetBitmap(panelImages[5]);
    m_bpButton6->SetBitmap(panelImages[6]);
    m_bpButton7->SetBitmap(panelImages[7]);
    m_bpButton8->SetBitmap(panelImages[8]);
    m_bpButton9->SetBitmap(panelImages[0]);

	m_bpButton1->Connect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);
	m_bpButton2->Connect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);
	m_bpButton3->Connect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);
	m_bpButton4->Connect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);
	m_bpButton5->Connect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);
	m_bpButton6->Connect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);
	m_bpButton7->Connect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);
	m_bpButton8->Connect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);
	m_bpButton9->Connect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);

	m_bpButton9->SetValue(true);
}

BBBFrame::~BBBFrame()
{
	m_bpButton1->Disconnect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);
	m_bpButton2->Disconnect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);
	m_bpButton3->Disconnect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);
	m_bpButton4->Disconnect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);
	m_bpButton5->Disconnect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);
	m_bpButton6->Disconnect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);
	m_bpButton7->Disconnect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);
	m_bpButton8->Disconnect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);
	m_bpButton9->Disconnect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);
	m_bpButton9->Disconnect(wxEVT_TOGGLEBUTTON, wxCommandEventHandler(BBBFrame::OnPanelChoose), NULL, this);
}

void BBBFrame::OnExit(wxCommandEvent& event)
{
    Destroy();
}

void BBBFrame::OnLoad(wxCommandEvent& event)
{
    wxFileDialog* dialog = new wxFileDialog(NULL, _("Load .bbb file"), wxEmptyString, wxEmptyString, _("BBB puzzle files (*.bbb)|*.bbb"), wxFD_OPEN|wxFD_FILE_MUST_EXIST|wxFD_CHANGE_DIR);
    if (dialog->ShowModal() == wxID_OK)
    {
        panel_display->Load(dialog->GetPath().ToStdString());
        moves->SetValue(panel_display->GetMoves());
        startingLines->SetValue(panel_display->GetStartingLines());
        lines->SetValue(panel_display->GetLines());
    }
}

void BBBFrame::OnSave(wxCommandEvent& event)
{
    wxFileDialog* dialog = new wxFileDialog(NULL, _("Save .bbb file"), wxEmptyString, wxEmptyString, _("BBB puzzle files (*.bbb)|*.bbb"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT|wxFD_CHANGE_DIR);
    if (dialog->ShowModal() == wxID_OK)
        panel_display->Save(dialog->GetPath().ToStdString());
}

void BBBFrame::OnClear(wxCommandEvent& event)
{
    panel_display->Clear();
}

void BBBFrame::OnSetMode(wxCommandEvent& event)
{
    if (event.GetSelection() == 0)
    {
        lines->Hide();
        linesText->Hide();
        startingLines->Hide();
        startingLinesText->Hide();
        lines->SetValue(11);
        startingLines->SetValue(11);
    }
    else
    {
        lines->Show();
        linesText->Show();
        startingLines->Show();
        startingLinesText->Show();
    }
}

void BBBFrame::OnLinesUpdate(wxSpinEvent& event)
{
    panel_display->SetLines(event.GetValue());
}

void BBBFrame::OnStartingLinesUpdate(wxSpinEvent& event)
{
    panel_display->SetStartingLines(event.GetValue());
}

void BBBFrame::OnMovesUpdate(wxSpinEvent& event)
{
    panel_display->SetMoves(event.GetValue());
}

void BBBFrame::OnPanelChoose(wxCommandEvent& event)
{
    m_bpButton1->SetValue(false);
    m_bpButton2->SetValue(false);
    m_bpButton3->SetValue(false);
    m_bpButton4->SetValue(false);
    m_bpButton5->SetValue(false);
    m_bpButton6->SetValue(false);
    m_bpButton7->SetValue(false);
    m_bpButton8->SetValue(false);
    m_bpButton9->SetValue(false);

    wxBitmapToggleButton* btn = dynamic_cast<wxBitmapToggleButton*>(event.GetEventObject());
    assert(btn != NULL);
    btn->SetValue(true);

    int panel = 0;
    if (btn == m_bpButton1)
        panel = 1;
    else if (btn == m_bpButton2)
        panel = 2;
    else if (btn == m_bpButton3)
        panel = 3;
    else if (btn == m_bpButton4)
        panel = 4;
    else if (btn == m_bpButton5)
        panel = 5;
    else if (btn == m_bpButton6)
        panel = 6;
    else if (btn == m_bpButton7)
        panel = 7;
    else if (btn == m_bpButton8)
        panel = 8;
    else if (btn == m_bpButton9)
        panel = 0;

    panel_display->SetCurrentPanel((Panel::Type)panel);
}
