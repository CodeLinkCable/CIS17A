#ifndef BANKEXCEPTION_H
#define BANKEXCEPTION_H
#include <iostream>
using namespace std;
class BankException //!Throws an exception if a bank will overdraft
{
public:
    bool result = false;
    //!Checks compared money values for invalid amounts and output error message
    BankException(int x, int y)
    {
        
        if(x<y)
        {
            cout << "ERROR 504: VALUE INVALID.  RETURNING TO DEFAULT PARAMETERS." << endl;
            result = true;
        }
    }
};


#endif /* BANKEXCEPTION_H */

