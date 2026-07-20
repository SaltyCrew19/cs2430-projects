// PropertySquare.h
#pragma once
#include <array>
#include "OwnableSquare.h"

class PropertySquare : public OwnableSquare
{
public:
    PropertySquare(int pos, std::string name, int price, std::array<int,6> rentLevels)
        : OwnableSquare(pos, std::move(name), SquareType::Property, price),rentLevels(rentLevels) {}


        int price;
        std::array<int, 6> rentLevels; // [0]=no houses, [1]-[4]=1-4 houses, [5]=hotel
        int numHouses = 0;

        int currentRent() const { return rentLevels[numHouses]; }
};
