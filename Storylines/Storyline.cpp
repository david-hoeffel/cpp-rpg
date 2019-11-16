#include "Storyline.hpp"



/* Constructeur par defaut */
Storyline::Storyline()
{    
     
}


/* Constructeur par defaut */
Storyline::Storyline(int id_storyline,string nom, Joueur * joueurP, int nb_areas)
{    
    
    this->nom = nom;
    this->id_storyline = id_storyline;
    this->nb_areas = nb_areas; 
    this->joueurP = joueurP;
    //texte = " ";
}


/* Destructeur */
Storyline::~Storyline()
{
    //dtor
}


/* Afficher le contenu entier de la storyline */
void Storyline::processStory(int etape)
{

 
  for(int i=etape;i<nb_areas;++i)
  {   
      if(i==0)
      {
               cout << endl << endl << endl << endl << endl << endl << "=========================== " 
               << nom << " ==========================="<< endl << endl;
               _getch();
               cout << texte << endl << endl;
      }
      
       joueurP->setArea(i);
       joueurP->setStoryline(id_storyline);
       
       //SAUVEGARDE
       ofstream savefile("savefile.xml", ios::out | ios::trunc);  
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
                nom = joueurP->getNom();
                hp = joueurP->getHp();
                sexe = joueurP->getSexe();
                race = joueurP->getRace();
                age = joueurP->getAge();
                taille = joueurP->getTaille();
                area = joueurP->getArea();
                id_storyline = joueurP->getStoryline();
                casque = joueurP->getCasque();
                gants = joueurP->getGants();
                blouson = joueurP->getBlouson();
                bottes = joueurP->getBottes();
                arme = joueurP->getArme();
                savefile << nom << endl;
                savefile << hp << endl;
                savefile << sexe << endl;
                savefile << race << endl;
                savefile << age << endl;
                savefile << taille << endl;
                savefile << id_storyline << endl;
                savefile << area << endl << endl;
                savefile << casque << endl;
                savefile << gants << endl;
                savefile << blouson << endl;
                savefile << bottes << endl;
                savefile << arme << endl;
                savefile.close();
        }
        else
        {
             cerr << "Impossible d'ouvrir le fichier de sauvegarde !" << endl;   
        }
        
       getArea(i)->afficheInfos();
               
  }  
  _getch();
  //delete tab_zones;                    
}


/* Getteurs */
Area* Storyline::getArea(int i)
{
   return(tab_zones[i]);  
}

string Storyline::getTexte()
{
       return texte;
}

int Storyline::getNbAreas()
{
       return nb_areas;
}

int Storyline::getId()
{
       return id_storyline;
}



     
