#include "Storyline0.hpp"


/* Constructeur par defaut */
Storyline0::Storyline0()
{    

}

/* Constructeur avec nom*/
Storyline0::Storyline0(int id_storyline, string nom, Joueur * joueurP, int nb_areas)
{
    this->nom = nom;
    this->id_storyline = id_storyline;
    this->nb_areas = nb_areas;
    this->joueurP = joueurP;  
    Storyline(this->id_storyline,this->nom,this->joueurP,this->nb_areas);
    
    texte = "Il pleut dehors comme tous les soirs. Peu de lumière filtre encore\n"
    "entre les gouttes qui se fracassent sur le sol. Il est 21h.\n"
    "Plus personne n'arpente les rues désertes et surveillées du centre-ville.\n"
    "Il n'y a que la pluie, qui déverse sa tristesse par d'infimes morceaux\n"
    "d'elle-même, instaurant ce rythme qui lui est propre. Le rythme du\n"
    "temps qui s'écoule sans fin, sans but." ;
    
    Appartement* appartement = new Appartement("Appartement",this->joueurP);
    Bar* bar = new Bar("Le Bar de Jack",this->joueurP);  
    tab_zones[0] = appartement;
    tab_zones[1] = bar;
}


/* Destructeur */
Storyline0::~Storyline0()
{
    //dtor
}
