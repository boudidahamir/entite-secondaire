#include "enemy.h"
#include "collisionBB.h"


int main()
{

SDL_Event event;
int continuer=1,i=0;
enemie en;
SDL_Surface *screen=NULL;
SDL_Surface *bg=NULL;
SDL_Surface *obstacle=NULL;
SDL_Rect posobstacle;
posobstacle.x=600;
posobstacle.y=350;
if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
{
printf("unable to initialize SDL: %s /n",SDL_GetError());
}

screen=SDL_SetVideoMode(1280,720,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
if(screen==NULL)
{
printf("unable to set video mode: %s /n",SDL_GetError());
}
bg=IMG_Load("bg.jpg");
obstacle=IMG_Load("enemiepos2r.png");

init(&en);
animerenemie(&en);

while(continuer)
{

  SDL_BlitSurface(bg,NULL,screen,NULL);
  SDL_BlitSurface(obstacle,NULL,screen,&posobstacle);
  afficher(&en,screen);
  SDL_Flip(screen);

  deplacer(&en);

    while(SDL_PollEvent(&event))
    {
        switch(event.type)

        case SDL_QUIT :
            continuer=0;
            break;
    }
if (collisionBB(&posobstacle,&en)==0)
{
  printf("ATTACK %d\n",i);
  i++;
}
}

SDL_FreeSurface(en.imgL);
SDL_FreeSurface(en.imgR);
SDL_Quit();

}
