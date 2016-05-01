#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <string>
#include <list>
#include <map>
#include <set>

#include "panel_table.hpp"

struct Move
{
    Move(int mi, int mj) : x(mj), y(mi) {}
    int x;
    int y;
};

struct Solution
{
    Solution() {}
    Solution(const std::list<Move>& m) : moves(m) {}
    std::string str() const;
    std::list<Move> moves;
};

class PuzzlePanelTable
{
public:
    PuzzlePanelTable(const PanelTable& table);
    Panel::Type value(int i, int j) const {return panels[i * width + j];}
    void set(int i, int j, Panel::Type v) {panels[i * width + j] = v;}

    void update_matches(void);
    void swap(int i, int j);

    bool swap_viable(int i, int j) const {return value(i, j) != value(i, j + 1);}

    bool empty(int i, int j) const {return value(i, j) == Panel::Type::EMPTY;}
    bool special(int i, int j) const {return value(i, j) == Panel::Type::SPECIAL;}
    bool normal(int i, int j) const {return !empty(i, j) && !special(i, j);}
    bool is_impossible() const;
    bool is_empty() const;

    std::string str() const;
    friend class PuzzleState;
private:
    std::vector<Panel::Type> panels;
    std::map<Panel::Type, int> numbers;
    int width;
    int height;

    bool vertical(int i, int j);
    bool horizontal(int i, int j);

    std::set<Point> check_horizontal_combo(int i, int j);
    std::set<Point> check_vertical_combo(int i, int j);
};

struct PuzzleState
{
    PuzzleState(const PanelTable& table);
    PuzzleState(const PuzzleState& other, int mi, int mj, int max_moves);
    bool operator<(const PuzzleState& other) const;
    bool is_empty() const;
    bool is_impossible() const;
    bool swap_viable(int i, int j) const {return table.swap_viable(i, j);}
    PuzzleState move(int i, int j) const;
    PuzzlePanelTable table;
    std::list<Move> moves;
    int moves_left;

};

void solve_puzzle(const PanelTable& table, std::vector<Solution>& out);
bool solve_puzzle(const PanelTable& table, Solution& out);

#endif

