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


    //methods
    void nextTurn();
    void movePlayer(Player player, int pos);
    int roll();
public:
    Simulation();
    void run();

    void doInJailActions(Player& currentPlayer, const int& die1, const int& die2);

    std::vector<Card> buildCommunityChest();
    std::vector<Card> buildChance();
    std::vector<Player> buildPlayers();

    ~Simulation();
};
