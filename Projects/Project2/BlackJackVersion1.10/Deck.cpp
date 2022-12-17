#include "Deck.h"
#include <iostream>
#include <string>
using namespace std;     
    Deck::Deck()
    {
        name = "NULL";
    }
    Deck::~Deck()
    {
        
    }
    Deck::Deck(string x)
    {
        name = x;
    }
    string Deck::getName()
    {
        return name;   
    }
    Card* Deck::getCardsInHand()
    {
        return cardsInHand;
    }
    void Deck::setName(string x)
    {
        name = x;
    }
    void Deck::setCardsInHand(Card* x)
    {
        cardsInHand = x;
    }
    inline void Deck::printHand()
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