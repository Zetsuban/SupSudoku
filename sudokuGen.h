#include <set>
#include <deque>
#include <memory>
#include <sstream>

struct coord {
    int x = 0;
    int y = 0;
};

class Cell {
public:
    coord                   pos;
    std::set<coord>         neighbors{};
    int                     value = 0;
    int                     oldValue = 0;

    void                    setChange( bool chg );
    bool                    getChange();
    void                    setPosition( coord pos );
    void                    getNeighbors();
    Cell() {}

private:
    bool                    canChange;
};

using cellQueu = std::deque<std::shared_ptr<Cell>>;

class SudokuBoard {
    cellQueu cells;

public:
    void                    doGenSudoku();
    void                    Puzzled();
    void                    display();
    void                    turn( coord pos );
    bool                    completed();
    bool                    win();
    std::string             parser();
    SudokuBoard();

private:
    std::shared_ptr<Cell>   at( int index );
    std::shared_ptr<Cell>   at( coord pos );
    bool                    genSudoku( int index );
    bool                    checkSudoku( int index );
};

SudokuBoard genBoard();