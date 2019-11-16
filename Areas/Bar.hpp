#ifndef BAR_H
#define BAR_H
#include "Area.hpp"

class Bar : public Area
{ 
    public:
        Bar();
        Bar(string nom, Joueur * joueurP);
        virtual ~Bar();
        virtual void afficheInfos();
};

#endif // BAR_H
