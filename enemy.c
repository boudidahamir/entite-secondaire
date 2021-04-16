#include "enemy.h"
#include "collisionBB.h"

void init(enemie *e)
{
  srand(time(NULL));
e->imgR=IMG_Load("enemier.png");

e->imgL=IMG_Load("enemiel.png");

e->direction[0]=rand()%2;
e->direction[1]=rand()%2;
if (e->direction[0]==0)
e->position.x=100;
else if(e->direction[0]==1)
e->position.x=1000;

e->position.y=rand()%601+100;
e->frame=0;
}

void animerenemie(enemie* e)
{
  int c;


  for( c=0; c<7; c++)
  {

     e->rects[c].x = 0 +c*100;
     e->rects[c].y = 0;
     e->rects[c].w = 100;
     e->rects[c].h = 76;
  }
}

void afficher(enemie *e,SDL_Surface *ecran)
{
  int fps=30,start,end;
  start=SDL_GetTicks();

    if (e->direction[0]==0)
    {

        SDL_BlitSurface(e->imgL,&e->rects[e->frame],ecran,&e->position);
        SDL_Flip(ecran);
        e->frame++;
        if (e->frame==7)
        e->frame=0;
    }
else if (e->direction[0]==1)
    {
        SDL_BlitSurface(e->imgR,&e->rects[e->frame],ecran,&e->position);
        SDL_Flip(ecran);
        e->frame++;
        if (e->frame==7)
        e->frame=0;
    }
    end=SDL_GetTicks();
    if(1000/fps>end-start)
    SDL_Delay(1000/fps-(end-start));



}



void deplacer(enemie *e)
{int droite=rand()%501+500;
  int gauche=rand()%501;
  int haut=rand()%351+350;
  int bas=rand()%351;
  srand(time(NULL));

    if (e->direction[0]==0 && e->direction[1]==0)
    {
        e->position.x=e->position.x-4;
        e->position.y=e->position.y+4;

    }
    else if (e->direction[0]==0 && e->direction[1]==1)
    {
        e->position.x=e->position.x-4;
        e->position.y=e->position.y-4;

    }
    else if (e->direction[0]==1 && e->direction[1]==0)
    {
        e->position.x=e->position.x+4;
        e->position.y=e->position.y+4;

    }
    else if (e->direction[0]==1 && e->direction[1]==1)
    {
        e->position.x=e->position.x+4;
        e->position.y=e->position.y-4;

    }
    
    if(e->position.x<=gauche)
    {
        e->direction[0]=1;
    }
    else if(e->position.x>=droite)
    {
        e->direction[0]=0;
    }

    if(e->position.y<=bas)
    {
        e->direction[1]=0;
    }
    else if(e->position.y>=haut)
    {
        e->direction[1]=1;
    }

}
