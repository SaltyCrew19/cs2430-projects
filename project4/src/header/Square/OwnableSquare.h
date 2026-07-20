// OwnableSquare.h
#pragma once
#include "Square.h"

class Player;

class OwnableSquare : public Square
{
public:
    OwnableSquare(int pos, std::string name, SquareType type, int price)
        : Square(pos, std::move(name), type), price(price) {}

    int price;
    Player* owner = nullptr;
};
