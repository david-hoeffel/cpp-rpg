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
    setTexte("Apr�s votre trajet en Hovercraft, vous arrivez enfin au bar. Le vent\n"
    "s'�tait lev� et la pluie ne cessait de tomber. Apr�s avoir d�sactiv� votre\n"
    "Hovercraft, vous entrez dans le bar. Une athmosph�re de d�tente y r�gnait,\n"
    "malgr� le bruit des alcooliques et une forte odeur de tabac. Ayant aper�u\n" 
    "Jack, vous allez le saluer.");
    setChoixMultiple("Salut mec,",
    "Les affaires vont bien ?","Jack : Hey "+joueurP->getNom()+" !\n" 
    "Jack : Les affaires tournent, m�me si en ce moment j'ai moins de monde que\n" 
    "Jack : d'habitude. Et �a sent rien de bon. Je sais que l'Etat a parl� de\n"
    "Jack : fermer les bars du centre-ville, mais j'ai l'impression qu'ils ne\n"
    "Jack : nous ont pas tout dit sur ce coup l�.",
    "Comment tu vas ?","Jack : Salut "+joueurP->getNom()+".\n"
    "Jack : Dis donc ca fait un p'tit bout de temps que j'tai plus vu ! Quel temps de"
    "Jack : chien ! On dirait que quelque chose fait fuir mes clients...",
    "Faut que je te montre un truc","Jack : Salut "+joueurP->getNom()+".\n"
    "Jack : Dis donc t'as l'air press� ! Je vais voir ce que je peux faire pour toi.");
    setTexte("Vous d�cidez de sortir l'objet sph�rique de votre poche et de lui montrer.");
    setTexte("Jack : Hmm... je reconnais cet objet...");
    setTexte("Jack : C'est un proto-neon, un petit bijoux qu'on ne croise pas tous les jours.");
    setTexte("Jack : Il peut servir � t'�clairer dans des endroits obscurs, mais poss�de\n"
    "aussi des ports d'extension qui permettent de lui ajouter des fonctionnalit�s.");
    setTexte("Jack : Si j'�tais toi, je le revendrais pas tout de suite ! Haha !");
    setTexte("Jack : Ca ce met autour de l'oreille, et �a s'implante ensuite dans\n"
    "la chair pour te transmettre en temps r�el les informations. Attention,\n"
    "ca risque de chatouiller...");
    setTexte("Vous d�cidez de mettre le proto-neon en place sur votre oreille.\n"
    "L'objet se fixe sur votre cr�ne dans un picotement �lectrique. Il s'auto-\n"
    "calibre puis affiche votre �tat.");
    _getch();
    joueurP->afficheInfos();
    setTexte("Vous remerciez Jack et lui proposez un verre pour discuter un peu,\n"
    "puis d�cidez de rentrer apr�s avoir profit� d'un Streets of Rage, un\n"
    "vestige du pass� pour l'an 2047.");
    setTexte("Longeant une ruelle pour reprendre votre Hoverbike, vous remarquez\n"
    "un curieux en train de tenter de vous voler votre v�hicule.\n");
    setChoixMultiple("Que faire ?","Hurler au secours","Le voleur remarque votre pr�sence.",
    "D�clencher la protection �lectrique","Le voleur prend une d�charge et se retourne.",
    "Fuir","Le voleur vous remarque et vous jette un regard sanglant.");
    setTexte("Trop tard. Il se rue sur vous et vous force � lui donner votre code\n"
    "de s�curit�, sauf que vous n'�tes pas cet avis.");
    joueurP->setHp(50);
    //joueurP->afficheInfos();
    setTexte("Vous parvenez � le renverser de c�t�, mais le voleur se rel�ve et vous\n"
    "plaque contre un mur, sortant un couteau. Vous voyant vous d�battre, il\n"
    "commence � vous �trangler, et le monde autour de vous commence � s'�vanouir...");
    setTexte("Alors que tout semble perdu, votre proto-neon aveugle le voleur de sa\n"
    "lumi�re.");
    setChoixMultiple("Vous saisissez cette occasion pour...",
    "Crever l'oeil du malfrat","Le voleur se tord de douleur et recule d'un pas.",
    "Lui faire un coup de boule","Sonn�, le voleur chanc�le et hurle face � votre affront.",
    "Lui cracher au visage","Le voleur met sa main devant son visage.");
    setTexte("Son couteau tombe au sol et vous le ramassez.\n"
    "Il faut en finir.");
    setItem("brigand",41,5);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    setTexte("--- MESSAGE DU PROTO-NEON ---");
    setTexte("Vous allez entrer en combat. Pour obtenir la victoire, il faut �tre\n"
    "vigilant sur vos possibilit�s.");
    setTexte("Votre taux d'esquive est d�termin� par vos Bottes.\n"
    "Votre taux de pr�cision (=coups critiques) est d�termin� par vos Gants.\n"
    "Votre Casque prot�ge votre t�te et votre Blouson prot�ge votre buste.");
    setTexte("Attaquer un membre ne fait pas de dommages � l'adversaire, mais applique les\n"
    "d�g�ts de votre arme soit sur le taux d'esquive, soit sur le taux de pr�cision\n"
    "de votre adversaire.");
    setTexte("Pour infliger des d�g�ts � votre adversaire, il vous faut attaquer son buste ou\n"
    "sa t�te. Un coup critique peut d�capiter votre adversaire ou le d�membrer\n" 
    "(r�duire son taux d'esquive ou de coup critique � 0).");
    setTexte("Un coup rapide � 100% de chances de r�ussir.\n"
    "Un coup lourd peut multiplier vos d�g�ts par 2.\n"
    "Un coup frontal peut d�truire l'�quipement associ� � la zone vis�e.");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    Personnage voleur("Voleur",20,1,20,1,20,2);
    setCombat(joueurP,&voleur);
    setTexte("D�stabilis� par le meurtre que vous venez de commettre, vous chancelez et vous\n"
    "vous �vanouissez.");
}


     
