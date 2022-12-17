#ifndef HAND_H
#include "Card.h"
#include <string>
using namespace std;
#define HAND_H
class Deck
{
protected:
    string name;
    Card* cardsInHand;
private:
    static const int deckSize = 52;
public:
    Deck()
    {
        name = "NULL";
    }
    Deck(string x)
    {
        name = x;
    }
    string getName()
    {
        return name;   
    }
    Card* getCardsInHand()
    {
        return cardsInHand;
    }
    void setName(string x)
    {
        name = x;
    }
    void setCardsInHand(Card* x)
    {
        cardsInHand = x;
    }
    inline void printHand()
    {
        cout << name << ":" << endl;
        int total = 0;
        for(int i = 0; i < deckSize; i++)
        {
            cout << cardsInHand[i].getName() << endl;
            total += cardsInHand[i].getValue();
        }
        cout << "Total: " << total << endl;
    }
};
class Hand:public Deck
{
private:
    int size;
public:
    Hand()
    {
        name = "NULL";
        size = 0;
    }
    Hand(string x, int y)
    {
        name = x;
        size = y;
    }
    Hand(Hand &x)
    {
        name = x.name;
        cardsInHand = x.cardsInHand;
        size = x.size;
    }
    int getSize()
    {
        return size;
    }
    void setSize(int x)
    {
        size = x;
    }
    inline void printHand()
    {
        cout << name << ":" << endl;
        int total = 0;
        for(int i = 0; i < size; i++)
        {
            cout << cardsInHand[i].getName() << endl;
            total += cardsInHand[i].getValue();
        }
        cout << "Total: " << total << endl;
    }    
    inline void printHand(int x)
    {
        cout << name << ":" << endl;
        for(int i = 0; i < size; i++)
        {
            cout << cardsInHand[i].getName() << endl;
        }
        cout << "Total: " << x << endl;
    }
};


#endif /* HAND_H */

