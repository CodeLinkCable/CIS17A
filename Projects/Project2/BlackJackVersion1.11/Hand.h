#include "Card.h"
#include "Deck.h"
#include <string>
#include <iostream>
#ifndef HAND_H
#define HAND_H
using namespace std;
class Hand:public Deck  //!Hand class that handles all dealings of cards.
{
private:
    int size;

public:
    //!Constructor
    Hand();
    //!Destructor
    ~ Hand();
    //!Overloaded Constructor
    Hand(string x, int y);
    //!Copy Constructor
    Hand(Hand &x);
    //!Returns Size
    int getSize();  
    //!Sets Size
    void setSize(int x);
    //! Prints Hand
    void printHand();   
    //! Prints Hand (using a value to printer a certain number of times)
    void printHand(int x); 
};


#endif /* HAND_H */

