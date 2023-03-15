//Nathan Flessati
#include <stdio.h>
int guard_hit(int headpos[2], int xpos,int ypos)
{
    int gameover = 0;
    printf("%d,%d\n",headpos[0],headpos[1]);
    if (headpos[0] == xpos && headpos[1] == ypos) {
	    gameover=1;
    }

    return gameover;
}
