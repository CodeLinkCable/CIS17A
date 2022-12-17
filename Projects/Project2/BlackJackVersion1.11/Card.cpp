#include "Card.h"
#include <string>
using namespace std; 
    //Overloads to work with card class objects
    int Card::operator +(Card const &c)
    {
        return value + c.value;
    }
    int Card::operator -(Card const &c)
    {
        return value - c.value;
    }
    int Card::operator >(Card const &c)
    {
        if(value > c.value)
            return value;
        else
            return c.value;
    }
    //Getters
    string Card::getName()
    {
        return name;   
    }
    int Card::getValue()
    {
        return value;
    }
    string Card::getSuit()
    {
        return suit;
    }
    //Setters
    void Card::setName(string x)
    {
        name = x;
    }
    void Card::setValue(int x)
    {
        value = x;
    }
    void Card::setSuit(string x)
    {
        suit = x;
    }

