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
    setTexte("Vous �tes seul dans votre chambre � contempler par la fen�tre ce\n"
    "spectacle d�solant. Les lumi�res sont �teintes et vous vous avachissez\n"
    "sur votre lit. Dans les t�n�bres de la pi�ce, vous remarquez un objet brillant.");
    setCondition("Le prendre ?","Vous t�tez l'objet, et remarquez qu'il est de forme sph�rique.\n"
    "Il est l�ger et pourvu d'un cordon optique l'entourant.\n"
    "Vous allumez les n�ons de votre chambre."
    ,"Attis� par votre curiosit�, vous d�cidez plut�t d'allumer les n�ons pour y voir plus clair.");
    setTexte("Vous inspectez l'objet, perplexe. Soudain, vous r�alisez que vous l'avez d�j�\n"
    "vu quelque part... Des souvenirs se bousculent dans votre t�te.");
    setChoixMultiple("O� l'avez-vous vu ?",
    "A la t�l�vision","En effet, il semblerait qu'il y en avait dans le dernier remake de Blade Runner.A moins que...",
    "Chez un ami","Un ami se ventait d'avoir achet� un objet r�volutionnaire, avant de r�aliser\nqu'il s'�tait fait arnaquer.",
    "Vous d�lirez","Non, vous ne savez pas du tout ce qu'est cet objet. Pourtant quelque chose\nvous intrigue...");
    setTexte("Vous d�cidez d'aller rendre visite � Jack, votre ami de longue date tenant un\n"
    "bar pas loin du centre-ville. Il en sait sans doute d'avantage sur cet objet.\n"
    "Vous saisissez vos gants et votre blouson avant de partir avec votre Hoverbike.");
    setItem("Hoverbike",01,50); //Gants
    setItem("microfibres",20,1); //Blouson
}


     
