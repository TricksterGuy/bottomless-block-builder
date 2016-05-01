#include "panel_table.hpp"
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <list>
#include <fstream>

struct BasicPuzzle
{
    char magic[4];
    char version[2];
    char type;
    char pad1;
    int rows;
    int columns;
    int starting;
    int moves;
    char panels[66];
    char pad2[6];
};

PanelTable::PanelTable(int height, int width) : panels(width * height), rows(height), columns(width), starting_lines(11), moves(1)
{
}

void PanelTable::lengthen(int lines)
{
    rows = lines;
    panels.resize(lines * columns);
}

void PanelTable::save(const std::string& filename)
{
    std::ofstream file(filename.c_str(), std::ios::binary);
    save_puzzle(file);
}

void PanelTable::save_puzzle(std::ofstream& file)
{
    BasicPuzzle puzzle;
    puzzle.magic[0] = puzzle.magic[1] = puzzle.magic[2] = 'B';
    puzzle.magic[3] = 0;
    puzzle.version[0] = VERSION_MAJOR;
    puzzle.version[1] = VERSION_MINOR;
    puzzle.type = type;
    puzzle.pad1 = 0;
    puzzle.rows = rows;
    puzzle.columns = columns;
    puzzle.starting = starting_lines;
    puzzle.moves = moves;
    for (unsigned int i = 0; i < panels.size(); i++)
        puzzle.panels[i] = panels[i].value;

    file.write(reinterpret_cast<char*>(&puzzle), sizeof(BasicPuzzle));
    file.close();
}

void PanelTable::load(const std::string& filename)
{
    std::ifstream file(filename.c_str(), std::ios::binary);
    load_puzzle(file);
}

void PanelTable::load_puzzle(std::ifstream& file)
{
    BasicPuzzle puzzle;
    file.read(reinterpret_cast<char*>(&puzzle), sizeof(puzzle));
    file.close();

    char* magic = puzzle.magic;
    if (!(magic[0] == 'B' && magic[1] == 'B' && magic[2] == 'B' && magic[3] == 0))
        return;

    char* version = puzzle.version;
    if (version[0] > VERSION_MAJOR || (version[0] == VERSION_MAJOR && version[1] > VERSION_MINOR))
        return;

    if (puzzle.type != PUZZLE)
        return;

    if (puzzle.rows != MAX_PUZZLE_ROWS || puzzle.columns != MAX_PUZZLE_COLUMNS || puzzle.starting != MAX_PUZZLE_ROWS ||
        puzzle.moves > MAX_PUZZLE_MOVES)
        return;

    type = puzzle.type;
    rows = puzzle.rows;
    columns = puzzle.columns;
    starting_lines = puzzle.starting;
    moves = puzzle.moves;

    panels.resize(columns * rows);
    for (unsigned int i = 0; i < panels.size(); i++)
        panels[i].value = (Panel::Type) puzzle.panels[i];
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
