#ifndef PANEL_DISPLAY_HPP
#define PANEL_DISPLAY_HPP

#include <wx/scrolwin.h>
#include <wx/dc.h>
#include "panel_table.hpp"
#include <vector>

class PanelDisplay : public wxScrolledCanvas
{
public:
    PanelDisplay(wxWindow *parent, wxWindowID id=wxID_ANY, const wxPoint &pos=wxDefaultPosition,
                 const wxSize &size=wxDefaultSize, long style=wxTAB_TRAVERSAL, const wxString &name=wxPanelNameStr);
    ~PanelDisplay();

    void OnDraw(wxDC& dc);
    void OnPanelMetadata(wxMouseEvent& event);
    void OnPanel(wxMouseEvent& event);

    void SetCurrentPanel(Panel::Type p) {panel = p;}

    void SetLines(int lines);
    void SetStartingLines(int startingLines) {table.set_starting_lines(startingLines);}
    void SetMoves(int moves) {table.set_moves(moves);}

    int GetLines() const {return table.height();}
    int GetStartingLines() const {return table.get_starting_lines();}
    int GetMoves() const {return table.get_moves();}

    void Save(const std::string& filename);
    void Load(const std::string& filename);
    void Clear();

private:
    std::vector<wxBitmap> panels;
    PanelTable table;
    Panel::Type panel;
};

#endif
