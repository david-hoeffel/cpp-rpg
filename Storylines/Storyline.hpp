#ifndef STORYLINE_H
#define STORYLINE_H
#include <iostream>
#include <string>
#include <fstream>
#include "../Areas/Area.hpp"
#include "../Characters/Joueur.hpp"
using namespace std;


class Storyline
{
    public:
        Storyline();
        Storyline(int id_storyline,string nom, Joueur * joueurP, int nb_areas);
        virtual ~Storyline(); 
        void processStory(int etape); 
        Area* getArea(int i);
        string getTexte();
        int getNbAreas();
        int getId();
     
    protected:
        int id_storyline;
        string nom;
        Joueur * joueurP;
        string texte;
        int nb_areas;
        Area* tab_zones [20]; 
             
};

#endif // STORYLINE_H
