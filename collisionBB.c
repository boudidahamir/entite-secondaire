#include "collisionBB.h"
#include "enemy.h"
int collisionBB (SDL_Rect* p,enemie *e)
{int i=0;

  if(e->position.y >= p->y + p->h)
  {  i=1;
  return i;}
  if(e->position.x >= p->x + p->w)
  {  i=1;
  return i;}
  if(e->position.y + e->position.h <= p->y)
  {  i=1;
  return i;}
  if(e->position.x + e->position.w <= p->x)
  {  i=1;
  return i;}
  
  return i;


}
