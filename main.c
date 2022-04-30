#include <stdio.h>
#include <stdlib.h>
#define NBR_MAX_DE_JOUEURS 4


typedef struct Perso{
    int element; //ira de 0 à 3 et permet de savoir quelle classe/perso le joueur a choisi (0 = terre ; 1 = eau ; 2 = feu ; 3 = air)
    int ptsvie; /// correspond aux points de vie de chaque perso, ils seront différents selon les personnages
    int ptsatt; // correspond aux points d'attaque de base, c'est le nombre de dégats de base que les persos prendre en compte les elements puiqsue c'est juste une attaque simple
    int ptsmagie; /// correspond aux dégâts magiques des attaques de sort, ce sont ces points là qui prennent en compte les éléments
    int ptsdef; // correspond aux points de défense de chaque perso, ils seront différents selon les personnages (peut-être qu'ils seront altérables durant la partie)
    int ptsact; /// correspond aux points d'actions de chaque personnage, si il est égal à 3, le personnage pourra faire jusqu'à trois actions durant son tour, ils seront différents selon le personnage
    int ptsmouv; // correspond aux points de mouvements, il sera le même pour tous les personnages (à moins que ce soit trop déséquilibré...)
    int attultime; /// correspond au nombre de dégâts de l'attaqye ultime de chaque personnage, elle diffère selon les personnages et prend en compte les éléments
    int recharge;//correspond à la recharge de l'attaque ultime, il commencera à 0, et à chaque fois que le perso attaque, il s'incrémentera de 1, une fois à 5, il pourra utiliser son attaque ultime, une fois utilisée, cette variable retombe à 0
}t_perso;

int choixNbrJoueurs(int nbrJoueurs)
{
    printf("Combien de joueurs ?\n");
    scanf("%d", &nbrJoueurs);
    return nbrJoueurs;
}

void choixDesClasses(t_perso tablo[NBR_MAX_DE_JOUEURS], int nbrjoueurs)
{
    int i = 0;
    while(i < nbrjoueurs)
    {
        printf("Joueur %d , veuillez choisir une classe\n", i+1);
        scanf("%d", &tablo[i].element);
        if (tablo[i].element == 0)
        {
            printf("Vous avez choisi le soldat de terre\n");
            tablo[i].ptsvie = 2300;
            tablo[i].ptsatt = 380;
            tablo[i].ptsdef = 250;
            tablo[i].ptsmagie = 450;
            tablo[i].ptsact = 3;
            tablo[i].ptsmouv = 3;
            tablo[i].attultime = 700;
            tablo[i].recharge = 0;
        }
        else if(tablo[i].element == 1)
        {
            printf("Vous avez choisi la brute de l'eau\n");
            tablo[i].ptsvie = 2500;
            tablo[i].ptsatt = 400;
            tablo[i].ptsdef = 220;
            tablo[i].ptsmagie = 430;
            tablo[i].ptsact = 2;
            tablo[i].ptsmouv = 3;
            tablo[i].attultime = 750;
            tablo[i].recharge = 0;
        }
        else if(tablo[i].element == 2)
        {
            printf("Vous avez choisi le mage de feu\n");
            tablo[i].ptsvie = 2200;
            tablo[i].ptsatt = 290;
            tablo[i].ptsdef = 300;
            tablo[i].ptsmagie = 500;
            tablo[i].ptsact = 3;
            tablo[i].ptsmouv = 3;
            tablo[i].attultime = 800;
            tablo[i].recharge = 0;
        }
        else if (tablo[i].element == 3)
        {
            printf("Vous avez choisi la danseuse de l'air\n");
            tablo[i].ptsvie = 2000;
            tablo[i].ptsatt = 350;
            tablo[i].ptsdef = 290;
            tablo[i].ptsmagie = 480;
            tablo[i].ptsact = 4;
            tablo[i].ptsmouv = 3;
            tablo[i].attultime = 820;
            tablo[i].recharge = 0;
        }
        i= i+1;
    }
}

int main()
{
    int nombreDeJoueurs = 0;
    t_perso joueurs[NBR_MAX_DE_JOUEURS];
    nombreDeJoueurs = choixNbrJoueurs(nombreDeJoueurs);
    choixDesClasses(joueurs, nombreDeJoueurs);
    printf("Le joueur 2 a une attaque de %d", joueurs[1].ptsatt);
    return 0;
}
