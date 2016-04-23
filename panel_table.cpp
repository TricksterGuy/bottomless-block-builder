#include "panel_table.hpp"
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <list>
#include <fstream>

PanelTable::PanelTable(int height, int width) : panels(width * height), rows(height), columns(width), starting_lines(11), moves(1)
{
}

PanelTable::PanelTable(int height, int width, const Panel::Type* data) : panels(width * height), rows(height), columns(width), starting_lines(11), moves(1)
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

void PanelTable::save(const std::string& filename)
{
    std::ofstream file(filename.c_str(), std::ios::binary);
    const std::string& header = "BBB";
    file.write(header.c_str(), sizeof(char) * 4);
    const char version[2] = {VERSION_MAJOR, VERSION_MINOR};
    file.write(version, sizeof(version));
    file.write(&type, sizeof(type));
    file.write(reinterpret_cast<char*>(&rows), sizeof(rows));
    file.write(reinterpret_cast<char*>(&columns), sizeof(columns));
    file.write(reinterpret_cast<char*>(&starting_lines), sizeof(starting_lines));
    file.write(reinterpret_cast<char*>(&moves), sizeof(moves));
    char* buffer = new char[columns * rows];
    for (unsigned int i = 0; i < panels.size(); i++)
        buffer[i] = panels[i].value;
    file.write(buffer, columns * rows);
    delete[] buffer;
    file.close();
}

void PanelTable::load(const std::string& filename)
{
    std::ifstream file(filename.c_str(), std::ios::binary);
    char magic[4];
    file.read(magic, sizeof(magic));
    if (!(magic[0] == 'B' && magic[1] == 'B' && magic[2] == 'B' && magic[3] == 0))
    {
        file.close();
        return;
    }
    char version[2];
    file.read(version, sizeof(version));
    if (version[0] > VERSION_MAJOR || (version[0] == VERSION_MAJOR && version[1] > VERSION_MINOR))
    {
        file.close();
        return;
    }
    file.read(&type, sizeof(type));
    file.read(reinterpret_cast<char*>(&rows), sizeof(rows));
    file.read(reinterpret_cast<char*>(&columns), sizeof(columns));
    file.read(reinterpret_cast<char*>(&starting_lines), sizeof(starting_lines));
    file.read(reinterpret_cast<char*>(&moves), sizeof(moves));
    if (rows > 1000 || columns > 6)
    {
        file.close();
        return;
    }
    char* buffer = new char[columns * rows];
    file.read(buffer, columns * rows);
    panels.resize(columns * rows);
    for (unsigned int i = 0; i < panels.size(); i++)
        panels[i].value = (Panel::Type)buffer[i];
    delete[] buffer;
    file.close();
}

void PanelTable::clear()
{
    for (int i = 0; i <= rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            panels[i * columns + j].value = Panel::Type::EMPTY;
        }
    }
}
