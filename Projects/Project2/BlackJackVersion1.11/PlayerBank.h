#ifndef PLAYERBANK_H
#define PLAYERBANK_H
#include "Bank.h"
#include <string>
using namespace std;
class PlayerBank : public Bank  //!Bank that the player's money is held in.
{
    private:
        //Used to hold the player's bank's name
        string bankName;
    public:
    //! Constructor
    PlayerBank(int x);  
    //! Overridden Constructor to give the bank a name.
    PlayerBank(int x, string y); 
    //! Returns bankName
    inline string getBankName()  
    {
        return bankName;
    };
            
};
#endif /* PLAYERBANK_H */

