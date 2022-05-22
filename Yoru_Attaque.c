#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>


///Meilleurs disposition de code actuelle


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

void draw_sprite(BITMAP *bmp, BITMAP *sprite, int x, int y);

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

typedef struct cases{

    //coordonnees de la case
    float x;
    float y;

    //Tailles d'une case
    int longueur;
    int largeur;

    //1 si occupe/obstacle et 0 si libre
    int libre;

    //pour ce qui se trouve sur la case utile ?
    BITMAP * image;

}t_case;

void Yoru_base(int x ,int y ,BITMAP* DoubleB, BITMAP * danseuse)
{
    danseuse = load_bitmap("Y0.bmp", NULL);
    if(!danseuse)
    {
        allegro_message("Problemo");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
    //blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
    //blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
}

///Rocky Punch
void Yoru_RP(t_perso Personnage, BITMAP * DoubleB)//BITMAP * danseuse,BITMAP* Terrain
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y;

    BITMAP*Mouvement[5];

    BITMAP*danseuse1 = load_bitmap("Y90.bmp", NULL);
    BITMAP*danseuse2 = load_bitmap("Y91.bmp", NULL);
    BITMAP*danseuse3 = load_bitmap("Y92.bmp", NULL);
    BITMAP*danseuse4 = load_bitmap("Y93.bmp", NULL);
    BITMAP*danseuse5 = load_bitmap("Y94.bmp", NULL);
    //BITMAP*danseuse6 = load_bitmap("Y95.bmp", NULL);

    Mouvement[0]= danseuse1;
    Mouvement[1]= danseuse2;
    Mouvement[2]= danseuse3;
    Mouvement[3]= danseuse4;
    Mouvement[4]= danseuse5;
    //Mouvement[5]= danseuse6;

    int i;


    int s = 0;
    for (s=0;s<1;s++)
            {
            for(int i=0;i<5;i++)
            {
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);

            rest(100);

            clear_bitmap(DoubleB);

            draw_sprite(DoubleB,Mouvement[i],x,y);
            }
            rest(100);
            }
}

///Rock Smash
void Yoru_RS(t_perso Personnage, BITMAP * DoubleB)
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y;


    BITMAP*Mouvement[4];

    BITMAP*danseuse1 = load_bitmap("Y23.bmp", NULL);
    BITMAP*danseuse2 = load_bitmap("Y25.bmp", NULL);
    BITMAP*danseuse3 = load_bitmap("Y26.bmp", NULL);
    BITMAP*danseuse4 = load_bitmap("Y27.bmp", NULL);


    Mouvement[0]= danseuse1;
    Mouvement[1]= danseuse2;
    Mouvement[2]= danseuse3;
    Mouvement[3]= danseuse4;

    int s = 0;
    for (s=0;s<1;s++)
            {
           for(int i=0;i<5;i++)
            {
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);

            rest(100);

            clear_bitmap(DoubleB);

            draw_sprite(DoubleB,Mouvement[i],x,y);
            }
            rest(100);
            }
}

///Defensive Crust
void Yoru_DC(t_perso Personnage, BITMAP * DoubleB)
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y +55;


    BITMAP*Mouvement[2];

    BITMAP*danseuse1 = load_bitmap("Y60.bmp", NULL);
    BITMAP*danseuse2 = load_bitmap("Y61.bmp", NULL);

    Mouvement[0]= danseuse1;
    Mouvement[1]= danseuse2;

    int j = 0;
    int i = 0;
    for (i=0;i<1;i++)
        {
            for(j=0;j<2;j++)
            {
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);

            rest(100);

            clear_bitmap(DoubleB);

            draw_sprite(DoubleB,Mouvement[j],x,y);
            }
            rest(100);

        }
}
///Will of the Earth
void Yoru_WOTE(t_perso Personnage, BITMAP * DoubleB)
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y;

    BITMAP*Mouvement[5];

    BITMAP*danseuse1 = load_bitmap("A10.bmp", NULL);
    BITMAP*danseuse2 = load_bitmap("A11.bmp", NULL);
    BITMAP*danseuse3 = load_bitmap("A12.bmp", NULL);
    BITMAP*danseuse4 = load_bitmap("A13.bmp", NULL);
    BITMAP*danseuse5 = load_bitmap("A14.bmp", NULL);


    Mouvement[0]= danseuse1;
    Mouvement[1]= danseuse2;
    Mouvement[2]= danseuse3;
    Mouvement[3]= danseuse4;
    Mouvement[4]= danseuse5;

    int j = 0;
    int s = 0;

        for (s=0;s<1;s++)
            {
           for(j=0;j<2;j++)
            {
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);

            rest(100);

            clear_bitmap(DoubleB);

            draw_sprite(DoubleB,Mouvement[j],x,y);
            }
            rest(100);

            }
}

///Atlas Smash
void Yoru_AS(t_perso Personnage, BITMAP * DoubleB)
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y;


    BITMAP*Mouvement[5];

    BITMAP*danseuse1 = load_bitmap("j1.bmp", NULL);
    BITMAP*danseuse2 = load_bitmap("j2.bmp", NULL);
    BITMAP*danseuse3 = load_bitmap("j3.bmp", NULL);
    BITMAP*danseuse4 = load_bitmap("j4.bmp", NULL);
    BITMAP*danseuse5 = load_bitmap("j5.bmp", NULL);
    BITMAP*danseuse6 = load_bitmap("j6.bmp", NULL);
    BITMAP*danseuse7 = load_bitmap("j7.bmp", NULL);
    BITMAP*danseuse8 = load_bitmap("j8.bmp", NULL);
    BITMAP*danseuse9 = load_bitmap("j9.bmp", NULL);
    BITMAP*danseuse10 = load_bitmap("j10.bmp", NULL);
    BITMAP*danseuse11 = load_bitmap("A11.bmp", NULL);
    BITMAP*danseuse12 = load_bitmap("A12.bmp", NULL);
    BITMAP*danseuse13 = load_bitmap("A13.bmp", NULL);
    BITMAP*danseuse14 = load_bitmap("A14.bmp", NULL);


    Mouvement[0]= danseuse1;
    Mouvement[1]= danseuse2;
    Mouvement[2]= danseuse3;
    Mouvement[3]= danseuse4;
    Mouvement[4]= danseuse5;
    Mouvement[5]= danseuse6;
    Mouvement[6]= danseuse7;
    Mouvement[7]= danseuse8;
    Mouvement[8]= danseuse9;
    Mouvement[9]= danseuse10;
    Mouvement[10]= danseuse11;
    Mouvement[11]= danseuse12;
    Mouvement[12]= danseuse13;
    Mouvement[13]= danseuse14;

    int j = 0;

    int s = 0;

     for (s=0;s<1;s++)
            {
            for(j=0;j<14;j++)
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

    t_perso Yoru;
    Yoru.x = 100;
    Yoru.y = 300;

    //declaration de variables
    BITMAP * Soldat;
    BITMAP * DoubleB;
    DoubleB =  create_bitmap(SCREEN_W,SCREEN_H);


    int x=0;
    int y=0;

    //initialisation allegro mis dans un sous-programme

    install_keyboard();
    install_mouse();


   /*//chargement de l'image
    danseuse = load_bitmap("Y0.bmp",NULL); //"posturebase" c'est juste le nom de mon sprite de base
    DoubleB = create_bitmap(SCREEN_W, SCREEN_H);// ne plus écrire 800 et 600
    masked_blit(danseuse, DoubleB, 0,0,x,y, danseuse->w, danseuse->h); //pour pouvoir déplacer le sprite en même temps que l'animation il va falloir jouer avec les 0
    blit(DoubleB, screen, 0,0,0,0, DoubleB->w, DoubleB->h);            //présents dans ces deux lignes de codes à chaque fois, je suppose qu'il faudra alors les remplacer
   */

    Soldat = load_bitmap("Y0.bmp", NULL);
    if(!Soldat)
    {
        allegro_message("Problemo");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

//par les coordonnées de chaque perso, d'où la nécessité de d'abord mettre à jour les coordonnées
    show_mouse(screen);

    while(!key[KEY_ESC])                                               // avant de commencer à animer
    {
    clear_bitmap(DoubleB);

    Yoru_base(Yoru.x,Yoru.y,DoubleB,Soldat);

    if (key[KEY_RIGHT])  //la condtion de cette boucle est0 arbitraire, évidemment on changera en fonction des besoins mais ce ne sera jamais cette condition spécifique en jeu
    {
        Yoru_RP(Yoru,DoubleB);//,screen
    }
    if (key[KEY_LEFT])  //la condtion de cette boucle est0 arbitraire, évidemment on changera en fonction des besoins mais ce ne sera jamais cette condition spécifique en jeu
    {
        Yoru_RS(Yoru,DoubleB);
    }
    if (key[KEY_UP])  //la condtion de cette boucle est0 arbitraire, évidemment on changera en fonction des besoins mais ce ne sera jamais cette condition spécifique en jeu
    {
        Yoru_AS(Yoru,DoubleB);
    }
    if (key[KEY_DOWN])  //la condtion de cette boucle est0 arbitraire, évidemment on changera en fonction des besoins mais ce ne sera jamais cette condition spécifique en jeu
    {
        Yoru_WOTE(Yoru,DoubleB);
    }

    blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);

    }

    printf("FIN!\n");
    return 0;
}END_OF_MAIN();
