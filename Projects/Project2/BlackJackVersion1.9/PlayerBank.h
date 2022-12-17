#ifndef PLAYERBANK_H
#define PLAYERBANK_H
class PlayerBank
{
private:
    int valueInBank;
public:
    PlayerBank(int x)
    {
        valueInBank = x;
    }
    friend class Bank;
};


#endif /* PLAYERBANK_H */

