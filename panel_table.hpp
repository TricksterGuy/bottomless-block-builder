#ifndef PANEL_TABLE_HPP
#define PANEL_TABLE_HPP

#include "panel.hpp"
#include <list>
#include <set>
#include <vector>

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
    /** Chains are rapidlying matching 3 or more blocks before they disappear */
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

class PanelTable
{
public:
    PanelTable(int rows, int columns);
    PanelTable(int rows, int columns, const Panel::Type* data);

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

private:
    std::vector<Panel> panels;
    int rows;
    int columns;
};

#endif
