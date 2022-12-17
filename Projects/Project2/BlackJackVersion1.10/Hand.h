#include "Card.h"
#include "Deck.h"
#include <string>
#include <iostream>
#ifndef HAND_H
#define HAND_H
using namespace std;
class Hand:public Deck
{
private:
    int size;

public:
    Hand();
    ~ Hand();
    Hand(string x, int y);
    Hand(Hand &x);
    int getSize();
    void setSize(int x);
    virtual inline void printHand();   
    virtual inline void printHand(int x);
};


#endif /* HAND_H */

