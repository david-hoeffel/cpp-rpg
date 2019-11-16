#include "Storyline1.hpp"


/* Constructeur par defaut */
Storyline1::Storyline1()
{    

}


/* Constructeur avec nom*/
Storyline1::Storyline1(int id_storyline, string nom, Joueur * joueurP, int nb_areas)
{
    this->nom = nom;
    this->id_storyline = id_storyline;
    this->nb_areas = nb_areas;
    this->joueurP = joueurP; 
    Storyline(this->id_storyline,this->nom,this->joueurP,this->nb_areas);
    texte = "texte sl 1";
    
    Bar* bar = new Bar("Bar", this->joueurP);
    
    tab_zones[0] = bar;
}


/* Destructeur */
Storyline1::~Storyline1()
{
    //dtor
}
