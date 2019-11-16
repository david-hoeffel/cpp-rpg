#ifndef STORYLINE0_H
#define STORYLINE0_H
#include "Storyline.hpp"
#include "../Areas/Appartement.hpp"
#include "../Areas/Bar.hpp"

class Storyline0 : public Storyline
{ 
    public:
        Storyline0();
        Storyline0(int id_storyline, string nom, Joueur * joueurP, int nb_areas);
        virtual ~Storyline0(); 
};

#endif // STORYLINE0_H
