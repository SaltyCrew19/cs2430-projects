//Board.h
#include <vector>
#include <memory>
#include <sstream>
#include "Console.h"
//square's
#include "Square.h"
#include "PropertySquare.h"
#include "TaxSquare.h"
#include "RailroadSquare.h"
#include "UtilitySquare.h"

class Board
{
private:
    std::vector<std::unique_ptr<Square>> board;
    Console sys;

    void initBoard();
public:
    Board();

    void printBoard();
    ~Board();
};