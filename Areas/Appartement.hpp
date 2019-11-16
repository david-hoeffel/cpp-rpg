#ifndef APPARTEMENT_H
#define APPARTEMENT_H
#include "Area.hpp"

class Appartement : public Area
{ 
    public:
        Appartement();
        Appartement(string nom, Joueur * joueurP);
        virtual ~Appartement();
        virtual void afficheInfos();
};

#endif // APPARTEMENT_H
