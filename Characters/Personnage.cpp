#include "Personnage.hpp"


/* Constructeur par defaut */
Personnage::Personnage()
{
    this->nom = "";
    this->hp = 100;
    this->casque = 0;
    this->bottes = 0;
    this->blouson = 0;
    this->gants = 0;
    this->arme = 2;
}

/* Constructeur par recopie pour les combats */
Personnage::Personnage(const Personnage & p)
{
    this->nom = p.nom;
    this->hp = p.hp;
    this->casque = p.casque;
    this->bottes = p.bottes;
    this->blouson = p.blouson;
    this->gants = p.gants;
    this->arme = p.arme;
}


/* Reconstruction ou non du personnage sauvegarde */
Personnage::Personnage(string nom, int hp, int casque, int gants, int blouson, int bottes, int arme)
{
   this->nom = nom;
   this->hp = hp;
   this->casque = casque;
   this->gants = gants;
   this->blouson = blouson;
   this->bottes = bottes;
   this->arme = arme;
}

/* Destructeur */
Personnage::~Personnage()
{
    //dtor
}


/* Getteurs */
string Personnage::getNom()
{
    return (nom);
}

int Personnage::getHp()
{
    return (hp);
}

int Personnage::getCasque()
{
     return casque;
}
int Personnage::getBottes()
{
     return bottes;
}
int Personnage::getBlouson()
{
     return blouson;
}
int Personnage::getGants()
{
     return gants;
}
int Personnage::getArme()
{
     return arme;
}

/* Setteurs */
void Personnage::setNom(string nom)
{
     this->nom = nom;
}

void Personnage::setHp(int hp)
{
     this->hp = hp;
}

void Personnage::setCasque(int casque)
{
     this->casque = casque;
}
void Personnage::setBottes(int bottes)
{
     this->bottes = bottes;
}
void Personnage::setBlouson(int blouson)
{
     this->blouson = blouson;
}
void Personnage::setArme(int arme)
{
     this->arme = arme;
}
void Personnage::setGants(int gants)
{
     this->gants = gants;
}
