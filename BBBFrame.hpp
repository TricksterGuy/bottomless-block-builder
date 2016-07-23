#ifndef BBBFRAME_HPP
#define BBBFRAME_HPP

#include <vector>
#include "BBBGui.h"
#include "solver.hpp"

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

    void IsSolvable(wxCommandEvent& event);
	void AllSolutions(wxCommandEvent& event);
};


class SolutionsDialog : public SolutionsGui
{
	public:
		SolutionsDialog(std::vector<Solution>& s);
		~SolutionsDialog() {}
		void OnUpdateSolution(wxSpinEvent& event);
		void DoUpdateSolution(int index);
    private:
        std::vector<Solution>& solutions;
};
#endif
