#include "solver.hpp"
#include <sstream>
#include <queue>

std::string Solution::str() const
{
    std::stringstream oss;
    for (const auto& move : moves)
        oss << "(" << move.y << "," << move.x << ")\n";
    return oss.str();
}

PuzzlePanelTable::PuzzlePanelTable(const PanelTable& table)
{
    width = table.columns;
    height = table.rows;
    for (const auto& panel : table.panels)
    {
        panels.push_back(panel.value);
        if (panel.normal())
            numbers[panel.value] += 1;
    }
}

bool PuzzlePanelTable::is_impossible() const
{
    for (const auto& panel_value : numbers)
    {
        if (panel_value.second == 2 || panel_value.second == 1)
            return true;
    }
    return false;
}

bool PuzzlePanelTable::is_empty() const
{
    if (numbers.empty()) return true;
    for (const auto& panel_value : numbers)
    {
        if (panel_value.second != 0)
            return false;
    }
    return true;
}


void PuzzlePanelTable::update_matches(void)
{
    MatchInfo match_info;
    std::set<Point> remove;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (horizontal(i, j))
            {
                std::set<Point> horiz = check_horizontal_combo(i, j);
                remove.insert(horiz.begin(), horiz.end());
            }
            if (vertical(i, j))
            {
                std::set<Point> vert = check_vertical_combo(i, j);
                remove.insert(vert.begin(), vert.end());
            }
        }
    }

    for (const auto& pt : remove)
    {
        numbers[value(pt.y, pt.x)] -= 1;
        set(pt.y, pt.x, Panel::Type::EMPTY);
    }

    if (!remove.empty())
    {
        for (int j = 0; j < width; j++)
        {
            std::list<Panel::Type> temp;
            for (int i = height - 1; i >= 0; i--)
            {
                Panel::Type panel = value(i, j);
                if (panel != Panel::Type::EMPTY)
                    temp.push_back(panel);
            }

            int i = height - 1;
            for (const auto& panel : temp)
                set(i, j, panel);
        }
    }
}

void PuzzlePanelTable::swap(int i, int j)
{
    Panel::Type temp = panels[i * width + j];
    panels[i * width + j] = panels[i * width + j + 1];
    panels[i * width + j + 1] = temp;
}

bool PuzzlePanelTable::vertical(int i, int j)
{
    if (i > height - 3)
        return false;

    if (empty(i, j) || special(i, j))
        return false;

    Panel::Type k, l, m;
    k = value(i, j);
    l = value(i + 1, j);
    m = value(i + 2, j);

    return k == l && k == m;
}

bool PuzzlePanelTable::horizontal(int i, int j)
{
    if (j > width - 3)
        return false;

    if (empty(i, j) || special(i, j))
        return false;

    Panel::Type k, l, m;
    k = value(i, j);
    l = value(i, j + 1);
    m = value(i, j + 2);

    return k == l && k == m;
}

std::set<Point> PuzzlePanelTable::check_horizontal_combo(int i, int j)
{
    std::set<Point> remove;
    int moveon = 3;

    remove.emplace(j, i);
    remove.emplace(j + 1, i);
    remove.emplace(j + 2, i);

    for (int k = 3; k < width - j - 1; k++)
    {
        if (!(j + k < width && value(i, j) == value(i, j + k)))
            break;

        moveon = k + 1;
        remove.emplace(j + k, i);
    }

    for (int m = 0; m < moveon; m++)
    {
        for (int k = -2; k <= 1; k++)
        {
            if (k == 0)
                continue;

            int l = k == -1 ? 1 : k + 1;
            Panel::Type panel = value(i, j);
            if (i + k >= 0 && i + l < height && panel == value(i + k, j + m) && panel == value(i + l, j + m))
            {
                remove.emplace(j + m, i + k);
                remove.emplace(j + m, i + l);
            }
        }
    }

    return remove;
}

std::set<Point> PuzzlePanelTable::check_vertical_combo(int i, int j)
{
    std::set<Point> remove;
    int moveon = 3;

    remove.emplace(j, i);
    remove.emplace(j, i + 1);
    remove.emplace(j, i + 2);

    for (int k = 3; k < height - i - 1; k++)
    {
        if (!(i + k < height && value(i, j) == value(i + k, j)))
            break;

        moveon = k + 1;
        remove.emplace(j, i + k);
    }

    for (int m = 0; m < moveon; m++)
    {
        for (int k = -2; k <= 1; k++)
        {
            if (k == 0)
                continue;
            int l = k == -1 ? 1 : k + 1;
            Panel::Type panel = value(i, j);
            if (j + k >= 0 && j + l < width && panel == value(i + m, j + k) && panel == value(i + m, j + l))
            {
                remove.emplace(j + k, i + m);
                remove.emplace(j + l, i + m);
            }
        }
    }

    return remove;
}

PuzzleState::PuzzleState(const PanelTable& ptable) : table(ptable), moves_left(ptable.get_moves())
{

}

PuzzleState::PuzzleState(const PuzzleState& other, int mi, int mj, int max_moves) : table(other.table), moves_left(max_moves)
{
    table.swap(mi, mj);
    table.update_matches();
    moves.emplace_back(mi, mj);
}

bool PuzzleState::operator<(const PuzzleState& other) const
{
    return moves_left < other.moves_left;
}

bool PuzzleState::is_empty() const
{
    return table.is_empty();
}

bool PuzzleState::is_impossible() const
{
    return table.is_impossible();
}

PuzzleState PuzzleState::move(int i, int j) const
{
    return PuzzleState(*this, i, j, moves_left - 1);
}

/*  def evaluate_board
    queue = []

    queue << @table.data
    queue << @table.numbers
    queue << []
    size = 1

    @moves.times do |k|
      size.times do
        data = queue.shift
        numbers = queue.shift
        made = queue.shift
        11.downto(@top) do |i|
          5.times do |j|
            unless (data[i][j] != nil or data[i][j + 1] != nil) and data[i][j] != data[i][j + 1]
              next
            end

            @table.data = data.dclone
            @table.numbers = numbers.dup

            move = Move.new([i, j], [@table[i, j], @table[i, j + 1]])
            @table.switch(i, j)
            @table.stack_down(i, j)
            @table.stack_down(i, j + 1)
            @table.update_matches
            #trim time

            if trim(made, move)
              move_made = made + [move]
              if @table.empty?
                @solutions << Solution.new(move_made)
              elsif !@table.impossible?
                queue << @table.data
                queue << @table.numbers
                queue << move_made
              end
              if @number != nil and @solutions.size >= @number
                return
              end
            end
          end
        end
      end
      size = queue.size / 3
    end
  end
*/

std::vector<Solution> solve_puzzle(const PanelTable& table, int max_moves)
{

}

bool solve_puzzle(const PanelTable& table, Solution& out)
{
    std::priority_queue<PuzzleState> queue;
    queue.push(PuzzleState(table));

    while (!queue.empty())
    {
        PuzzleState state = queue.top();
        if (state.is_empty())
        {
            out.moves = state.moves;
            return true;
        }
        if (state.is_impossible() || state.moves_left == 0)
        {
            queue.pop();
            continue;
        }
        for (int i = 10; i >= 0; i--)
        {
            for (int j = 0; j < 5; j++)
            {
                if (state.swap_viable(i, j))
                {
                    queue.push(state.move(i, j));
                }
            }
        }
        queue.pop();
    }

    return false;
}
