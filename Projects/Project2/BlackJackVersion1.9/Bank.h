#ifndef BANK_H
#define BANK_H

#include "PlayerBank.h"

class Bank
{
private:
    int maxBank;
public:
    Bank(int x)
    {
        maxBank = x;
    }
    void addMoney(int x)
    {
        maxBank += x;
    }
    void loseMoney(int x)
    {
        maxBank -= x;
    }
    //ADD CATCH THROW EXCEPTIONS HERE FOR WHEN NOT ENOUGH MONEY IS PRESENT
    void addMoney(int x, PlayerBank y)
    {
        if(maxBank <= x)
        {
            y.valueInBank+=x;
        }
    }    
    void loseMoney(int x, PlayerBank y)
    {
        if(y.valueInBank >= x)
        {
            y.valueInBank-=x;
        }
        
    }
};


#endif /* BANK_H */

