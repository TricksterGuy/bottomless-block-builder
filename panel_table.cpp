#include "panel_table.hpp"
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <list>
#include <fstream>
#include "logger.hpp"



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
    char panels[72];
};

void load_version_1_0(const BasicPuzzle& puzzle, PanelTable& table)
{
    // Version 1.0 had 11x6 board for puzzle mode with 6 extra padding bytes which contain junk.
    table.type = puzzle.type;
    table.rows = 12;
    table.columns = puzzle.columns;
    table.starting_lines = 12;
    table.moves = puzzle.moves;

    table.panels.resize(table.columns * table.rows);
    for (unsigned int i = 0; i < table.panels.size(); i++)
        table.panels[i].value = (int)i < table.columns ? Panel::EMPTY : (Panel::Type) puzzle.panels[i - table.columns];

}

PanelTable::PanelTable(int height, int width) : panels(width * height), rows(height), columns(width), starting_lines(12), moves(1)
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
    if (!file.good())
    {
        ErrorLog("Could not open file %s", filename.c_str());
        return;
    }
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
    if (!file.good())
    {
        ErrorLog("Could not open file %s", filename.c_str());
        return;
    }
    load_puzzle(file);
}

void PanelTable::load_puzzle(std::ifstream& file)
{
    BasicPuzzle puzzle;
    file.read(reinterpret_cast<char*>(&puzzle), sizeof(puzzle));
    file.close();

    char* magic = puzzle.magic;
    if (!(magic[0] == 'B' && magic[1] == 'B' && magic[2] == 'B' && magic[3] == 0))
    {
        ErrorLog("Invalid File");
        return;
    }

    char* version = puzzle.version;
    if (version[0] > VERSION_MAJOR || (version[0] == VERSION_MAJOR && version[1] > VERSION_MINOR))
    {
        ErrorLog("Version %d.%d is not supported", version[0], version[1]);
        return;
    }

    InfoLog("Version %d.%d found", version[0], version[1]);

    if (puzzle.type != PUZZLE)
    {
        ErrorLog("Invalid File");
        return;
    }

    if (puzzle.rows > MAX_PUZZLE_ROWS || puzzle.columns > MAX_PUZZLE_COLUMNS || puzzle.starting > MAX_PUZZLE_ROWS ||
        puzzle.moves > MAX_PUZZLE_MOVES)
    {
        ErrorLog("Puzzle too big can only be (%d %d) moves: %d found (%d(%d) %d %d)", MAX_PUZZLE_ROWS, MAX_PUZZLE_COLUMNS, MAX_PUZZLE_MOVES,
                 puzzle.rows, puzzle.starting, puzzle.columns, puzzle.moves);
        return;
    }

    if (version[0] == 1 && version[1] == 0)
    {
        InfoLog("Found version 1.0 file");
        load_version_1_0(puzzle, *this);
        return;
    }

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
