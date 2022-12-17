#include "Deck.h"
#include <iostream>
#include <string>
using namespace std;   
    //Constructor
    Deck::Deck()
    {
        name = "NULL";
    }
    //Destructor
    Deck::~Deck()
    {
        
    }
    //Overloaded constructor
    Deck::Deck(string x)
    {
        name = x;
    }
    //Getters
    string Deck::getName()
    {
        return name;   
    }
    Card* Deck::getCardsInHand()
    {
        return cardsInHand;
    }
    //Setters
    void Deck::setName(string x)
    {
        name = x;
    }
    void Deck::setCardsInHand(Card* x)
    {
        cardsInHand = x;
    }
    //Printers
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