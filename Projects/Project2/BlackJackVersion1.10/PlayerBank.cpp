#include "PlayerBank.h"   
PlayerBank::PlayerBank(int x)
{
    valueInBank = x;

}
int PlayerBank::getPMoney()
{
    return valueInBank;
}
void PlayerBank::addMoney(int x)
{
    valueInBank+=x;
}
void PlayerBank::loseMoney(int x)
{
    valueInBank-=x;
}