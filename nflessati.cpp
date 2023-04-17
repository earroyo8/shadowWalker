//Nathan Flessati
#include <GL/glx.h>
#include "nflessati.h"
int guard_hit(int headpos[2], int xpos,int ypos)
{
    int gameover = 0;
    if (headpos[0] == xpos && headpos[1] == ypos) {
	gameover=1;
    }

    return gameover;
}

void make_walls(float w, float h, int xcent,int ycent)
{
    int cent[2];
    cent[0]=xcent;
    cent[1]=ycent;
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.1, 0.1f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2i(cent[0]-w,cent[1]-h);
    glVertex2i(cent[0]-w,cent[1]+h);
    glVertex2i(cent[0]+w,cent[1]+h);
    glVertex2i(cent[0]+w,cent[1]-h);
    glEnd();
}
