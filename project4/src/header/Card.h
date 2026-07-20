//Card.h
#pragma once
#include <string>

// Each value here corresponds to how Deck/Simulation will
// interpret and apply the card once drawn.
enum class CardEffect
{
    MoveToSquare,           // moves player to a specific board position (target position stored in `value`)
    MoveToNearestRailroad,  // moves player forward to the closest Railroad square from their current position
    MoveToNearestUtility,   // moves player forward to the closest Utility square from their current position
    GoToJail,               // sends player directly to the Jail square, ignores GO collection
    GetOutOfJailFree,       // player holds this card until used; removed from deck while held
    MoveBackSpaces,         // moves player backward by `value` spaces (e.g. "Go Back 3 Spaces")
    MoveToGo,               // moves player to GO (position 0), typically also collects $200
    CollectMoney,           // player receives money from the bank, amount stored in `value`
    PayMoney,               // player pays money to the bank, amount stored in `value`
    NoEffect,               // card has no movement/money effect (placeholder for cards you choose not to implement)
    PayEachPlayer,          // pay a fixed amount to every other player (value = amount per player)
    CollectFromEachPlayer,  // collect a fixed amount from every other player (value = amount per player)
    PayPerBuilding          // pay per house/hotel owned (needs 2 values: per-house and per-hotel rate, more below)
};

struct Card
{
    std::string text;   // the card's printed text, shown to the player when drawn
    CardEffect effect;  // which behavior this card triggers, handled in Simulation/Player logic
    int value;          // primary value: dollar amount, board position, or per-house repair rate
    int secondValue;    // only used by PayPerBuilding, the per-hotel rate; unused (0) otherwise
};