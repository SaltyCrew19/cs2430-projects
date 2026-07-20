// UtilitySquare.h
#pragma once
#include "OwnableSquare.h"
class UtilitySquare : public OwnableSquare
{
public:
    UtilitySquare(int pos, std::string name, int price)
        : OwnableSquare(pos, std::move(name), SquareType::Utility, price) {}
    // rent calculated in Simulation based on dice roll
};