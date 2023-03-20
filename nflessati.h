#ifndef _NFLESSATI_H_
#define _NFLESSATI_H_

#define NO_MOVEMENT 4

typedef struct t_wall{
    	    int number;
	    float w,h;
	    float pos[2];
}Walls;

extern void make_walls(float w, float h, int xcent, int ycent);

extern int guard_hit(int headpos[2], int xpos, int ypos);

#endif
