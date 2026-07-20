// Square.h
#pragma once
#include <string>

enum class SquareType 
{
    Go,
    Property,
    Railroad,
    Utility,
    Tax,
    Chance,
    CommunityChest,
    Jail,
    FreeParking,
    GoToJail
};

class Square 
{
public:
    Square(int pos, std::string name, SquareType type):position(pos), name(std::move(name)), type(type) {}
    virtual ~Square() = default;

    int position;
    std::string name;
    SquareType type;
};