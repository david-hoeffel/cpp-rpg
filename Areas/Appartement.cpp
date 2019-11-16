#include "Appartement.hpp"


/* Constructeur par defaut */
Appartement::Appartement()
{

}


/* Constructeur avec nom*/
Appartement::Appartement(string nom, Joueur * joueurP)
{
    this->joueurP = joueurP;  
    this->nom = nom;
    Area(this->nom,this->joueurP);
}


/* Destructeur */
Appartement::~Appartement()
{
    //dtor
}


/* Affiche l'etat du personnage */
void Appartement::afficheInfos()
{
    Area::afficheInfos();
    setTexte("Vous êtes seul dans votre chambre à contempler par la fenêtre ce\n"
    "spectacle désolant. Les lumières sont éteintes et vous vous avachissez\n"
    "sur votre lit. Dans les ténèbres de la pièce, vous remarquez un objet brillant.");
    setCondition("Le prendre ?","Vous tâtez l'objet, et remarquez qu'il est de forme sphérique.\n"
    "Il est léger et pourvu d'un cordon optique l'entourant.\n"
    "Vous allumez les néons de votre chambre."
    ,"Attisé par votre curiosité, vous décidez plutôt d'allumer les néons pour y voir plus clair.");
    setTexte("Vous inspectez l'objet, perplexe. Soudain, vous réalisez que vous l'avez déjà\n"
    "vu quelque part... Des souvenirs se bousculent dans votre tête.");
    setChoixMultiple("Où l'avez-vous vu ?",
    "A la télévision","En effet, il semblerait qu'il y en avait dans le dernier remake de Blade Runner.A moins que...",
    "Chez un ami","Un ami se ventait d'avoir acheté un objet révolutionnaire, avant de réaliser\nqu'il s'était fait arnaquer.",
    "Vous délirez","Non, vous ne savez pas du tout ce qu'est cet objet. Pourtant quelque chose\nvous intrigue...");
    setTexte("Vous décidez d'aller rendre visite à Jack, votre ami de longue date tenant un\n"
    "bar pas loin du centre-ville. Il en sait sans doute d'avantage sur cet objet.\n"
    "Vous saisissez vos gants et votre blouson avant de partir avec votre Hoverbike.");
    setItem("Hoverbike",01,50); //Gants
    setItem("microfibres",20,1); //Blouson
}


     
