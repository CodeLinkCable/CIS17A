#ifndef ABSBANK_H
#define ABSBANK_H
#include "BankException.h"
class AbsBank //!Abstract Class that Bank And PlayerBank are derived from
{ 
private:
    bool ex = false; //! Checks if an exception is thrown
protected:
    int maxBank;
    int valueInBank;
public:
    //!Returns value of banks
    virtual inline int getSMoney() 
    {
        return 0;
    }
    
    //!Adds value to the given bank
    inline void addMoney(int x, AbsBank y)
    {
       valueInBank+=x;
    }    
    //!Uses exception to avoid overdrafts
    inline void loseMoney(int x, AbsBank y)
    {
        try
        {
            throw BankException(valueInBank,x);
        }   
        catch(BankException t)
        {
            if(t.result)
            {
                valueInBank = 0;
                cout << "Value has been tested" << endl;
                return;
            }
            else
            {
                valueInBank -= x;
            }
        }
        
     } 
};
#endif /* ABSBANK_H */

