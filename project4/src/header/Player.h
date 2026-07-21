// Player.h
#pragma once

#include <vector>
#include <string>
#include "Card.h"
enum class Playstyle    {Neutral,Aggressive,Carefull};
enum class JailDecision { PayFine, TryRoll, UseCard };
class Player
{
private:
    
public:
    std::vector<Card> cards;
    std::string name;
    Playstyle style;
    int pos = 0;
    int money = 1500;
    bool inJail = false;
    bool isDone = false;
    int place = 0;
    int doublesCount = 0;
    
    JailDecision decideJailAction() const;

    Player();
    Player(std::string name);
    Player(std::string name, Playstyle style);

};