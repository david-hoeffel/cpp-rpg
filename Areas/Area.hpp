#ifndef AREA_H
#define AREA_H
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <time.h>
#include "../Characters/Joueur.hpp"
#include "../Item.hpp"
using namespace std;


class Area
{ 
    public:
        Area();
        Area(string nom, Joueur * joueurP);
        virtual ~Area();
        virtual void afficheInfos(); 
        int waitForEnterCM(int car,string c1, string c2, string c3, int i, int choix);
        void traitementAttaque(int choixZone, int choixAttaque, Personnage * sourceP, Personnage * cibleP);  
        bool isEsquiveOrCc(int bottes_or_gants);
        int calculRandom(int borne1);
        void testIfUnderZero(Personnage * personnageP);
        
        string getNom();
        Item getItem();
        
        void setItem(string nom,int type,int bonus);
        void setTexte(string texte);
        void setCondition(string question, string text_if_yes, string text_if_non);
        int setChoixMultiple(string q, string c1, string r1, string c2, string r2, string c3, string r3);
        void setCombat(Joueur * joueurP, Personnage * adversaireP);
        
      
    protected:
        string nom;
        Joueur * joueurP;
        Item item;
};

#endif // AREA_H
