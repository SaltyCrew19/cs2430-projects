//Simulation.h
#pragma once
#include <vector>
#include <string>
#include "Console.h"
#include "Board.h"
#include "Player.h"
#include "Deck.h"


class Simulation
{
private:
    Console sys;
    Deck chance;
    Deck communityChest;
    Board board;
    int currentPlayerInt;
    std::vector<Player> players;

public:
    Simulation();
    void run();
    void nextTurn();

    ~Simulation();
};
