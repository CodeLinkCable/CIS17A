#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;
class Card
{
private:
    string name;
    int value;
    string suit;

public:
    int operator +(Card const &c)
    {
        return value + c.value;
    }
    int operator -(Card const &c)
    {
        return value - c.value;
    }
    int operator >(Card const &c)
    {
        if(value > c.value)
            return value;
        else
            return c.value;
    }
    string getName()
    {
        return name;   
    }
    int getValue()
    {
        return value;
    }
    string getSuit()
    {
        return suit;
    }
    void setName(string x)
    {
        name = x;
    }
    void setValue(int x)
    {
        value = x;
    }
    void setSuit(string x)
    {
        suit = x;
    }

};


#endif /* CARD_H */

