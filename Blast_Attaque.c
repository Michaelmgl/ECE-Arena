#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

///Meilleurs disposition de code actuelle Pour Blast



///Meilleurs disposition de code actuelle Pour Blast


void initialistionAllegro()
{
    allegro_init();
    set_color_depth(desktop_color_depth());
    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0))!=0)
    {
        allegro_message("Pb de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    install_keyboard();
    install_mouse();
}

typedef struct Perso{
    int element; //ira de 0 à 3 et permet de savoir quelle classe/perso le joueur a choisi (0 = terre ; 1 = eau ; 2 = feu ; 3 = air)
    int ptsvie; /// correspond aux points de vie de chaque perso, ils seront différents selon les personnages
    int ptsatt; // correspond aux points d'attaque de base, c'est le nombre de dégats de base que les persos
    int ptsmagie; /// correspond aux dégâts magiques des attaques de sort, ce sont ces points là qui prennent en compte les éléments
    int ptsdef; // correspond aux points de défense de chaque perso, ils seront différents selon les personnages (peut-être qu'ils seront altérables durant la partie)
    int ptsact; /// correspond aux points d'actions de chaque personnage, si il est égal à 3, le personnage pourra faire jusqu'à trois actions durant son tour, ils seront différents selon le personnage
    int ptsmouv; // correspond aux points de mouvements, il sera le même pour tous les personnages (à moins que ce soit trop déséquilibré...)
    int attultime; /// correspond au nombre de dégâts de l'attaqye ultime de chaque personnage, elle diffère selon les personnages et prend en compte les éléments
    int recharge;//correspond à la recharge de l'attaque ultime, il commencera à 0, et à chaque fois que le perso attaque, il s'incrémentera de 1, une fois à 5, il pourra utiliser son attaque ultime, une fois utilisée, cette variable retombe à 0
    int boostdef;///initié à 0, si égal à 1 alors les points de défense augmente de 100 et le restent pour 2 tours
    int boostatt;//initié à 0, si égal à 1, alors les points d'attaque et les points magie augmentent tout les deux de 100 pendant 2 tours
    int boostmag;
    int boostmouv;
    int boostcrit;
    int brulure;
    int jaugemagie;///différente selon les persos, elle sert à réguler l'utilisation des attaques de sorts, cett
    int numeroPassage;
    int i;///Pour le bouger plus facilement dans le tableau
    int j;
    float x;///Pour bouger les sprites
    float y;
}t_perso;

///Axe Blow
void Blast_AB(t_perso Personnage, BITMAP * DoubleB)
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y;

    BITMAP*Mouvement[2];

    BITMAP*danseuse1 = load_bitmap("B0.bmp", NULL);
    BITMAP*danseuse2 = load_bitmap("B1.bmp", NULL);
    BITMAP*danseuse3 = load_bitmap("B0.bmp", NULL);
    BITMAP*danseuse4 = load_bitmap("B1.bmp", NULL);


    Mouvement[0]= danseuse1;
    Mouvement[1]= danseuse2;
    Mouvement[2]= danseuse3;
    Mouvement[3]= danseuse4;


    int i = 0;
    int s = 0;
    int j=0;

    for (s=0;s<1;s++)
            {
            for(j=0;j<4;j++)
            {
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);

            rest(100);

            clear_bitmap(DoubleB);

            draw_sprite(DoubleB,Mouvement[j],x,y);
            }


            }
}

///Ice Eyes
void Blast_IE(t_perso Personnage, BITMAP * DoubleB)
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y;

    BITMAP*Mouvement[4];

    BITMAP*danseuse1 = load_bitmap("B0.bmp", NULL);
    BITMAP*danseuse2 = load_bitmap("B4.bmp", NULL);
    BITMAP*danseuse3 = load_bitmap("B5.bmp", NULL);
    BITMAP*danseuse4 = load_bitmap("B6.bmp", NULL);

    Mouvement[0]= danseuse1;
    Mouvement[1]= danseuse2;
    Mouvement[2]= danseuse3;
    Mouvement[3]= danseuse4;

     int i = 0;
     int j = 0;
     for (i=0;i<1;i++)
        {
        for(j=0;j<4;j++)
            {
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);

            rest(100);

            clear_bitmap(DoubleB);

            draw_sprite(DoubleB,Mouvement[j],x,y);
            }

        }
}
///Doom
void Blast_D(t_perso Personnage, BITMAP * DoubleB)
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y;

    BITMAP*Mouvement[6];

    BITMAP*danseuse1 = load_bitmap("B0.bmp", NULL);
    BITMAP*danseuse2 = load_bitmap("B28.bmp", NULL);
    BITMAP*danseuse3 = load_bitmap("B29.bmp", NULL);
    BITMAP*danseuse4 = load_bitmap("B30.bmp", NULL);
    BITMAP*danseuse5 = load_bitmap("B31.bmp", NULL);
    BITMAP*danseuse6 = load_bitmap("B32.bmp", NULL);

    Mouvement[0]= danseuse1;
    Mouvement[1]= danseuse2;
    Mouvement[2]= danseuse3;
    Mouvement[3]= danseuse4;
    Mouvement[4]= danseuse5;
    Mouvement[5]= danseuse6;

    int s = 0;
    int j = 0;
        for (s=0;s<1;s++)
            {
           for(j=0;j<6;j++)
            {
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);

            rest(100);

            clear_bitmap(DoubleB);

            draw_sprite(DoubleB,Mouvement[j],x,y);
            }
            rest(100);
            }
}
///Born In Hell
void Blast_BIH(t_perso Personnage, BITMAP * DoubleB)
{
     int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y;

    BITMAP*Mouvement[4];

    BITMAP*danseuse1 = load_bitmap("B0.bmp", NULL);
    BITMAP*danseuse2 = load_bitmap("B34.bmp", NULL);
    BITMAP*danseuse3 = load_bitmap("B35.bmp", NULL);
    BITMAP*danseuse4 = load_bitmap("B36.bmp", NULL);

    Mouvement[0]= danseuse1;
    Mouvement[1]= danseuse2;
    Mouvement[2]= danseuse3;
    Mouvement[3]= danseuse4;


    int j = 0;
    int s = 0;

     for (s=0;s<1;s++)
            {
         for(j=0;j<4;j++)
            {
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);

            rest(100);

            clear_bitmap(DoubleB);

            draw_sprite(DoubleB,Mouvement[j],x,y);
            }
            rest(100);

            }
}

///Blizzard
void Blast_B(t_perso Personnage, BITMAP * DoubleB)
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y;

    BITMAP*Mouvement[8];

    BITMAP*danseuse1 = load_bitmap("B0.bmp", NULL);
    BITMAP*danseuse2 = load_bitmap("B10.bmp", NULL);
    BITMAP*danseuse3 = load_bitmap("B11.bmp", NULL);
    BITMAP*danseuse4 = load_bitmap("B12.bmp", NULL);
    BITMAP*danseuse5 = load_bitmap("B13.bmp", NULL);
    BITMAP*danseuse6 = load_bitmap("B14.bmp", NULL);
    BITMAP*danseuse7 = load_bitmap("B15.bmp", NULL);
    BITMAP*danseuse8 = load_bitmap("B16.bmp", NULL);
    //BITMAP*danseuse9 = load_bitmap("B17.bmp", NULL);

    Mouvement[0]= danseuse1;
    Mouvement[1]= danseuse2;
    Mouvement[2]= danseuse3;
    Mouvement[3]= danseuse4;
    Mouvement[4]= danseuse5;
    Mouvement[5]= danseuse6;
    Mouvement[6]= danseuse7;
    Mouvement[7]= danseuse8;
    //Mouvement[8]= danseuse9;

    int j =0;
    int s = 0;
     for (s=0;s<1;s++)
            {
           for(j=0;j<8;j++)
            {
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);

            rest(100);

            clear_bitmap(DoubleB);

            draw_sprite(DoubleB,Mouvement[j],x,y);
            }
            rest(100);
            }
}

int main()
{
    ///Initialisation Allegro
    initialistionAllegro();

    set_color_depth(desktop_color_depth());
    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0))!=0)
    {
        allegro_message("Pb de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    install_keyboard();
    install_mouse();

    //declaration de variables
    BITMAP * Brute;
    BITMAP * DoubleB;
    DoubleB =  create_bitmap(SCREEN_W,SCREEN_H);

    int x=0;
    int y=0;

    //initialisation allegro mis dans un sous-programme

    install_keyboard();
    install_mouse();

    t_perso Blast;

    Blast.x = 100;
    Blast.y = 400;


   /*//chargement de l'image
    danseuse = load_bitmap("Y0.bmp",NULL); //"posturebase" c'est juste le nom de mon sprite de base
    DoubleB = create_bitmap(SCREEN_W, SCREEN_H);// ne plus écrire 800 et 600
    masked_blit(danseuse, DoubleB, 0,0,x,y, danseuse->w, danseuse->h); //pour pouvoir déplacer le sprite en même temps que l'animation il va falloir jouer avec les 0
    blit(DoubleB, screen, 0,0,0,0, DoubleB->w, DoubleB->h);            //présents dans ces deux lignes de codes à chaque fois, je suppose qu'il faudra alors les remplacer
   */

    Brute = load_bitmap("Y0.bmp", NULL);
    if(!Brute)
    {
        allegro_message("Problemo");
        allegro_exit();
        exit(EXIT_FAILURE);
    }                                 //par les coordonnées de chaque perso, d'où la nécessité de d'abord mettre à jour les coordonnées
    show_mouse(screen);

    while(!key[KEY_ESC])                                               // avant de commencer à animer
    {
    //Yoru_base(x,y,DoubleB,Soldat);

    clear_bitmap(DoubleB);

    if (mouse_x>=65 && mouse_x <=199 && mouse_y>=540 && mouse_y <=600)  //la condtion de cette boucle est0 arbitraire, évidemment on changera en fonction des besoins mais ce ne sera jamais cette condition spécifique en jeu
    {
         if (mouse_b&1)
         {
              Blast_AB(Blast,DoubleB);
         }

    }
    if (mouse_x>=200 && mouse_x <=334 && mouse_y>=540 && mouse_y <=600)  //la condtion de cette boucle est0 arbitraire, évidemment on changera en fonction des besoins mais ce ne sera jamais cette condition spécifique en jeu
    {
        if (mouse_b&1)
         {
              Blast_IE(Blast,DoubleB);
         }
    }
    if (mouse_x>=335 && mouse_x <=469 && mouse_y>=540 && mouse_y <=600)  //la condtion de cette boucle est0 arbitraire, évidemment on changera en fonction des besoins mais ce ne sera jamais cette condition spécifique en jeu
    {
         if (mouse_b&1)
         {
              Blast_D(Blast,DoubleB);
         }
    }
    if (mouse_x>=470 && mouse_x <=604 && mouse_y>=540 && mouse_y <=600)  //la condtion de cette boucle est0 arbitraire, évidemment on changera en fonction des besoins mais ce ne sera jamais cette condition spécifique en jeu
    {
      if (mouse_b&1)
         {
              Blast_BIH(Blast,DoubleB);
         }
    }


        if (mouse_x>=605 && mouse_x <=739 && mouse_y>=540 && mouse_y <=600)  //la condtion de cette boucle est0 arbitraire, évidemment on changera en fonction des besoins mais ce ne sera jamais cette condition spécifique en jeu
    {
      if (mouse_b&1)
         {
              Blast_B(Blast,DoubleB);
         }
    }
    }

    printf("FIN!\n");
    return 0;
}END_OF_MAIN();
