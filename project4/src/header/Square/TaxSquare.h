//TaxSquare.h
#pragma once
#include "Square.h"

class TaxSquare : public Square
{
public:
    TaxSquare(int pos, std::string name, int fee)
        : Square(pos, std::move(name), SquareType::Tax), fee(fee) {}
        
    int fee;
};