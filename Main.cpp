#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
//#include "Console/ConsoleLogger.h"
#include "Storylines/Storyline0.hpp"
#include "Storylines/Storyline1.hpp"
#define NB_STORYLINES 2
using namespace std;




/* Affichage des regles du jeu */
void afficherRegles()
{
     cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl <<endl;     
     cout << "Bienvenue !\n\n\n"
     <<"Dungeon Slayer est un petit projet étudiant de jeu de rôle, en quelque sorte un\n\n"
     <<"\"visual novel\" en console !\n\n\n";
     _getch();
     cout << "Les règles du jeu sont simples :\n\n"
     <<"-les questions oui/non doivent être répondues en tapant \"y\" ou \"n\" en console.\n\n"
     <<"-les questions ouvertes doivent être répondues en un seul mot ou nombre.\n\n"
     <<"-les QCM permettent de sélectionner directement un choix.\n\n\n";
     _getch();
     cout << "Alors détendez-vous - Ce jeu est fait pour vous faire vivre une expérience\n\n"
     <<"originale et divertissante ! ... Bon jeu ;) \n\n\n";
     //_getch();
     cout <<"* Les sauvegardes sont effectuées automatiquement à la fin de chaque zone *\n\n" << endl;
     cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl;
     _getch();
}




/* Affichage de l'ecran titre */
void drawEcranTitre()
{     
    /* LEXIQUE DESSIN -----------------------------------
    *
    * 0xDa = VERTICAL HT DTE
    * 0xBF = VERTICAL HT GCHE
    * 0xC4 = HORIZONTAL
    * 0xB3 = VERTICAL BIG
    * '\n' = RC
    * 0xC0 = VERTICAL BAS DTE
    * 0xD9 = VERTICAL BAS GCHE
    *
    * print example : cout << (char)0xBF;
    *
    */

    /* HRZT HAUT */
    cout << endl <<  "               ";
    for(int i=0; i<6 ;i++)
    { 
      if(i==5)
      {
            cout << (char)0xBF;
      }
      else
      {
           cout << (char)0xC4;
      }
     
    }
    cout << endl;
    
    /* VERTIC DTE ET GCHE */
    for(int i=0; i<2 ;i++)
    { 
      if(i==0)
      {
            cout << "               " << (char)0xDa << (char)0xC4 << (char)0xC4  
            << (char)0xBF << " " << (char)0xB3 << endl;
      }
      else
      {
           cout << "               " << (char)0xB3 << "    " << (char)0xB3;
           cout << endl;
      }
     
    }  
    cout << "DUNGEON SLAYER ";
   
    /* VERTIC DTE ET GCHE */
    for(int i=0; i<5 ;i++)
    { 
      if(i==0)
      {
            cout << (char)0xC0;
      }
      if(i==4)
      {
            cout << (char)0xD9;
      }
      else
      {
           cout << (char)0xC4;
      }
     
    }  
    cout << " UNLIMITED EDITION" << endl << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl << endl << endl;    
}




/* MAIN */
int main(int argc, char *argv[])
{   
    //--CREATE 2nd CONSOLE
    /*CConsoleLoggerEx coloured_console;
    coloured_console.Create("This is the first console");
    coloured_console.printf("WOW !!! COOLL !!! another console ???");
    coloured_console.cls(CConsoleLoggerEx::COLOR_BACKGROUND_RED);
	coloured_console.gotoxy(10,10);
	coloured_console.cprintf( CConsoleLoggerEx::COLOR_WHITE| 
                              CConsoleLoggerEx::COLOR_BACKGROUND_BLUE,"White on Blue");*/
    
   //--SET CONSOLE POSITION
   //HWND hConsole = GetConsoleWindow();
   //MoveWindow(hConsole, 1, 1, 800, 600, TRUE);

   //--SET CONSOLE SIZE
   /*SMALL_RECT windowSize = {0, 0, 1000, 2};
   SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);*/

    SetConsoleTitle("DUNGEON SLAYER 2013          release 0.1         David Hoeffel");
    drawEcranTitre();
    setlocale(LC_ALL,""); //Permet d'afficher les accents
    
    cout << "Charger la sauvegarde ? (tapez y ou n puis appuyez sur ENTREE)" << endl;
    string choixSav("n");
    cin >> choixSav;
    cout << endl << endl << endl <<endl;
    
    Storyline* tab_storylines[NB_STORYLINES];
    

    if(choixSav == "y")
    {
         Joueur joueur(1);
         Joueur *joueurP = &joueur;
         joueurP->afficheInfos();
         Storyline0* storyline0 = new Storyline0(0,"Funeste Destin",joueurP,2);
         Storyline1* storyline1 = new Storyline1(1,"STORYLINE 1",joueurP,1);
         tab_storylines[0] = storyline0;
         tab_storylines[1] = storyline1;         
         int etapeStoryline = joueurP->getStoryline();
         int etapeArea = joueurP->getArea(); //recuperation de la zone sauvegardee        
         for(etapeStoryline;etapeStoryline<NB_STORYLINES;++etapeStoryline)
         {
            tab_storylines[etapeStoryline]->processStory(etapeArea); 
            etapeArea=0;  
         }
         joueurP->afficheInfos();
    }  
    else
    {
         afficherRegles();
         Joueur joueur(false);
         Joueur *joueurP = &joueur;
         Storyline0* storyline0 = new Storyline0(0,"Funeste Destin",joueurP,2);
         Storyline1* storyline1 = new Storyline1(1,"STORYLINE 1",joueurP,1);
         tab_storylines[0] = storyline0;
         tab_storylines[1] = storyline1;         
         int etapeStoryline = joueurP->getStoryline();
         int etapeArea = joueurP->getArea(); //recuperation de la zone sauvegardee         
         for(etapeStoryline;etapeStoryline<NB_STORYLINES;++etapeStoryline)
         {
            tab_storylines[etapeStoryline]->processStory(etapeArea);
            etapeArea=0;   
         }
         joueurP->afficheInfos();  
    }
     
    system("PAUSE");
    return EXIT_SUCCESS;
}



     


