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
    int operator +(Card const &c);
    int operator -(Card const &c);
    int operator >(Card const &c);
    string getName();
    int getValue();
    string getSuit();
    void setName(string x);
    void setValue(int x);
    void setSuit(string x);
};


#endif /* CARD_H */

