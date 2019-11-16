#include "Joueur.hpp"


/* Constructeur par defaut */
Joueur::Joueur() : Personnage()
{
   sexe = "";
   race = "";
   age = 0;
   taille = 0;
   area = 0;
   id_storyline = 0;
   desc_arme = "Mains nues (+2)";
   desc_bottes = "Pantoufles (+0)";
   desc_blouson = "Simple veste (+0)";
   desc_gants = "Aucune paire (+0)";
   desc_casque = "Aucun (+0)";   
}


/* Constructeur par recopie */
Joueur::Joueur(const Joueur & j) : Personnage(j)
{
   sexe = "";
   race = "";
   age = 0;
   taille = 0;
   area = 0;
   id_storyline = 0;
   desc_arme = "Mains nues (+2)";
   desc_bottes = "Pantoufles (+0)";
   desc_blouson = "Simple veste (+0)";
   desc_gants = "Aucune paire (+0)";
   desc_casque = "Aucun (+0)";
}


/* Reconstruction ou non du personnage sauvegarde */
Joueur::Joueur(bool exists)
{
   if(exists==1){
      
     //CHARGEMENT           
     ifstream savefile("savefile.xml", ios::in);
  
        if(savefile)
        {
                string nom;
                int hp;
                string sexe;
                string race;
                int age;
                float taille;
                int area;
                int id_storyline;
                int casque;
                int gants;
                int blouson;
                int bottes;
                int arme;
                string desc_casque;
                string desc_gants;
                string desc_blouson;
                string desc_bottes;
                string desc_arme;
                savefile >> nom >> hp >> sexe >> race >> age >> taille >> id_storyline 
                >> area >> casque >> gants >> blouson >> bottes >> arme >> desc_casque 
                >> desc_gants >> desc_blouson >> desc_bottes >> desc_arme;
                setNom(nom);
                setHp(hp);
                setSexe(sexe);
                setRace(race);
                setAge(age);
                setTaille(taille);
                setArea(area);
                setStoryline(id_storyline);
                setCasque(casque);
                setGants(gants);
                setBlouson(blouson);
                setBottes(bottes);
                setArme(arme);
                setDescArme(desc_arme); 
                setDescBottes(desc_bottes); 
                setDescBlouson(desc_blouson); 
                setDescGants(desc_gants); 
                setDescCasque(desc_casque);
                savefile.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier de sauvegarde !" << endl;
   }
   
   else
   {
     creerPersonnage();
     hp = 100;
     area = 0;
     id_storyline = 0;
     casque = 0;
     gants = 0;
     blouson = 0;
     bottes = 0;
     arme = 2;
     desc_arme = "Mains nues (+2)";
     desc_bottes = "Pantoufles (+0)";
     desc_blouson = "Simple veste (+0)";
     desc_gants = "Aucune paire (+0)";
     desc_casque = "Aucun (+0)";
   }
}


/* Destructeur */
Joueur::~Joueur()
{
    //dtor
}


/* Affiche l'etat du personnage (Proto-neon) */
void Joueur::afficheInfos()
{
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    cout << "Nom       : " << getNom() << endl
    << "Hp        : " << getHp() << endl
    << "Sexe      : " << getSexe() << endl
    << "Race      : " << getRace() << endl
    << "Age       : " << getAge() << endl
    << "Taille    : " << getTaille() << endl 
    << "Storyline : " << getStoryline() << endl
    << "Area      : " << getArea() << endl << endl
    << "Casque    : " << getCasque() << endl
    << "Gants     : " << getGants() << endl
    << "Blouson   : " << getBlouson() << endl
    << "Bottes    : " << getBottes() << endl
    << "Arme      : " << getArme() << endl << endl 
    
    << getDescCasque() << endl
    << getDescGants() << endl
    << getDescBlouson() << endl
    << getDescBottes() << endl
    << getDescArme() << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    //_getch();
}


/* Methode de creation du personnage */
void Joueur::creerPersonnage()
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_BLUE);
  cout << "Quel est votre nom d'aventurier ?" << endl << endl;
  string nomTemp("Yorick");           //On crée une case mémoire pour contenir une chaine de caractères
  cin >> nomTemp;
  cout << endl << endl;
  setNom(nomTemp);                       //On remplit cette case avec ce qu'écrit l'utilisateur  
  
    cout << "Quel est votre sexe (homme ou femme) ?" << endl << endl;
    string sexeTemp("Homme");           //On crée une case mémoire pour contenir une chaine de caractères
    cin >> sexeTemp;  
    cout << endl << endl;                     //On remplit cette case avec ce qu'écrit l'utilisateur
    setSexe(sexeTemp);

    cout << "Quelle est votre race ?" << endl << endl;
    string raceTemp("Humain");           //On crée une case mémoire pour contenir une chaine de caractères
    cin >> raceTemp;
    cout << endl << endl;                       //On remplit cette case avec ce qu'écrit l'utilisateur
    setRace(raceTemp);

    cout << "Quel age avez-vous ? (entier)" << endl << endl;
    int ageTemp(15);                  //On crée une case mémoire pour stocker un nombre réel
    cin >> ageTemp;  
    cout << endl << endl;                      //Et on remplit cette case avec ce qu'écrit l'utilisateur
    setAge(ageTemp);

    cout << "Quelle est votre taille ? (flottant)" << endl << endl;
    float tailleTemp(1.50);                  //On crée une case mémoire pour stocker un nombre réel
    cin >> tailleTemp; 
    cout << endl << endl;                       //Et on remplit cette case avec ce qu'écrit l'utilisateur 
    setTaille(tailleTemp);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),/*FOREGROUND_INTENSITY |*/ 7);
}


/* Getteurs */
string Joueur::getSexe()
{
    return (sexe);
}

string Joueur::getRace()
{
    return (race);
}

int Joueur::getAge()
{
    return (age);
}

float Joueur::getTaille()
{
    return (taille);
}

int Joueur::getArea()
{
    return (area);
}
int Joueur::getStoryline()
{
    return (id_storyline);
}
string Joueur::getDescCasque()
{
    return (desc_casque);
}
string Joueur::getDescBottes()
{
    return (desc_bottes);
}
string Joueur::getDescBlouson()
{
    return (desc_blouson);
}
string Joueur::getDescArme()
{
    return (desc_arme);
}
string Joueur::getDescGants()
{
    return (desc_gants);
}


/* Setteurs */
void Joueur::setSexe(string sexe)
{
     this->sexe = sexe;
}

void Joueur::setRace(string race)
{
     this->race = race;
}

void Joueur::setAge(int age)
{
     this->age = age;
}

void Joueur::setTaille(float taille)
{
     this->taille = taille;
}

void Joueur::setArea(int area)
{
     this->area = area;
}     
void Joueur::setStoryline(int id_storyline)
{
     this->id_storyline = id_storyline;
}

void Joueur::setDescCasque(string desc_casque)
{
     this->desc_casque = desc_casque;
}

void Joueur::setDescBottes(string desc_bottes)
{
     this->desc_bottes = desc_bottes;
}

void Joueur::setDescBlouson(string desc_blouson)
{
     this->desc_blouson = desc_blouson;
}

void Joueur::setDescGants(string desc_gants)
{
     this->desc_gants = desc_gants;
}

void Joueur::setDescArme(string desc_arme)
{
     this->desc_arme = desc_arme;
}
