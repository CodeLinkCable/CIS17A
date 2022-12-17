#ifndef BANK_H
#define BANK_H

#include "PlayerBank.h"

class Bank
{
private:
    int maxBank;
    
public:
    Bank(int x);
    //ADD CATCH THROW EXCEPTIONS HERE FOR WHEN NOT ENOUGH MONEY IS PRESENT
    void addMoney(int x, PlayerBank y);  
    void loseMoney(int x, PlayerBank y);
    int getSMoney(PlayerBank x)
    {
        return x.valueInBank;
    }
    void addMoney(int x);
    void loseMoney(int x);
};


#endif /* BANK_H */

