#include <iostream>
#include "Console.h"
#include "Board.h"

int main(int, char**)
{
    Console sys = Console("MonopolySimulation");
    sys.intro();

    Board board = Board();
    
    // board.printBoard();
}
