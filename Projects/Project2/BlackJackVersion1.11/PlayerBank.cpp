#include "PlayerBank.h"   
//Constructor
PlayerBank::PlayerBank(int x) : Bank(x)
{
    valueInBank = x;
}
PlayerBank::PlayerBank(int x, string y) : Bank(x)
{
    valueInBank = x;
    bankName = y;
}