//Player.cpp
#include "Player.h"

Player::Player() : name("Default Name"), style(Playstyle::Neutral){}
Player::Player(std::string name):name(std::move(name)),style(Playstyle::Neutral) {}
Player::Player(std::string name, Playstyle style):name(std::move(name)),style(style) {}




//getters and setters
    void Player::setPos(int pos){this->pos = pos;}
    int Player::getPos() const {return this->pos;}
    void Player::setMoney(int money){this->money = money;}
    int Player::getMoney() const {return this->money;}
    void Player::setInJail(bool inJail){this->inJail = inJail;}
    bool Player::getInJail() const {return this->inJail;}
