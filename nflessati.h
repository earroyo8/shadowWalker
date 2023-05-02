#ifndef _NFLESSATI_H_
#define _NFLESSATI_H_

#define NO_MOVEMENT 4
#define DIRECTION_DOWN  0
#define DIRECTION_LEFT  1
#define DIRECTION_UP    2
#define DIRECTION_RIGHT 3

#define MAX_SIZE 40

extern int walls[MAX_SIZE][MAX_SIZE];
extern int guardHit(int headpos[2], int xpos, int ypos);
extern bool wallHit(int spyposx,int spyposy);
extern void initWalls();
extern void drawWalls();
#endif
