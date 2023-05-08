#include <iostream>
#include <cmath>
#include <GL/glx.h>
/*
//cone of vision param
#define CONE_ANGLE 45.0f //in degrees
#define CONE_DISTANCE 25.0f //in units
#define SPY_CONE_ANGLE 90.0f
#define SPY_CONE_DISTANCE 25.0f
#define SPY_ANGLE_SNEAK 60.0f
#define SPY_DISTANCE_SNEAK 5.0f
//const int for maximum guards
const int MAX_GUARDS = 10;
*/

/*
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void initGuard()
{
    for (int k=0; k<MAX_GUARDS; ++k) {
        int i=rand() % MAX_SIZE;
        int j=rand() % MAX_SIZE;

        while (walls[i][j]!=0) {
            i=rand() % MAX_SIZE;
            j=rand() % MAX_SIZE;
        }

        g.guard[k].status = 1;
        g.guard[k].pos[0] = j;
        g.guard[k].pos[1] = i;

        g.guard[k].direction = NO_MOVEMENT;
        //g.guard[k].pos[1] += 1;
    }
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

void initguardCone(float angle, float distance) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); //center of cone
    glColor3f(1.0f, 0.0f, 1.0f); //cone to purple
    for (float i = -angle / 2; i <= angle / 2; i += 1.0f) {
        float rad = i * (M_PI / 180.0f);
        float x = distance * cos(rad);
        float y = distance * sin(rad);
        glVertex2f(x, y);
    }
    glEnd();
}

void incrementGuard(int& enemyCount) {
    enemyCount += ENEMY_INCREMENT;
}
    

/*
//PHYSICS%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    for (int z=0; z<MAX_GUARDS; z++) {
        int guardpos[2];
        guardpos[0]=g.guard[z].pos[0];
        guardpos[1]=g.guard[z].pos[1];


        if (guardHit(headpos,g.guard[z].pos[0],g.guard[z].pos[1])) {
            resetGame();
            return;
        }
        if(g.guard[z].direction == NO_MOVEMENT)
            g.guard[z].direction = DIRECTION_RIGHT;

        if(g.guard[z].direction==DIRECTION_RIGHT) {
            if (walls[g.guard[z].pos[1]+1][g.guard[z].pos[0]]!=1) {
                g.guard[z].direction = DIRECTION_DOWN;
            }
            else if (walls[g.guard[z].pos[1]][g.guard[z].pos[0]+1]!=1) {
                g.guard[z].direction = DIRECTION_RIGHT;
            }
            else if (walls[g.guard[z].pos[1]-1][g.guard[z].pos[0]]!=1) {
                g.guard[z].direction = DIRECTION_UP;
            }
            else if (walls[g.guard[z].pos[1]][g.guard[z].pos[0]-1]!=1) {
                g.guard[z].direction = DIRECTION_LEFT;
            }
        }
        else if (g.guard[z].direction==DIRECTION_DOWN) {
            if (walls[g.guard[z].pos[1]][g.guard[z].pos[0]+1]!=1) {
                g.guard[z].direction = DIRECTION_RIGHT;
            }
            else if (walls[g.guard[z].pos[1]+1][g.guard[z].pos[0]]!=1) {
                g.guard[z].direction = DIRECTION_DOWN;
            }
            else if (walls[g.guard[z].pos[1]][g.guard[z].pos[0]-1]!=1) {
                g.guard[z].direction = DIRECTION_LEFT;
            }
            else if (walls[g.guard[z].pos[1]-1][g.guard[z].pos[0]]!=1) {
                g.guard[z].direction = DIRECTION_UP;
            }

        }
        else if (g.guard[z].direction==DIRECTION_LEFT) {
            if (walls[g.guard[z].pos[1]-1][g.guard[z].pos[0]]!=1) {
                g.guard[z].direction = DIRECTION_UP;
            }
            else if (walls[g.guard[z].pos[1]][g.guard[z].pos[0]-1]!=1) {
                g.guard[z].direction = DIRECTION_LEFT;
            }
            else if (walls[g.guard[z].pos[1]+1][g.guard[z].pos[0]]!=1) {
                g.guard[z].direction = DIRECTION_DOWN;
            }
            else if (walls[g.guard[z].pos[1]][g.guard[z].pos[0]+1]!=1) {
                g.guard[z].direction = DIRECTION_RIGHT;
            }
        }
        else if (g.guard[z].direction==DIRECTION_UP) {
            if (walls[g.guard[z].pos[1]][g.guard[z].pos[0]-1]!=1) {
                g.guard[z].direction = DIRECTION_LEFT;
            }
            else if (walls[g.guard[z].pos[1]-1][g.guard[z].pos[0]]!=1) {
                g.guard[z].direction = DIRECTION_UP;
            }
            else if (walls[g.guard[z].pos[1]][g.guard[z].pos[0]+1]!=1) {
                g.guard[z].direction = DIRECTION_RIGHT;
            }
            else if (walls[g.guard[z].pos[1]+1][g.guard[z].pos[0]]!=1) {
                g.guard[z].direction = DIRECTION_DOWN;
            }
        } 


        switch (g.guard[z].direction) {
            case DIRECTION_DOWN:
                g.guard[z].pos[1] += 1;
                break;
            case DIRECTION_LEFT:
                g.guard[z].pos[0] -= 1;
                break;
            case DIRECTION_UP:
                g.guard[z].pos[1] -= 1;
                break;
            case DIRECTION_RIGHT:
                g.guard[z].pos[0] += 1;
                break;
            case NO_MOVEMENT:
                g.guard[z].pos[0]+=0;
                g.guard[z].pos[1]+=0 ;
                break;
        }
        if (g.guard[z].pos[0]< 0 ||
                g.guard[z].pos[0] > g.gridDim-1 ||
                g.guard[z].pos[1]< 0 ||
                g.guard[z].pos[1] > g.gridDim-1) {
            g.guard[z].pos[0]=guardpos[0]; g.guard[z].pos[1]=guardpos[1] ;
            return;
        }
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

/*
//RENDER%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //draw guard...
    for (int k=0; k<MAX_GUARDS; ++k) {
        getGridCenter(g.guard[k].pos[1],g.guard[k].pos[0],cent);
        initguardCone(CONE_ANGLE, CONE_DISTANCE);
        //glTranslatef(g.guard[k].pos[1],g.guard[k].pos[0],0.0f);
        glColor3f(1.0, 0.1f, 0.0f);
        glBegin(GL_POLYGON);
        glVertex2i(cent[0]-5, cent[1]-5);
        glVertex2i(cent[0]-5, cent[1]+5);
        glVertex2i(cent[0]+5, cent[1]+5);
        glVertex2i(cent[0]+5, cent[1]-5);
        glEnd();
    }
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/
