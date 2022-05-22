#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

///Meilleurs disposition de code actuelle Pour Dvhani


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


void Dhvani_base(int x, int y, BITMAP* DoubleB,BITMAP * danseuse)
{
    danseuse = load_bitmap("K0.bmp", NULL);
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

///Fan Slap
void Dhvani_FS(t_perso Personnage, BITMAP * DoubleB,BITMAP * danseuse,BITMAP* Terrain)
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y +55;

    int s = 0;
    for (s=0;s<1;s++)
            {
        clear_bitmap(DoubleB);
        danseuse = load_bitmap("DD1.bmp", NULL);
        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);

        clear_bitmap(DoubleB);
        danseuse = load_bitmap("DD2.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("DD3.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


           clear_bitmap(DoubleB);
        danseuse = load_bitmap("DD4.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);
            }
}

///Heavenly Breath
void Dhvani_haut(t_perso Personnage, BITMAP * DoubleB,BITMAP * danseuse,BITMAP* Terrain)
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y +55;

    int s = 0;
    for (s=0;s<1;s++)
            {
           clear_bitmap(DoubleB);
        danseuse = load_bitmap("HB1.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);

        clear_bitmap(DoubleB);
        danseuse = load_bitmap("HB2.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);



        clear_bitmap(DoubleB);
        danseuse = load_bitmap("HB3.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);

                clear_bitmap(DoubleB);
        danseuse = load_bitmap("HB4.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


                clear_bitmap(DoubleB);
        danseuse = load_bitmap("HB5.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


                clear_bitmap(DoubleB);
        danseuse = load_bitmap("HB6.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


                clear_bitmap(DoubleB);
        danseuse = load_bitmap("HB7.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


                clear_bitmap(DoubleB);
        danseuse = load_bitmap("HB8.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);
            }
}

///Meditation
void Dhvani_M(t_perso Personnage, BITMAP * DoubleB,BITMAP * danseuse,BITMAP* Terrain)
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y +55;

     int i = 0;
     for (i=0;i<1;i++)
        {

        clear_bitmap(DoubleB);
        danseuse = load_bitmap("P1.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);

        clear_bitmap(DoubleB);
        danseuse = load_bitmap("P2.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);

        clear_bitmap(DoubleB);
        danseuse = load_bitmap("P3.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("P4.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("P5.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);

        clear_bitmap(DoubleB);
        danseuse = load_bitmap("P6.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);
        clear_bitmap(DoubleB);
        danseuse = load_bitmap("P7.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);
        }
}

///Dandling Feet
void Dhvani_DF(t_perso Personnage, BITMAP * DoubleB,BITMAP * danseuse,BITMAP* Terrain)
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y +55;


    int s = 0;
        for (s=0;s<1;s++)
            {
           clear_bitmap(DoubleB);
        danseuse = load_bitmap("DF1.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);

        clear_bitmap(DoubleB);
        danseuse = load_bitmap("DF2.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("DF3.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


         clear_bitmap(DoubleB);
        danseuse = load_bitmap("DF4.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);
            }
}
///Dance Till The End
void Dhvani_DTTE(t_perso Personnage, BITMAP * DoubleB,BITMAP * danseuse,BITMAP* Terrain)
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y +55;

    int s = 0;

     for (s=0;s<1;s++)
            {
        clear_bitmap(DoubleB);
        danseuse = load_bitmap("DA1.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(1000);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("DA2.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("DA3.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);

        clear_bitmap(DoubleB);
        danseuse = load_bitmap("DA4.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("DA5.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("DA6.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("DA5.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("DA4.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
        danseuse = load_bitmap("DA3.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
         danseuse = load_bitmap("DA2.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
        blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
        rest(100);


        clear_bitmap(DoubleB);
         danseuse = load_bitmap("DA1.bmp", NULL);

        masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
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

    //declaration de variables
    BITMAP * danseuse;
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

    danseuse = load_bitmap("Y0.bmp", NULL);
    if(!danseuse)
    {
        allegro_message("Problemo");
        allegro_exit();
        exit(EXIT_FAILURE);
    }                                 //par les coordonn�es de chaque perso, d'o� la n�cessit� de d'abord mettre � jour les coordonn�es
    show_mouse(screen);

    while(!key[KEY_ESC])                                               // avant de commencer � animer
    {
    //Yoru_base(x,y,DoubleB,Soldat);

    clear_bitmap(DoubleB);

    if (key[KEY_RIGHT])  //la condtion de cette boucle est0 arbitraire, �videmment on changera en fonction des besoins mais ce ne sera jamais cette condition sp�cifique en jeu
    {
      //  Yoru_droite(&x,y,DoubleB,Soldat);
    }
    if (key[KEY_LEFT])  //la condtion de cette boucle est0 arbitraire, �videmment on changera en fonction des besoins mais ce ne sera jamais cette condition sp�cifique en jeu
    {
      //  Yoru_gauche(&x,y,DoubleB,Soldat);
    }
    if (key[KEY_UP])  //la condtion de cette boucle est0 arbitraire, �videmment on changera en fonction des besoins mais ce ne sera jamais cette condition sp�cifique en jeu
    {
       // Yoru_haut(x,&y,DoubleB,Soldat);
    }
    if (key[KEY_DOWN])  //la condtion de cette boucle est0 arbitraire, �videmment on changera en fonction des besoins mais ce ne sera jamais cette condition sp�cifique en jeu
    {
       // Yoru_bas(x,&y,DoubleB,Soldat);
    }
    }

    printf("FIN!\n");
    return 0;
}END_OF_MAIN();
