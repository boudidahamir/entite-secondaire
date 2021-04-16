#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>

typedef struct
{
SDL_Rect position;
SDL_Surface *imgR;
SDL_Surface *imgL;
int direction[2];
int frame;
SDL_Rect rects[8];

}enemie;

void animerenemie(enemie* e);
void init(enemie *e);
void afficher(enemie *e,SDL_Surface *ecran);
void deplacer(enemie *e);






#endif // ENEMY_H_INCLUDED
