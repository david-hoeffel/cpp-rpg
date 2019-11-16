#ifndef STORYLINE1_H
#define STORYLINE1_H
#include "Storyline.hpp"
#include "../Areas/Bar.hpp"

class Storyline1 : public Storyline
{ 
    public:
        Storyline1();
        Storyline1(int id_storyline, string nom, Joueur * joueurP, int nb_areas);
        virtual ~Storyline1(); 
};

#endif // STORYLINE1_H
