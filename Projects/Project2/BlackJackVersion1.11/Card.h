#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;
class Card  //!Card Class that Holds and Manages All Card Info
{
private:
    string name;  //!Name of Card
    int value; //! Value of Card
    string suit; //! Name of Suit of Card
public:
    //! Adds value of two cards
    int operator +(Card const &c);
    //! Subtracts value of two cards
    int operator -(Card const &c); 
    //! Compares value of two cards
    int operator >(Card const &c); 
    //! Gets name of card
    string getName();  
    //! Gets Value of Card
    int getValue(); 
    //! Gets Suit of Card
    string getSuit(); 
    //! Sets Name Of Card
    void setName(string x);  
    //! Sets Value of Card
    void setValue(int x); 
    //! Sets Suit of Card
    void setSuit(string x); 
};


#endif /* CARD_H */

