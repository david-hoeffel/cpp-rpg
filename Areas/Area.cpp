#include "Area.hpp"

/* Constructeur par defaut */
Area::Area()
{

}


/* Constructeur avec nom*/
Area::Area(string nom, Joueur * joueurP)
{
    this->joueurP = joueurP;
    this->nom = nom;
}


/* Destructeur */
Area::~Area()
{
    //dtor
}


/* Affiche le titre de la zone */
void Area::afficheInfos()
{
    _getch(); //attente d'appui d'un touche
    cout << endl << endl << endl << "---------------- " << getNom() << " ----------------" << endl << endl;
}


/* Attente d'appui de touche entree lors d'un choix multiple */
int Area::waitForEnterCM(int car,string c1, string c2, string c3, int i, int choix)
{
    if(car==13)
    {
               return choix;
    }
    else
    {
       if(i==1)
       {
               cout << "\r";
               SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN); 
               cout << c1;
               SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_BLUE);
               cout << "   " << c2 << "   " << c3; 
               car = getch();
               return waitForEnterCM(car,c1,c2,c3,2,0);           
       }
       else if(i==0)
       {
               cout << "\r" << c1 << "   " ;
               SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN); 
               cout << c2;
               SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_BLUE);
               cout << "   " << c3;
               car = getch();
               return waitForEnterCM(car,c1,c2,c3,1,1);       
       }
       else if(i==2)
       {
               cout << "\r" << c1 << "   " << c2 << "   ";
               SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN); 
               cout << c3;
               SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_BLUE);
               car = getch();
               return waitForEnterCM(car,c1,c2,c3,0,2);           
       }
   }      
}

/** RAZ des attributs du personnage tombés en dessous de 0*/
void Area::testIfUnderZero(Personnage * personnageP)
{
     if(personnageP->getHp()<0)
     {
        personnageP->setHp(0);
     }
     if(personnageP->getGants()<0)
     {
        personnageP->setGants(0);
     }
     if(personnageP->getBottes()<0)
     {
        personnageP->setBottes(0);
     }
}

/** Retourne une valeur aléatoire*/
int Area::calculRandom(int borne)
{
    int randVal = 0;
    for(int i=0;i<5;i++)
    { 
            randVal = ((int)((float)rand()/32767*borne));
    }
    //cout << "RANDOM : " << randVal << endl;
    return randVal ;
}

/** Retourne 1 si l'esquive(bottes) ou le cc(gants) est réussi*/
bool Area::isEsquiveOrCc(int bottes_or_gants)
{
    
    int randVal = calculRandom(100);
    
    if(randVal <= bottes_or_gants)
    {
         return 1;
    }
    else
    {
        return 0;
    }
}


/** Affiche le résultat d'une attaque et met à jour les attributs des combattants*/
void Area::traitementAttaque(int choixZone, int choixAttaque, Personnage * sourceP, Personnage * cibleP)
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
  bool esquive = isEsquiveOrCc(cibleP->getBottes());
  bool cc = isEsquiveOrCc(sourceP->getGants());

  if(esquive == 1)
  {
         cout << cibleP->getNom() << " a esquivé l'attaque ! " << endl;
  }
  else{
     int outputDegats;
     int cibleGantsTmp = cibleP->getGants();
     int cibleBottesTmp = cibleP->getBottes();
     bool esquiveCoupSpecial = 0;
     string membre="aucun";
     cout << sourceP->getNom() << " inflige : ";
     
     //Tete
     if(choixZone == 0)
     {
          cout << "Attaque à la tête ";
          outputDegats = sourceP->getArme()-cibleP->getCasque();
          //Frontal
          if(choixAttaque == 0)
          {
              cout << "par coup Frontal";
              if(isEsquiveOrCc(cibleP->getBottes()))
              {
                  cibleP->setCasque(0);
                  cout << "(destruction de l'équipement !)";
              }
          }
          //Rapide
          if(choixAttaque == 1)
          {
              cout << "par coup Rapide";
          }
          //Lourd
          if(choixAttaque == 2)
          {
              cout << "par coup Lourd";
              if(isEsquiveOrCc(cibleP->getBottes()))
              {
                  outputDegats = outputDegats*2;
                  cout << "(réussi - dégats X2)";
              }
              else
              {
                  esquiveCoupSpecial=1;
                  cout << "(esquivé)";
                  outputDegats = 0;
              }
          }
          
          if(cc==1 && esquiveCoupSpecial!=1)
          {
                 if((sourceP->getNom()==joueurP->getNom()) && (isEsquiveOrCc(cibleP->getBottes())))
                 {
                       cout << endl << "Coup critique ! " << cibleP->getNom() << " décapité !"; 
                       outputDegats = cibleP->getHp();   
                 }
                 else if((sourceP->getNom()!=joueurP->getNom()))
                 {
                      cout << endl << "Coup critique ! Coup supplémentaire sans protection du casque !";
                      outputDegats += sourceP->getArme();
                 }
                 
                 esquiveCoupSpecial = 0;
          }
     }
     
     //Buste
     if(choixZone == 1)
     {
          cout << "Attaque au buste ";
          outputDegats = sourceP->getArme()-cibleP->getBlouson();
          //Frontal
          if(choixAttaque == 0)
          {
              cout << "par coup Frontal";
              if(isEsquiveOrCc(cibleP->getBottes()))
              {
                  cibleP->setBlouson(0);
                  cout << "(destruction de l'équipement !)";
              }
          }
          //Rapide
          if(choixAttaque == 1)
          {
              cout << "par coup Rapide";
          }
          //Lourd
          if(choixAttaque == 2)
          {
              cout << "par coup Lourd";
              if(isEsquiveOrCc(cibleP->getBottes()))
              {
                  outputDegats = outputDegats*2;
                  cout << "(réussi - dégats X2)";
              }
              else
              {
                  esquiveCoupSpecial = 1;
                  cout << "(esquivé)";
                  outputDegats = 0;
              }
          }
          
          if(cc==1 && esquiveCoupSpecial!=1)
          {
                 cout << endl << "Coup critique ! Coup supplémentaire sans protection du blouson !";
                 outputDegats += sourceP->getArme();
                 esquiveCoupSpecial = 0;
          }
     }
     
     
     //Membre
     if(choixZone == 2)
     {
          cout << "Attaque ";
          outputDegats = sourceP->getArme();
          if(calculRandom(2)==0)
          {
                 membre = "bras";
                 cout << "au bras ";
                  
          }
          else
          {
              membre = "jambe";
              cout << "à la jambe "; 
          }
          //Frontal
          /*if(choixAttaque == 0)
          {
              cout << "par coup Frontal";
          }
          //Rapide
          if(choixAttaque == 1)
          {
              cout << "par coup Rapide";
          }
          //Lourd
          if(choixAttaque == 2)
          {
              cout << "par coup Lourd";
          }*/
          
          
          if(cc==1)
          {
                 if((sourceP->getNom()==joueurP->getNom()) && (isEsquiveOrCc(cibleP->getBottes())))
                 {
                       cout << endl << "Coup critique ! " << membre << " tranché !"; 
                       if(membre=="bras")
                       {
                            cibleP->setGants(0);
                       }
                       else
                       {
                           cibleP->setBottes(0);
                       }   
                 }
          }
          else
          {
              if(membre=="bras")
              {
                 cibleP->setGants(cibleP->getGants()-sourceP->getArme());
              }
              else
              {
                 cibleP->setBottes(cibleP->getBottes()-sourceP->getArme());
              }  
          }
     }
     
     //Attribution des dommages
     if(membre=="aucun")
     {
          cibleP->setHp(cibleP->getHp()-outputDegats);
          cout<<" (" << outputDegats << " dégâts)" << endl;
     }
     else
     {
         if(membre=="bras")
         {
             cout<<" (" << outputDegats << " malus en esquive)" << endl;
         }
         if(membre=="jambe")
         {
             cout<<" (" << outputDegats << " malus en précision)" << endl;
         }
     }
  }
 
}




/* Getteurs */
string Area::getNom()
{
    return (nom);
}

Item Area::getItem()
{
     return item;
}


/* Setteur */
void Area::setTexte(string texte)
{
     _getch(); //attente d'appui d'un touche
     cout << texte << endl << endl;
}

/* Prompt type condition oui-non */
void Area::setCondition(string question, string text_if_yes, string text_if_non)
{
  _getch();
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_BLUE);
  cout << question << endl;
  string varTemp("n");           //On crée une case mémoire pour contenir une chaine de caractères
  cin >> varTemp;
  cout << endl;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),/*FOREGROUND_INTENSITY |*/ 7);
  if(varTemp=="y")
  {
        cout << text_if_yes;
  }
  else if(varTemp=="n")
  {
      if(text_if_non=="")
      {
         cout << "Vous avez decide de ne rien faire.";
      }
      else
      {
          cout << text_if_non;
      }
      
  } 
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
  cout << endl << endl;         
}

/* Prompt type choix multiple */
int Area::setChoixMultiple(string q, string c1, string r1, string c2, string r2, string c3, string r3)
{
    _getch();
    int choix;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    cout << q << endl << endl << c1 << "   ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN); 
    cout << c2;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    cout << "   " << c3;    
    int car = getch();
    choix = waitForEnterCM(car,c1,c2,c3,1,1); 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7); 
    cout << endl << endl;
    if(choix==0)
    {
             cout << r1 << endl << endl ;
             return choix;
    }
    else if(choix==1)
    {
             cout << r2 << endl << endl ;
             return choix;
    }
    else if(choix==2)
    {
             cout << r3 << endl << endl ;
             return choix;
    }
    
                
}


/** Demarrage et gestion combat*/
void Area::setCombat(Joueur * joueurP, Personnage * adversaireP)
{
     _getch();
     srand(time(NULL));
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
     Joueur joueurTmp(joueurP);
     joueurTmp.setHp(50);
     joueurTmp.setCasque(0);
     joueurTmp.setGants(50);
     joueurTmp.setBlouson(1);
     joueurTmp.setBottes(0);
     joueurTmp.setArme(5);
     Joueur * jTmpPtr = &joueurTmp;
     cout << endl << adversaireP->getNom() << " (" << adversaireP->getHp() << " HP)       " << joueurP->getNom() << " (" << joueurP->getHp() << " HP)\n" << 
     "\nCasque  : " << adversaireP->getCasque() << "          Casque   : " << joueurP->getCasque() <<
     "\nGants   : " << adversaireP->getGants() << "         Gants   : " << joueurP->getGants() <<
     "\nBlouson : " << adversaireP->getBlouson() << "          Blouson : " << joueurP->getBlouson() <<
     "\nBottes  : " << adversaireP->getBottes() << "         Bottes  : " << joueurP->getBottes() <<
     "\nDégâts  : " << adversaireP->getCasque() << "          Dégâts  : " << joueurP->getCasque();
     //jTmpPtr->afficheInfos();
  
     int choixZone;
     int choixAttaque;
     int tour =1;
     
     
     while(adversaireP->getHp()>0 && joueurP->getHp()>0)
     {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
            cout << endl << endl << endl << "-*-*-*-*-*- TOUR " << tour << " -*-*-*-*-*-" << endl;
            tour++;
            cout << endl << "Vous : " << jTmpPtr->getHp() << " HP" << endl;
            cout << adversaireP->getNom() << " : " << adversaireP->getHp() << " HP" << endl << endl;
            
            choixZone = setChoixMultiple("Quelle zone attaquer ?",
            "Tête","Vous ciblez la tête.",
            "Buste","Vous ciblez le buste.",
            "Membres","Vous ciblez un membre.");
            
            if(choixZone!=2)
            {
                choixAttaque = setChoixMultiple("Quel type d'attaque ?",
                "Attaque frontale","",
                "Attaque rapide","",
                "Attaque lourde","");
                traitementAttaque(choixZone, choixAttaque, jTmpPtr, adversaireP);
            }
            else
            {
                traitementAttaque(2, -1, jTmpPtr, adversaireP);
            }
            _getch();
            cout << endl;
            
            //Au tour de l'adversaire d'attaquer
            if(adversaireP->getHp()>0)
            {
                choixZone = calculRandom(3);
                choixAttaque = calculRandom(3);
                traitementAttaque(choixZone, choixAttaque, adversaireP, jTmpPtr);
                _getch();
            }
            
     }
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
     if(adversaireP->getHp() <= 0)
     {
          cout << endl << "Vous avez vaincu votre adversaire." << endl; 
     }
     else
     {
         cout << endl << "Vous êtes mort. Veuillez quitter et relancer pour recharger votre zone." << endl; 
     }
     cout << "-*-*-*-*-*-" << endl << endl << endl ;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7); 
     //joueurP->afficheInfos();
}


/* Affiche et instancie un nouvel item*/
void Area::setItem(string nom, int type, int bonus)
{
     _getch();
     Item item(nom,type,bonus);
     this->item = item;

     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
     cout << "Vous vous equippez ";
     if(type == 00)
     {
           cout << "de Gants en ";
     }
     if(type == 01)
     {
           cout << "de Gants de ";
     }
     if(type == 10)
     {
           cout << "d'un Casque en ";
     }
     if(type == 11)
     {
           cout << "d'un Casque de ";
     }
     if(type == 20)
     {
           cout << "d'un Blouson en ";
     }
     if(type == 21)
     {
           cout << "d'un Blouson de ";
     }
     if(type == 30)
     {
           cout << "de Bottes en ";
     }
     if(type == 31)
     {
           cout << "de Bottes de ";
     }
     if(type == 40)
     {
           cout << "d'une Barre en ";
     }
     if(type == 41)
     {
           cout << "d'un Couteau de ";
     }
     if(type == 42)
     {
           cout << "d'un Pistolet ";
     }
     
     cout << nom << " (+" << bonus << " en ";
     if(type==00 || type==01)
     {
           cout << "précision)";
           joueurP->setGants(this->item.getBonus());
     }
     if(type==10 || type==11)
     {
           cout << "résistance tête)";
           joueurP->setCasque(this->item.getBonus());
     }
     if(type==20 || type==21)
     {
           cout << "défense)";
           joueurP->setBlouson(this->item.getBonus());
     }
     if(type==30 || type==31)
     {
           cout << "esquive)";
           joueurP->setBottes(this->item.getBonus());
     }
     if(type==40 || type==41 || type==42)
     {
           cout << "dégats)";
           joueurP->setArme(this->item.getBonus());
     }
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);  
     cout << endl << endl;
}



     
