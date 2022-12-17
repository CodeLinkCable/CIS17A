#ifndef PLAYERBANK_H
#define PLAYERBANK_H
class PlayerBank
{
private:
    int valueInBank;
public:
    PlayerBank(int x);
    int getPMoney();
    void addMoney(int x);  
    void loseMoney(int x);  
    friend class Bank;
};


#endif /* PLAYERBANK_H */

