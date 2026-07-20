//Deck.h
#include <vector>
#include <deque>
#include <algorithm>
#include <random>
#include "Card.h"

class Deck
{
private:
    std::deque<Card> cards;
    std::vector<Card> originalCards;
public:
    Deck(std::vector<Card> initialCards);

    void shuffle();
    Card draw();
    void returnCard(const Card& card);
    void reset();
};