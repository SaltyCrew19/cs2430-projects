// RailroadSquare.h
#pragma once
#include "OwnableSquare.h"
class RailroadSquare : public OwnableSquare
{
public:
    RailroadSquare(int pos, std::string name, int price)
        : OwnableSquare(pos, std::move(name), SquareType::Railroad, price) {}
    // rent calculated in Simulation based on how many railroads owner has
};