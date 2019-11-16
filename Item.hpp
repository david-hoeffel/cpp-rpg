#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
using namespace std;


class Item
{ 
    public:
        Item();
        Item(string nom, int type, int bonus);
        virtual ~Item();
        string getNom();
        int getBonus();
    private:
        string nom;
        int type;
        int bonus;
};

#endif // ITEM_H
