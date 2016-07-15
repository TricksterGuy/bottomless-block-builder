#include "PanelDisplay.hpp"
#include <cstdio>
#include "solver.hpp"
#include "logger.hpp"

extern std::vector<wxBitmap> panelImages;

PanelDisplay::PanelDisplay(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style,
                           const wxString& name) : wxScrolledCanvas(parent, id, pos, size, style, name), table(12, 6)
{
    InfoLog("PanelDisplay");
    Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(PanelDisplay::OnPanelMetadata), NULL, this);
	Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(PanelDisplay::OnPanel), NULL, this);
	Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(PanelDisplay::OnPanel), NULL, this);
	Connect(wxEVT_MOTION, wxMouseEventHandler(PanelDisplay::OnPanel), NULL, this);
	SetVirtualSize(16 * table.width(), 16 * table.height());
	SetClientSize(16 * table.width(), 16 * table.height());
	SetScrollbars(16, 16, table.width(), table.height());
}

PanelDisplay::~PanelDisplay()
{
    InfoLog("~PanelDisplay");
    Disconnect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(PanelDisplay::OnPanelMetadata), NULL, this);
    Disconnect(wxEVT_MOTION, wxMouseEventHandler(PanelDisplay::OnPanel), NULL, this);
	Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(PanelDisplay::OnPanel), NULL, this);
	Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(PanelDisplay::OnPanel), NULL, this);
}

void PanelDisplay::Save(const std::string& filename)
{
    InfoLog("Save");
    table.save(filename);
}

void PanelDisplay::Load(const std::string& filename)
{
    InfoLog("Load");
    table.load(filename);
    Refresh();
}

void PanelDisplay::Clear()
{
    InfoLog("Clear");
    table.clear();
    Refresh();
}

void PanelDisplay::OnDraw(wxDC& dc)
{
    for (int i = 0; i < table.height(); i++)
    {
        for (int j = 0; j < table.width(); j++)
        {
            Panel::Type p = table.value(i, j);
            dc.DrawRectangle(j * 16, i * 16, 16, 16);
            dc.DrawBitmap(panelImages[(int)p], j * 16, i * 16);
        }
    }
}

void PanelDisplay::OnPanel(wxMouseEvent& event)
{
    VerboseLog("OnPanel");
    if (event.Moving() || (event.Dragging() && !event.LeftIsDown()))
        return;

    int x = event.GetX() / 16;
    int y = event.GetY() / 16;
    if (x >= table.width() || y >= table.height())
        return;
    InfoLog("Set (%d %d) to %d", y, x, event.RightIsDown() ? Panel::Type::EMPTY : panel);
    table.set(y, x, event.RightIsDown() ? Panel::Type::EMPTY : panel);
    Refresh();
}

void PanelDisplay::OnPanelMetadata(wxMouseEvent& event)
{
    InfoLog("OnPanelMetadata");
}

void PanelDisplay::SetLines(int lines)
{
    InfoLog("SetLines %d", lines);
    table.lengthen(lines);
    SetScrollbars(16, 16, table.width(), table.height());
    SetVirtualSize(16 * table.width(), 16 * table.height());
    Refresh();
}

bool PanelDisplay::IsSolvable(Solution& s)
{
    return solve_puzzle(table, s);
}

void PanelDisplay::AllSolutions(std::vector<Solution>& solutions)
{
    solve_puzzle(table, solutions);
}
