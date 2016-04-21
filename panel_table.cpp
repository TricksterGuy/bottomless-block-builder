#include "panel_table.hpp"
#include <list>
#include <cstdlib>
#include <ctime>
#include <cstdio>

PanelTable::PanelTable(int height, int width) : panels(width * (height + 1)), rows(height), columns(width)
{
}

PanelTable::PanelTable(int height, int width, const Panel::Type* data) : panels(width * (height + 1)), rows(height), columns(width)
{
    for (int i = 0; i <= rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            panels[i * columns + j].value = *data++;
        }
    }
}

void PanelTable::lengthen(int lines)
{
    rows = lines;
    panels.resize(lines * columns);
}
