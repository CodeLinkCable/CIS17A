#include "Bank.h"  
#include <iostream>
#include <string>
using namespace std; 
    Bank::Bank(int x)
    {
        maxBank = x;
    }
    void Bank::addMoney(int x)
    {
        maxBank += x;
    }
    void Bank::loseMoney(int x)
    {
        maxBank -= x;
    }
    //ADD CATCH THROW EXCEPTIONS HERE FOR WHEN NOT ENOUGH MONEY IS PRESENT
    void Bank::addMoney(int x, PlayerBank y)
    {
        if(maxBank <= x)
        {
            y.valueInBank+=x;
        }
    }    
    void Bank::loseMoney(int x, PlayerBank y)
    {
        if(y.valueInBank >= x)
        {
            y.valueInBank-=x;
        }
        
    }