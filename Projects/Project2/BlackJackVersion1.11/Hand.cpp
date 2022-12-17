#include "Hand.h"
#include <iostream>
#include <string>
using namespace std;
    //Constructor
    Hand::Hand()
    {
        name = "NULL";
        size = 0;
    }
    //Destructor
    Hand::~Hand()
    {
        cout << name << " hand has been altered or removed." << endl;
    }
    //Overload Constructor
    Hand::Hand(string x, int y)
    {
        name = x;
        size = y;
    }
    //Copy Constructor
    Hand::Hand(Hand &x)
    {
        name = x.name;
        cardsInHand = x.cardsInHand;
        size = x.size;
    }
    //Getters
    int Hand::getSize()
    {
        return size;
    }
    void Hand::setSize(int x)
    {
        size = x;
    }
    //Printers
    void Hand::printHand()
    {
        cout << name << ":" << endl;
        int total = 0;
        for(int i = 0; i < size; i++)
        {
            cout << cardsInHand[i].getName() << endl;
            total += cardsInHand[i].getValue();
        }
        cout << "Total: " << total << endl;
    }    
    void Hand::printHand(int x)
    {
        cout << name << ":" << endl;
        for(int i = 0; i < size; i++)
        {
            cout << cardsInHand[i].getName() << endl;
        }
        cout << "Total: " << x << endl;
    }

