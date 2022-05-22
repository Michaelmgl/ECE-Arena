#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

///Meilleurs disposition de code actuelle Pour Dvhani


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
void Dhvani_FS(t_perso Personnage, BITMAP * DoubleB)
{

    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y;

    BITMAP*Mouvement[4];

    BITMAP*danseuse1 = load_bitmap("DD1.bmp", NULL);
    BITMAP*danseuse2 = load_bitmap("DD2.bmp", NULL);
    BITMAP*danseuse3 = load_bitmap("DD3.bmp", NULL);
    BITMAP*danseuse4 = load_bitmap("DD4.bmp", NULL);

    Mouvement[0]= danseuse1;
    Mouvement[1]= danseuse2;
    Mouvement[2]= danseuse3;
    Mouvement[3]= danseuse4;


    int i = 0;
    int s = 0;
    for (s=0;s<1;s++)
            {
       for(i=0;i<4;i++)
            {
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);

            rest(100);

            clear_bitmap(DoubleB);

            draw_sprite(DoubleB,Mouvement[i],x,y);
            }
            rest(100);
            }
}

///Heavenly Breath
void Dhvani_HB(t_perso Personnage, BITMAP * DoubleB)
{
     int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y;

    BITMAP*Mouvement[8];

    BITMAP*danseuse1 = load_bitmap("HB1.bmp", NULL);
    BITMAP*danseuse2 = load_bitmap("HB2.bmp", NULL);
    BITMAP*danseuse3 = load_bitmap("HB3.bmp", NULL);
    BITMAP*danseuse4 = load_bitmap("HB4.bmp", NULL);
    BITMAP*danseuse5 = load_bitmap("HB5.bmp", NULL);
    BITMAP*danseuse6 = load_bitmap("HB6.bmp", NULL);
    BITMAP*danseuse7 = load_bitmap("HB7.bmp", NULL);
    BITMAP*danseuse8 = load_bitmap("HB8.bmp", NULL);

    Mouvement[0]= danseuse1;
    Mouvement[1]= danseuse2;
    Mouvement[2]= danseuse3;
    Mouvement[3]= danseuse4;
    Mouvement[4]= danseuse5;
    Mouvement[5]= danseuse6;
    Mouvement[6]= danseuse7;
    Mouvement[7]= danseuse8;

    int i = 0;
    int s = 0;
    for (s=0;s<1;s++)
            {
          for(i=0;i<8;i++)
            {
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);

            rest(100);

            clear_bitmap(DoubleB);

            draw_sprite(DoubleB,Mouvement[i],x,y);
            }
            rest(100);
            }
}

///Meditation
void Dhvani_M(t_perso Personnage, BITMAP * DoubleB)
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y;

    BITMAP*Mouvement[6];

    BITMAP*danseuse1 = load_bitmap("P1.bmp", NULL);
    BITMAP*danseuse2 = load_bitmap("P2.bmp", NULL);
    BITMAP*danseuse3 = load_bitmap("P3.bmp", NULL);
    BITMAP*danseuse4 = load_bitmap("P4.bmp", NULL);
    BITMAP*danseuse5 = load_bitmap("P5.bmp", NULL);
    BITMAP*danseuse6 = load_bitmap("P6.bmp", NULL);
    BITMAP*danseuse7 = load_bitmap("P7.bmp", NULL);

    Mouvement[0]= danseuse1;
    Mouvement[1]= danseuse2;
    Mouvement[2]= danseuse3;
    Mouvement[3]= danseuse4;
    Mouvement[4]= danseuse5;
    Mouvement[5]= danseuse6;
    Mouvement[6]= danseuse7;

    int i = 0;
    int j = 0;

     for (i=0;i<1;i++)
        {
        for(j=0;j<7;j++)
            {
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);

            rest(100);

            clear_bitmap(DoubleB);

            draw_sprite(DoubleB,Mouvement[j],x,y);
            }
            rest(100);
        }
}

///Dandling Feet
void Dhvani_DF(t_perso Personnage, BITMAP * DoubleB)
{
     int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y;

    BITMAP*Mouvement[3];

    BITMAP*danseuse1 = load_bitmap("DF1.bmp", NULL);
    BITMAP*danseuse2 = load_bitmap("DF2.bmp", NULL);
    BITMAP*danseuse3 = load_bitmap("DF3.bmp", NULL);
    //BITMAP*danseuse4 = load_bitmap("DF4.bmp", NULL);

    Mouvement[0]= danseuse1;
    Mouvement[1]= danseuse2;
    Mouvement[2]= danseuse3;
    //Mouvement[3]= danseuse4;

    int j = 0;
    int s = 0;

        for (s=0;s<1;s++)
            {
            for(j=0;j<3;j++)
            {
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);

            rest(100);

            clear_bitmap(DoubleB);

            draw_sprite(DoubleB,Mouvement[j],x,y);
            }
            for(j=3;j>=0;j--)
            {
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);

            rest(100);

            clear_bitmap(DoubleB);

            draw_sprite(DoubleB,Mouvement[j],x,y);
            }
            rest(100);
            }
}
///Dance Till The End
void Dhvani_DTTE(t_perso Personnage, BITMAP * DoubleB)
{
    int x =0;
    int y =0;

    x = Personnage.x;
    y = Personnage.y;

    BITMAP*Mouvement[6];

    BITMAP*danseuse1 = load_bitmap("DA1.bmp", NULL);
    BITMAP*danseuse2 = load_bitmap("DA2.bmp", NULL);
    BITMAP*danseuse3 = load_bitmap("DA3.bmp", NULL);
    BITMAP*danseuse4 = load_bitmap("DA4.bmp", NULL);
    BITMAP*danseuse5 = load_bitmap("DA5.bmp", NULL);
    BITMAP*danseuse6 = load_bitmap("DA6.bmp", NULL);

    Mouvement[0]= danseuse1;
    Mouvement[1]= danseuse2;
    Mouvement[2]= danseuse3;
    Mouvement[3]= danseuse4;
    Mouvement[4]= danseuse5;
    Mouvement[5]= danseuse6;


    int j = 0;
    int s = 0;

     for (s=0;s<1;s++)
            {
            for(j=0;j<6;j++)
            {
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);

            rest(100);

            clear_bitmap(DoubleB);

            draw_sprite(DoubleB,Mouvement[j],x,y);
            }
            for(j=6;j>=0;j++)
            {
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);

            rest(100);

            clear_bitmap(DoubleB);

            draw_sprite(DoubleB,Mouvement[j],x,y);
            rest(100);
            }
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
    BITMAP * Mage;
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

    Mage = load_bitmap("Y0.bmp", NULL);
    if(!Mage)
    {
        allegro_message("Problemo");
        allegro_exit();
        exit(EXIT_FAILURE);
    }                                 //par les coordonnées de chaque perso, d'où la nécessité de d'abord mettre à jour les coordonnées
    show_mouse(screen);

    t_perso Amerigo;

    Amerigo.x=500;
    Amerigo.y=400;

    while(!key[KEY_ESC])                                               // avant de commencer à animer
    {
    //Yoru_base(x,y,DoubleB,Soldat);

    clear_bitmap(DoubleB);

    if (mouse_x>=605 && mouse_x <=739 && mouse_y>=540 && mouse_y <=600)  //la condtion de cette boucle est0 arbitraire, évidemment on changera en fonction des besoins mais ce ne sera jamais cette condition spécifique en jeu
    {
            if (mouse_b&1)
            {

        Dhvani_DTTE(Amerigo,DoubleB);
        }
    }
    if (mouse_x>=470 && mouse_x <=604 && mouse_y>=540 && mouse_y <=600)  //la condtion de cette boucle est0 arbitraire, évidemment on changera en fonction des besoins mais ce ne sera jamais cette condition spécifique en jeu
    {
            if (mouse_b&1)
                {
      Dhvani_DF(Amerigo,DoubleB);
      }
    }
    if (mouse_x>=335 && mouse_x <=469 && mouse_y>=540 && mouse_y <=600)  //la condtion de cette boucle est0 arbitraire, évidemment on changera en fonction des besoins mais ce ne sera jamais cette condition spécifique en jeu
    {

            if (mouse_b&1)

                {
     Dhvani_M(Amerigo,DoubleB);
      }
    }
    if (mouse_x>=65 && mouse_x <=199 && mouse_y>=540 && mouse_y <=600)  //la condtion de cette boucle est0 arbitraire, évidemment on changera en fonction des besoins mais ce ne sera jamais cette condition spécifique en jeu
    {

            if (mouse_b&1)

                {
      Dhvani_FS(Amerigo,DoubleB);


      }
    }

     if(mouse_x>=200 && mouse_x <=334 && mouse_y>=540 && mouse_y <=600)  //la condtion de cette boucle est0 arbitraire, évidemment on changera en fonction des besoins mais ce ne sera jamais cette condition spécifique en jeu
    {


            if (mouse_b&1)

                {
      Dhvani_HB(Amerigo,DoubleB);


      }
    }

    }

    printf("FIN!\n");
    return 0;
}END_OF_MAIN();

