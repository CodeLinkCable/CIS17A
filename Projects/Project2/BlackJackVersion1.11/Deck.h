#include "Card.h"
#ifndef DECK_H
#define DECK_H
class Deck //!Deck Class that Hand is derived from.  Holds info on the full deck of cards.
{
protected:
    string name;
    Card* cardsInHand;
private:
    static const int deckSize = 52;
public:
    //!Constructor
    Deck();
    //!Destructor
    ~ Deck();
    //!Overloaded Constructor
    Deck(string x);
    //! Returns name
    string getName(); 
    //! Returns cardsInHand
    Card* getCardsInHand(); 
    //! Sets Name
    void setName(string x); 
    //! Sets cardsInHand
    void setCardsInHand(Card* x);
    //! Prints the contents of the deck
    inline void printHand(); 
};


#endif /* DECK_H */

