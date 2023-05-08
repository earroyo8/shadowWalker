#include <iostream>
#include <cmath>
#include <GL/glx.h>
#include "cviramontes.h"
#include "nflessati.h"

//comment code was what was made in shadow.cpp

/*
//cone of vision param
#define CONE_ANGLE 45.0f //in degrees
#define CONE_DISTANCE 25.0f //in units
//const int for maximum guards
const int MAX_GUARDS = 10;
int enemyCount = 5;
*/
const int ENEMY_INCREMENT = 5;

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
    
void updateGuardPos(int& direction, int& x, int& y)
{
    switch (direction) {
        case DIRECTION_DOWN:
            y += 1;
            break;
        case DIRECTION_LEFT:
            x -= 1;
            break;
        case DIRECTION_UP:
            y -= 1;
            break;
        case DIRECTION_RIGHT:
            x += 1;
            break;
        case NO_MOVEMENT:
            break;
    }

    if(direction == DIRECTION_RIGHT) {
        if (walls[y+1][x] != 1) {
            direction = DIRECTION_DOWN;
        }
        else if (walls[y][x+1] != 1) {
            direction = DIRECTION_RIGHT;
        }
        else if (walls[y-1][x] != 1) {
            direction = DIRECTION_UP;
        }
        else if (walls[y][x-1] !=1 ) {
            direction = DIRECTION_LEFT;
        }
    }
    else if (direction == DIRECTION_DOWN) {
        if (walls[y][x+1] != 1) {
            direction = DIRECTION_RIGHT;
        }
        else if (walls[y+1][x] != 1) {
            direction = DIRECTION_DOWN;
        }
        else if (walls[y][x-1] != 1) {
            direction = DIRECTION_LEFT;
        }
        else if (walls[y-1][x] != 1) {
            direction = DIRECTION_UP;
        }

    }
    else if (direction == DIRECTION_LEFT) {
        if (walls[y-1][x] != 1) {
            direction = DIRECTION_UP;
        }
        else if (walls[y][x-1] != 1) {
            direction = DIRECTION_LEFT;
        }
        else if (walls[y+1][x] !=1 ) {
            direction = DIRECTION_DOWN;
        }
        else if (walls[y][x+1] !=1 ) {
            direction = DIRECTION_RIGHT;
        }
    }
    else if (direction == DIRECTION_UP) {
        if (walls[y][x-1] != 1) {
            direction = DIRECTION_LEFT;
        }
        else if (walls[y-1][x] != 1) {
            direction = DIRECTION_UP;
        }
        else if (walls[y][x+1] != 1) {
            direction = DIRECTION_RIGHT;
        }
        else if (walls[y+1][x] != 1) {
            direction = DIRECTION_DOWN;
        }
    }

    return;
}

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
