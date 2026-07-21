//Simulation.cpp
#include <sstream>
#include "Simulation.h"

Simulation::Simulation() : sys(Console("Simulation")),chance(buildChance()),communityChest(buildCommunityChest()),players(buildPlayers())
{
    sys.print("Constructing Chance and Community Chest Decks");
    chance.shuffle();
    communityChest.shuffle();
}

void Simulation::nextTurn()
{
    Player& currentPlayer = players[currentPlayerInt];
    int die1 = roll();
    int die2 = roll();
    int currentPlayerPos = currentPlayer.pos;
    int playerNextPos = currentPlayerPos + die1 + die2;
    if(currentPlayer.doublesCount >= 3){currentPlayer.pos == 10; currentPlayer.doublesCount = 0;} //jailed
    else if(die1 == die2){currentPlayer.doublesCount++;}
    else{currentPlayer.doublesCount = 0;}
    


    if (currentPlayerInt+1 > players.size()-1){currentPlayerInt = 0;}
    else{currentPlayerInt++;}
}

int Simulation::roll()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int > dist(1,6);

    return dist(gen);
}

Simulation::~Simulation(){}

std::vector<Card> Simulation::buildCommunityChest()
{
    std::vector<Card> chest
    {
        {"Advance to GO (Collect $200)", CardEffect::MoveToGo, 0, 0},
        {"Bank error in your favor: Collect $200", CardEffect::CollectMoney, 200, 0},
        {"Doctor's fee: Pay $50", CardEffect::PayMoney, 50, 0},
        {"From sale of stock you get $50", CardEffect::CollectMoney, 50, 0},
        {"Get Out of Jail Free", CardEffect::GetOutOfJailFree, 0, 0},
        {"Go to Jail", CardEffect::GoToJail, 0, 0},
        {"Grand Opera Night: Collect $50 from every player", CardEffect::CollectFromEachPlayer, 50, 0},
        {"Holiday Fund matures: Receive $100", CardEffect::CollectMoney, 100, 0},
        {"Income tax refund: Collect $20", CardEffect::CollectMoney, 20, 0},
        {"It is your birthday: Collect $10 from every player", CardEffect::CollectFromEachPlayer, 10, 0},
        {"Life insurance matures: Collect $100", CardEffect::CollectMoney, 100, 0},
        {"Pay hospital fees of $100", CardEffect::PayMoney, 100, 0},
        {"Pay school fees of $50", CardEffect::PayMoney, 50, 0},
        {"Receive $25 consultancy fee", CardEffect::CollectMoney, 25, 0},
        {"You are assessed for street repairs: Pay $40 per house, $115 per hotel", CardEffect::PayPerBuilding, 40, 115},
        {"You have won second prize in a beauty contest: Collect $10", CardEffect::CollectMoney, 10, 0}
    };
    return chest;
}

std::vector<Card> Simulation::buildChance()
{
    std::vector<Card> chance
    {
        {"Advance to GO (Collect $200)", CardEffect::MoveToGo, 0, 0},
        {"Advance to Illinois Ave.", CardEffect::MoveToSquare, 24, 0},
        {"Advance to St. Charles Place", CardEffect::MoveToSquare, 11, 0},
        {"Advance to nearest Utility", CardEffect::MoveToNearestUtility, 0, 0},
        {"Advance to nearest Railroad", CardEffect::MoveToNearestRailroad, 0, 0},
        {"Advance to nearest Railroad", CardEffect::MoveToNearestRailroad, 0, 0},
        {"Bank pays you dividend of $50", CardEffect::CollectMoney, 50, 0},
        {"Get Out of Jail Free", CardEffect::GetOutOfJailFree, 0, 0},
        {"Go Back 3 Spaces", CardEffect::MoveBackSpaces, 3, 0},
        {"Go to Jail", CardEffect::GoToJail, 0, 0},
        {"Make general repairs on all your property: For each house pay $25, For each hotel pay $100", CardEffect::PayPerBuilding, 25, 100},
        {"Pay poor tax of $15", CardEffect::PayMoney, 15, 0},
        {"Take a trip to Reading Railroad", CardEffect::MoveToSquare, 5, 0},
        {"Take a walk on the Boardwalk", CardEffect::MoveToSquare, 39, 0},
        {"You have been elected Chairman of the Board: Pay each player $50", CardEffect::PayEachPlayer, 50, 0},
        {"Your building loan matures: Collect $150", CardEffect::CollectMoney, 150, 0}
    };

    return chance;
}

std::vector<Player> Simulation::buildPlayers()
{
    std::vector<Player> players;
    for (int i = 0; i < 4; i++){players.push_back(Player("Player:" + std::to_string(i)));}
}