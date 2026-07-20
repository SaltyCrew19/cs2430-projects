//Deck.cpp
#include "Deck.h"

Deck::Deck(std::vector<Card> initialCards): cards(initialCards.begin(), initialCards.end()), originalCards(initialCards) {}

void Deck::reset()
{
    cards.assign(originalCards.begin(), originalCards.end());
    shuffle();
}

void Deck::shuffle()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::shuffle(cards.begin(), cards.end(), gen);
}

Card Deck::draw()
{
    Card draw = cards.front();
    cards.pop_front();
    return draw;
}

void Deck::returnCard(const Card& card) { cards.push_back(card); }

