#include "Card.h"
#ifndef DECK_H
#define DECK_H
class Deck
{
protected:
    string name;
    Card* cardsInHand;
private:
    static const int deckSize = 52;
public:
    Deck();
    ~ Deck();
    Deck(string x);
    string getName();
    Card* getCardsInHand();
    void setName(string x);
    void setCardsInHand(Card* x);
    inline void printHand();
};


#endif /* DECK_H */

