#ifndef BANK_H
#define BANK_H
#include "AbsBank.h"
class Bank : public AbsBank //!Bank class that PlayerBank is derived from.  Holds the getter for money.
{  
public:
    Bank(int x);
    //!Overrides AbsBanks getSMoney
    inline int getSMoney() 
    {
        return valueInBank;
    }
};


#endif /* BANK_H */

