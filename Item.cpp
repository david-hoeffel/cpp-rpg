#include "Item.hpp"


/* Constructeur par defaut */
Item::Item()
{
              
}


/* Constructeur avec nom*/
Item::Item(string nom, int type, int bonus)
{
    this->nom = nom;
    this->type = type;  
    this->bonus = bonus;
}


/* Destructeur */
Item::~Item()
{
    //dtor
}

string Item::getNom()
{
    return nom;
}

int Item::getBonus()
{
    return bonus;
}




     
