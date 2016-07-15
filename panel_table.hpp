#ifndef PANEL_TABLE_HPP
#define PANEL_TABLE_HPP

#include <fstream>
#include <vector>

#define VERSION_MAJOR 1
#define VERSION_MINOR 1

#define MAX_PUZZLE_ROWS 12
#define MAX_PUZZLE_COLUMNS 6
#define MAX_PUZZLE_MOVES 1000000

class PuzzlePanelTable;

struct Point
{
    Point(int j, int i) : x(j), y(i) {}
    bool operator<(const Point& p) const {return (y != p.y) ? y > p.y : x < p.x;}
    bool operator==(const Point& p) const {return x == p.x && y == p.y;}
    int x;
    int y;
};

struct MatchInfo
{
    MatchInfo() : chain(0), cascade(0), combo(0), swap_match(false), fall_match(false) {}
    /** Chains are rapidly matching 3 or more blocks before they disappear */
    int chain;
    /** Cascades are sequential matches after blocks are removed */
    int cascade;
    /** Combos are matches of more than 3 blocks */
    int combo;
    /** If any panels was in state IDLE then this will be true (part of a chain) */
    bool swap_match;
    /** If any panels was in state END_FALL this will be true (part of a cascade) */
    bool fall_match;
};

struct BasicPuzzle;

class Panel
{
public:
    enum Type
    {
        EMPTY = 0,
        GREEN = 1,
        PURPLE = 2,
        RED = 3,
        YELLOW = 4,
        CYAN = 5,
        BLUE = 6,
        SILVER = 7,
        SPECIAL = 8,
    };

    bool empty() const {return value == EMPTY;}
    bool normal() const {return !empty() && !special();}
    bool special() const {return value == SPECIAL;}

    Type value = EMPTY;
    unsigned int modifiers = 0;
};

class PanelTable
{
public:
    enum Type
    {
        PUZZLE = 0,
        MISSION = 1,
    };
    PanelTable(int rows, int columns);

    int width() const {return columns;}
    int height() const {return rows;}
    Panel& get(int i, int j) {return panels[i * columns + j];}
    const Panel& get(int i, int j) const {return panels[i * columns + j];}
    void set(int i, int j, Panel::Type value) {panels[i * columns + j].value = value;}
    Panel::Type value(int i, int j) const {return get(i, j).value;}

    bool empty(int i, int j) const {return get(i, j).empty();}
    bool special(int i, int j) const {return get(i, j).special();}
    bool normal(int i, int j) const {return get(i, j).normal();}

    void lengthen(int lines);
    void save(const std::string& filename);
    void load(const std::string& filename);
    void clear();

    void set_starting_lines(int starting) {starting_lines = starting;}
    void set_moves(int m) {moves = m;}
    int get_starting_lines() const {return starting_lines;}
    int get_moves() const {return moves;}

    friend class PuzzlePanelTable;
    friend void load_version_1_0(const BasicPuzzle& puzzle, PanelTable& table);
private:
    void load_puzzle(std::ifstream& file);
    void save_puzzle(std::ofstream& file);

    std::vector<Panel> panels;
    char type;
    int rows;
    int columns;
    int starting_lines;
    int moves;
};

#endif
