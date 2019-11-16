#ifndef JOUEUR_H
#define JOUEUR_H
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "Personnage.hpp"
using namespace std;


class Joueur : public Personnage
{
    public:
        Joueur();
        Joueur(const Joueur & j);
        Joueur(bool exists);
        virtual ~Joueur();
        void afficheInfos();
        void creerPersonnage();
        
        string getSexe();
        string getRace();
        int getAge();
        float getTaille();
        int getArea();
        int getStoryline();
        
        void setSexe(string sexe);
        void setRace(string race);
        void setAge(int age);
        void setTaille(float taille);
        void setArea(int area);
        void setStoryline(int id_storyline);
        
        void setDescGants(string desc_gants);
        void setDescBottes(string desc_bottes);
        void setDescCasque(string desc_casque);
        void setDescBlouson(string desc_blouson);
        void setDescArme(string desc_arme);
        string getDescArme();
        string getDescGants();
        string getDescBottes();
        string getDescBlouson();
        string getDescCasque();
        
    protected:
    private:
        string sexe;
        string race;
        int age;
        float taille;
        int area;
        int id_storyline;
        string desc_gants;
        string desc_arme;
        string desc_bottes;
        string desc_blouson;
        string desc_casque;
        
};

#endif // JOUEUR_H
