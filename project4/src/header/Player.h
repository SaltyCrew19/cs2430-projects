// Player.h
#pragma once

#include <vector>
#include <string>
#include "Card.h"
enum class Playstyle
{
    Neutral,
    Aggressive,
    Carefull
};
class Player
{
private:
    std::string name;
    Playstyle style;
    int pos = 0;
    int money = 1500;
    bool inJail = false;
    std::vector<Card> cards;
public:

    bool isDone = false;
    int place = 0;
    Player();
    Player(std::string name);
    Player(std::string name, Playstyle style);

    //getters and setters
    void setPos(int pos);
    int getPos() const;
    void setMoney(int money);
    int getMoney() const;
    void setInJail(bool inJail);
    bool getInJail() const;
    
};