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
    int element; //ira de 0 � 3 et permet de savoir quelle classe/perso le joueur a choisi (0 = terre ; 1 = eau ; 2 = feu ; 3 = air)
    int ptsvie; /// correspond aux points de vie de chaque perso, ils seront diff�rents selon les personnages
    int ptsatt; // correspond aux points d'attaque de base, c'est le nombre de d�gats de base que les persos
    int ptsmagie; /// correspond aux d�g�ts magiques des attaques de sort, ce sont ces points l� qui prennent en compte les �l�ments
    int ptsdef; // correspond aux points de d�fense de chaque perso, ils seront diff�rents selon les personnages (peut-�tre qu'ils seront alt�rables durant la partie)
    int ptsact; /// correspond aux points d'actions de chaque personnage, si il est �gal � 3, le personnage pourra faire jusqu'� trois actions durant son tour, ils seront diff�rents selon le personnage
    int ptsmouv; // correspond aux points de mouvements, il sera le m�me pour tous les personnages (� moins que ce soit trop d�s�quilibr�...)
    int attultime; /// correspond au nombre de d�g�ts de l'attaqye ultime de chaque personnage, elle diff�re selon les personnages et prend en compte les �l�ments
    int recharge;//correspond � la recharge de l'attaque ultime, il commencera � 0, et � chaque fois que le perso attaque, il s'incr�mentera de 1, une fois � 5, il pourra utiliser son attaque ultime, une fois utilis�e, cette variable retombe � 0
    int boostdef;///initi� � 0, si �gal � 1 alors les points de d�fense augmente de 100 et le restent pour 2 tours
    int boostatt;//initi� � 0, si �gal � 1, alors les points d'attaque et les points magie augmentent tout les deux de 100 pendant 2 tours
    int boostmag;
    int boostmouv;
    int boostcrit;
    int brulure;
    int jaugemagie;///diff�rente selon les persos, elle sert � r�guler l'utilisation des attaques de sorts, cett
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
void Yoru_DC(t_perso Personnage,BITMAP * DoubleB,BITMAP* danseuse,BITMAP* Terrain)
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y +55;

    int i = 0;
    for (i=0;i<1;i++)
        {

        clear_bitmap(DoubleB);
        danseuse = load_bitmap("Y0.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("Y60.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);

        clear_bitmap(DoubleB);
        danseuse = load_bitmap("Y61.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);

        }
}
///Will of the Earth
void Yoru_WOTE(t_perso Personnage,BITMAP* DoubleB,BITMAP* danseuse,BITMAP* Terrain)
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y +55;

        int s = 0;
        for (s=0;s<1;s++)
            {
           clear_bitmap(DoubleB);
        danseuse = load_bitmap("A10.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);

        clear_bitmap(DoubleB);
        danseuse = load_bitmap("A11.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("A12.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(700);


         clear_bitmap(DoubleB);
        danseuse = load_bitmap("A13.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(700);

        clear_bitmap(DoubleB);
        danseuse = load_bitmap("A14.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(700);

            }
}

///Atlas Smash
void Yoru_AS(t_perso Personnage, BITMAP* DoubleB,BITMAP* danseuse,BITMAP* Terrain)
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y +55;


    int s = 0;

     for (s=0;s<1;s++)
            {
            clear_bitmap(DoubleB);
        danseuse = load_bitmap("j1.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(1000);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("j2.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);




        clear_bitmap(DoubleB);
        danseuse = load_bitmap("j4.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("j5.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("j6.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("j7.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("j8.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("j9.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);

         clear_bitmap(DoubleB);
        danseuse = load_bitmap("j10.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


         clear_bitmap(DoubleB);
        danseuse = load_bitmap("j11.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);

         clear_bitmap(DoubleB);
        danseuse = load_bitmap("j12.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


         clear_bitmap(DoubleB);
        danseuse = load_bitmap("j13.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);

         clear_bitmap(DoubleB);
        danseuse = load_bitmap("j14.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,0,0,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
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
    DoubleB = create_bitmap(SCREEN_W, SCREEN_H);// ne plus �crire 800 et 600
    masked_blit(danseuse, DoubleB, 0,0,x,y, danseuse->w, danseuse->h); //pour pouvoir d�placer le sprite en m�me temps que l'animation il va falloir jouer avec les 0
    blit(DoubleB, screen, 0,0,0,0, DoubleB->w, DoubleB->h);            //pr�sents dans ces deux lignes de codes � chaque fois, je suppose qu'il faudra alors les remplacer
   */

    Soldat = load_bitmap("Y0.bmp", NULL);
    if(!Soldat)
    {
        allegro_message("Problemo");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

//par les coordonn�es de chaque perso, d'o� la n�cessit� de d'abord mettre � jour les coordonn�es
    show_mouse(screen);

    while(!key[KEY_ESC])                                               // avant de commencer � animer
    {
    clear_bitmap(DoubleB);

    Yoru_base(Yoru.x,Yoru.y,DoubleB,Soldat);

    if (key[KEY_RIGHT])  //la condtion de cette boucle est0 arbitraire, �videmment on changera en fonction des besoins mais ce ne sera jamais cette condition sp�cifique en jeu
    {
        Yoru_RP(Yoru,DoubleB);//,screen
    }
    if (key[KEY_LEFT])  //la condtion de cette boucle est0 arbitraire, �videmment on changera en fonction des besoins mais ce ne sera jamais cette condition sp�cifique en jeu
    {
        Yoru_RS(Yoru,DoubleB);
    }
    if (key[KEY_UP])  //la condtion de cette boucle est0 arbitraire, �videmment on changera en fonction des besoins mais ce ne sera jamais cette condition sp�cifique en jeu
    {
        //Yoru_haut(x,&y,DoubleB,Soldat);
    }
    if (key[KEY_DOWN])  //la condtion de cette boucle est0 arbitraire, �videmment on changera en fonction des besoins mais ce ne sera jamais cette condition sp�cifique en jeu
    {
        //Yoru_bas(x,&y,DoubleB,Soldat);
    }

    blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);

    }

    printf("FIN!\n");
    return 0;
}END_OF_MAIN();
