#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "../Item.hpp"
using namespace std;


class Personnage
{
    public:
        Personnage();
        Personnage(const Personnage & p);
        Personnage(string nom, int hp, int casque, int gants, int blouson, int bottes, int arme);
        virtual ~Personnage();
        
        string getNom();
        int getHp();
        int getCasque();
        int getBottes();
        int getBlouson();
        int getArme();
        int getGants();
        
        void setNom(string nom);
        void setHp(int hp);
        void setCasque(int casque);
        void setBlouson(int blouson);
        void setBottes(int bottes);
        void setGants(int gants);
        void setArme(int arme); 
        
    protected:
        int hp;
        string nom;
        int casque;
        int gants;
        int bottes;
        int blouson;
        int arme;
        
};

#endif // PERSONNAGE_H
