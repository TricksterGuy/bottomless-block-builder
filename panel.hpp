#ifndef PANEL_HPP
#define PANEL_HPP

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

#endif
