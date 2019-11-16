#include "Bar.hpp"


/* Constructeur par defaut */
Bar::Bar()
{
              
}


/* Constructeur avec nom*/
Bar::Bar(string nom, Joueur * joueurP)
{
    this->nom = nom;
    this->joueurP = joueurP;  
    Area(this->nom,this->joueurP);
}


/* Destructeur */
Bar::~Bar()
{
    //dtor
}


/* Affiche l'etat du personnage */
void Bar::afficheInfos()
{
    Area::afficheInfos();
    setTexte("Après votre trajet en Hovercraft, vous arrivez enfin au bar. Le vent\n"
    "s'était levé et la pluie ne cessait de tomber. Après avoir désactivé votre\n"
    "Hovercraft, vous entrez dans le bar. Une athmosphère de détente y régnait,\n"
    "malgré le bruit des alcooliques et une forte odeur de tabac. Ayant aperçu\n" 
    "Jack, vous allez le saluer.");
    setChoixMultiple("Salut mec,",
    "Les affaires vont bien ?","Jack : Hey "+joueurP->getNom()+" !\n" 
    "Jack : Les affaires tournent, même si en ce moment j'ai moins de monde que\n" 
    "Jack : d'habitude. Et ça sent rien de bon. Je sais que l'Etat a parlé de\n"
    "Jack : fermer les bars du centre-ville, mais j'ai l'impression qu'ils ne\n"
    "Jack : nous ont pas tout dit sur ce coup là.",
    "Comment tu vas ?","Jack : Salut "+joueurP->getNom()+".\n"
    "Jack : Dis donc ca fait un p'tit bout de temps que j'tai plus vu ! Quel temps de"
    "Jack : chien ! On dirait que quelque chose fait fuir mes clients...",
    "Faut que je te montre un truc","Jack : Salut "+joueurP->getNom()+".\n"
    "Jack : Dis donc t'as l'air pressé ! Je vais voir ce que je peux faire pour toi.");
    setTexte("Vous décidez de sortir l'objet sphérique de votre poche et de lui montrer.");
    setTexte("Jack : Hmm... je reconnais cet objet...");
    setTexte("Jack : C'est un proto-neon, un petit bijoux qu'on ne croise pas tous les jours.");
    setTexte("Jack : Il peut servir à t'éclairer dans des endroits obscurs, mais possède\n"
    "aussi des ports d'extension qui permettent de lui ajouter des fonctionnalités.");
    setTexte("Jack : Si j'étais toi, je le revendrais pas tout de suite ! Haha !");
    setTexte("Jack : Ca ce met autour de l'oreille, et ça s'implante ensuite dans\n"
    "la chair pour te transmettre en temps réel les informations. Attention,\n"
    "ca risque de chatouiller...");
    setTexte("Vous décidez de mettre le proto-neon en place sur votre oreille.\n"
    "L'objet se fixe sur votre crâne dans un picotement électrique. Il s'auto-\n"
    "calibre puis affiche votre état.");
    _getch();
    joueurP->afficheInfos();
    setTexte("Vous remerciez Jack et lui proposez un verre pour discuter un peu,\n"
    "puis décidez de rentrer après avoir profité d'un Streets of Rage, un\n"
    "vestige du passé pour l'an 2047.");
    setTexte("Longeant une ruelle pour reprendre votre Hoverbike, vous remarquez\n"
    "un curieux en train de tenter de vous voler votre véhicule.\n");
    setChoixMultiple("Que faire ?","Hurler au secours","Le voleur remarque votre présence.",
    "Déclencher la protection électrique","Le voleur prend une décharge et se retourne.",
    "Fuir","Le voleur vous remarque et vous jette un regard sanglant.");
    setTexte("Trop tard. Il se rue sur vous et vous force à lui donner votre code\n"
    "de sécurité, sauf que vous n'êtes pas cet avis.");
    joueurP->setHp(50);
    //joueurP->afficheInfos();
    setTexte("Vous parvenez à le renverser de côté, mais le voleur se relève et vous\n"
    "plaque contre un mur, sortant un couteau. Vous voyant vous débattre, il\n"
    "commence à vous étrangler, et le monde autour de vous commence à s'évanouir...");
    setTexte("Alors que tout semble perdu, votre proto-neon aveugle le voleur de sa\n"
    "lumière.");
    setChoixMultiple("Vous saisissez cette occasion pour...",
    "Crever l'oeil du malfrat","Le voleur se tord de douleur et recule d'un pas.",
    "Lui faire un coup de boule","Sonné, le voleur chancèle et hurle face à votre affront.",
    "Lui cracher au visage","Le voleur met sa main devant son visage.");
    setTexte("Son couteau tombe au sol et vous le ramassez.\n"
    "Il faut en finir.");
    setItem("brigand",41,5);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    setTexte("--- MESSAGE DU PROTO-NEON ---");
    setTexte("Vous allez entrer en combat. Pour obtenir la victoire, il faut être\n"
    "vigilant sur vos possibilités.");
    setTexte("Votre taux d'esquive est déterminé par vos Bottes.\n"
    "Votre taux de précision (=coups critiques) est déterminé par vos Gants.\n"
    "Votre Casque protège votre tête et votre Blouson protège votre buste.");
    setTexte("Attaquer un membre ne fait pas de dommages à l'adversaire, mais applique les\n"
    "dégâts de votre arme soit sur le taux d'esquive, soit sur le taux de précision\n"
    "de votre adversaire.");
    setTexte("Pour infliger des dégâts à votre adversaire, il vous faut attaquer son buste ou\n"
    "sa tête. Un coup critique peut décapiter votre adversaire ou le démembrer\n" 
    "(réduire son taux d'esquive ou de coup critique à 0).");
    setTexte("Un coup rapide à 100% de chances de réussir.\n"
    "Un coup lourd peut multiplier vos dégâts par 2.\n"
    "Un coup frontal peut détruire l'équipement associé à la zone visée.");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    Personnage voleur("Voleur",20,1,20,1,20,2);
    setCombat(joueurP,&voleur);
    setTexte("Déstabilisé par le meurtre que vous venez de commettre, vous chancelez et vous\n"
    "vous évanouissez.");
}


     
