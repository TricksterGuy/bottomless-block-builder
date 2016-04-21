#ifndef BBBFRAME_HPP
#define BBBFRAME_HPP

#include "BBBGui.h"

class BBBFrame : public BBBGui
{
public:
    BBBFrame();
    ~BBBFrame();
    void OnSetMode(wxCommandEvent& event);
	void OnLinesUpdate(wxSpinEvent& event);
    void OnPanelChoose(wxCommandEvent& event);
};

#endif
