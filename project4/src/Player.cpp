//Player.cpp
#include "Player.h"

Player::Player() : name("Default Name"), style(Playstyle::Neutral){}
Player::Player(std::string name):name(std::move(name)),style(Playstyle::Neutral) {}
Player::Player(std::string name, Playstyle style):name(std::move(name)),style(style) {}


//TODO:
JailDecision Player::decideJailAction() const
{
    // if (hasJailFreeCard) return JailDecision::UseCard;
    // could branch on `style` here later:
    // Aggressive -> always try rolling (save the $50)
    // Careful -> always pay the $50 (guaranteed out, avoid risk)
    // Neutral -> maybe pay if money is low, roll otherwise

    return JailDecision::PayFine; // placeholder until you build real logic
}