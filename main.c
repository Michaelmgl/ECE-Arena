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

void Yoru_base(int x, int y, BITMAP* DoubleB,BITMAP * danseuse)
{
    danseuse = load_bitmap("Y0.bmp", NULL);
    if(!danseuse)
    {
        allegro_message("Problemo");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    masked_blit(danseuse,DoubleB,0,0,x,y,danseuse->w,danseuse->h);
    blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
    blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
}


void Yoru_haut(int x,int *y, BITMAP * DoubleB,BITMAP * danseuse)
{

    int s = 0;
    for (s=0;s<1;s++)
            {
            clear_bitmap(DoubleB);
            danseuse = load_bitmap("Y0U.bmp", NULL);

            masked_blit(danseuse,DoubleB,0,0,x,*y,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);            //sera utilisé avec blit(), masked_blit() étant la fonction qui enlève le magenta
            rest(100);
            danseuse = load_bitmap("Y1U.bmp", NULL);
            clear_bitmap(DoubleB);

            masked_blit(danseuse,DoubleB,0,0,x,*y-11,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);
            danseuse = load_bitmap("Y2U.bmp", NULL);
            clear_bitmap(DoubleB);

            masked_blit(danseuse,DoubleB,0,0,x,*y-22,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);
            danseuse = load_bitmap("Y3U.bmp", NULL);
            clear_bitmap(DoubleB);

            masked_blit(danseuse,DoubleB,0,0,x,*y-33,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);
            danseuse = load_bitmap("Y4U.bmp", NULL);
            clear_bitmap(DoubleB);

            masked_blit(danseuse,DoubleB,0,0,x,*y-65,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);

            clear_bitmap(DoubleB);
            danseuse = load_bitmap("Y0.bmp", NULL);
            masked_blit(danseuse,DoubleB,0,0,x,*y-65,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);

            *y = *y-65;
            }
}

void Yoru_droite(int* x,int y,BITMAP * DoubleB,BITMAP * danseuse)
{

     int i = 0;
     for (i=0;i<1;i++)
        {
            clear_bitmap(DoubleB);
            danseuse = load_bitmap("Y0.bmp", NULL);

            masked_blit(danseuse,DoubleB,0,0,*x,y,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);            //sera utilisé avec blit(), masked_blit() étant la fonction qui enlève le magenta
            rest(100);
            danseuse = load_bitmap("Y1R.bmp", NULL);
            clear_bitmap(DoubleB);

            masked_blit(danseuse,DoubleB,0,0,*x,y,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);
            danseuse = load_bitmap("Y2R.bmp", NULL);
            clear_bitmap(DoubleB);

            masked_blit(danseuse,DoubleB,0,0,*x,y,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);
            danseuse = load_bitmap("Y3R.bmp", NULL);
            clear_bitmap(DoubleB);

            masked_blit(danseuse,DoubleB,0,0,*x+33,y,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);
            danseuse = load_bitmap("Y4R.bmp", NULL);
            clear_bitmap(DoubleB);

            masked_blit(danseuse,DoubleB,0,0,*x+65,y,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);

            clear_bitmap(DoubleB);
            danseuse = load_bitmap("Y0.bmp", NULL);
            masked_blit(danseuse,DoubleB,0,0,*x+65,y,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);

            *x = *x + 65;
        }
}

void Yoru_gauche(int* x,int y,BITMAP* DoubleB,BITMAP* danseuse)
{


    int s = 0;
        for (s=0;s<1;s++)
            {
            clear_bitmap(DoubleB);
            danseuse = load_bitmap("Y0.bmp", NULL);

            masked_blit(danseuse,DoubleB,0,0,*x,y,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);            //sera utilisé avec blit(), masked_blit() étant la fonction qui enlève le magenta
            rest(100);
            danseuse = load_bitmap("Y1L.bmp", NULL);
            clear_bitmap(DoubleB);

            masked_blit(danseuse,DoubleB,0,0,*x-11,y,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);
            danseuse = load_bitmap("Y2L.bmp", NULL);
            clear_bitmap(DoubleB);

            masked_blit(danseuse,DoubleB,0,0,*x-22,y,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);
            danseuse = load_bitmap("Y3L.bmp", NULL);
            clear_bitmap(DoubleB);

            masked_blit(danseuse,DoubleB,0,0,*x-33,y,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);
            danseuse = load_bitmap("Y4L.bmp", NULL);
            clear_bitmap(DoubleB);

            masked_blit(danseuse,DoubleB,0,0,*x-65,y,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);

            clear_bitmap(DoubleB);
            danseuse = load_bitmap("Y0.bmp", NULL);
            masked_blit(danseuse,DoubleB,0,0,*x-65,y,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);

            *x = *x-65;
            }
}

void Yoru_bas(int x, int *y, BITMAP* DoubleB,BITMAP* danseuse)
{

    int s = 0;

     for (s=0;s<1;s++)
            {
            clear_bitmap(DoubleB);
            danseuse = load_bitmap("Y0.bmp", NULL);


            masked_blit(danseuse,DoubleB,0,0,x,*y,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);            //sera utilisé avec blit(), masked_blit() étant la fonction qui enlève le magenta
            rest(100);
            danseuse = load_bitmap("Y1.bmp", NULL);
            clear_bitmap(DoubleB);

            masked_blit(danseuse,DoubleB,0,0,x,*y+11,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);
            danseuse = load_bitmap("Y2.bmp", NULL);
            clear_bitmap(DoubleB);

            masked_blit(danseuse,DoubleB,0,0,x,*y+22,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);
            danseuse = load_bitmap("Y3.bmp", NULL);
            clear_bitmap(DoubleB);

            masked_blit(danseuse,DoubleB,0,0,x,*y+33,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);
            danseuse = load_bitmap("Y4.bmp", NULL);
            clear_bitmap(DoubleB);

            masked_blit(danseuse,DoubleB,0,0,x,*y+65,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);

            clear_bitmap(DoubleB);
            danseuse = load_bitmap("Y0.bmp", NULL);
            masked_blit(danseuse,DoubleB,0,0,x,*y+65,danseuse->w,danseuse->h);
            blit(DoubleB,screen,0,0,0,0,DoubleB->w,DoubleB->h);
            rest(100);

            *y = *y + 65;
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
    BITMAP * Soldat;
    BITMAP * DoubleB;
    DoubleB =  create_bitmap(SCREEN_W,SCREEN_H);

    SAMPLE*Musique;
    Musique = load_wav("ksi.wave");
    ///pour l'appel
   // play_sample()
    ///play_sample(nom,100,128,1000,0)

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
    }                                 //par les coordonnées de chaque perso, d'où la nécessité de d'abord mettre à jour les coordonnées
    show_mouse(screen);

    while(!key[KEY_ESC])                                               // avant de commencer à animer
    {
    Yoru_base(x,y,DoubleB,Soldat);

    clear_bitmap(DoubleB);

    if (key[KEY_RIGHT])  //la condtion de cette boucle est0 arbitraire, évidemment on changera en fonction des besoins mais ce ne sera jamais cette condition spécifique en jeu
    {
        Yoru_droite(&x,y,DoubleB,Soldat);
    }
    if (key[KEY_LEFT])  //la condtion de cette boucle est0 arbitraire, évidemment on changera en fonction des besoins mais ce ne sera jamais cette condition spécifique en jeu
    {
        Yoru_gauche(&x,y,DoubleB,Soldat);
    }
    if (key[KEY_UP])  //la condtion de cette boucle est0 arbitraire, évidemment on changera en fonction des besoins mais ce ne sera jamais cette condition spécifique en jeu
    {
        Yoru_haut(x,&y,DoubleB,Soldat);
    }
    if (key[KEY_DOWN])  //la condtion de cette boucle est0 arbitraire, évidemment on changera en fonction des besoins mais ce ne sera jamais cette condition spécifique en jeu
    {
        Yoru_bas(x,&y,DoubleB,Soldat);
    }
    }

    printf("FIN!\n");
    return 0;
}END_OF_MAIN();
