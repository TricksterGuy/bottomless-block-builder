#ifndef BBBFRAME_HPP
#define BBBFRAME_HPP

#include "BBBGui.h"

class BBBFrame : public BBBGui
{
public:
    BBBFrame();
    ~BBBFrame();
    void OnLoad(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnClear(wxCommandEvent& event);

    void OnSetMode(wxCommandEvent& event);
	void OnLinesUpdate(wxSpinEvent& event);
	void OnStartingLinesUpdate(wxSpinEvent& event);
	void OnMovesUpdate(wxSpinEvent& event);

    void OnPanelChoose(wxCommandEvent& event);
};

#endif
