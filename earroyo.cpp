//Estevan Arroyo
//earroyo.cpp file
//
#include <GL/glx.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include "earroyo.h"
#include "nflessati.h"
using namespace std;

//void getGridCenter(const int i, const int j, int cent[2]);

void initBomb();

/*
typedef struct key {
    int status;
    int pos[2];
} Key;
*/

/*
typedef struct bomb {
    int status;
    int pos[2];
    int timer = 0;
} Bomb;
*/

int score = 0;

struct Global {
//    Key key;
//    Bomb bomb;
    int xres, yres;
    int gameover;
    int winner;
} ge;

/*
void initKey() {
    int xPos = rand() % MAX_SIZE;
    int yPos = rand() % MAX_SIZE;
    while (walls[xPos][yPos]!=0) {
        xPos = rand() % MAX_SIZE;
        yPos = rand() % MAX_SIZE;
    }
    ge.key.status = 1;
    ge.key.pos[0] = xPos;
    ge.key.pos[1] = yPos;
}
*/

void resetGame(int n) {
    initSpy();
    initGuard();
    initKey();
    ge.gameover  = 0;
    ge.winner    = 0;
    if (n == 1)
        score = 0;
}

void incrementScore() {
    score++;
}

/*
void initBomb() {
    int xPos = rand() % MAX_SIZE;
    int yPos = rand() % MAX_SIZE;
    while (walls[xPos][yPos]!=0) {
        xPos = rand() % MAX_SIZE;
        yPos = rand() % MAX_SIZE;
    }
    ge.bomb.status = 1;
    ge.bomb.pos[0] = xPos;
    ge.bomb.pos[1] = yPos;
    ge.bomb.timer = 0; // initialize timer to 0
}
*/

/*
// Draw Bomb and Explosion on board
    getGridCenter(g.bomb.pos[1],g.bomb.pos[0],cent);

    if (g.bomb.timer < 60*1) {
        if (g.bomb.timer < 60 && g.bomb.timer % 10 < 5) { // blink every 10 frames (1/6 sec) for first second
            glColor3f(0,0,0); // set bomb color to black
        } else {
            glColor3f(1,0,0); // set bomb color to red
        }
        glBegin(GL_QUADS);
        glVertex2i(cent[0]-5, cent[1]-5);
        glVertex2i(cent[0]-5, cent[1]+5);
        glVertex2i(cent[0]+5, cent[1]+5);
        glVertex2i(cent[0]+5, cent[1]-5);
        glEnd();
    } else if (g.bomb.timer >= 60*5 && g.bomb.timer < 60*6) { // bomb starts blinking faster in last second
        if (g.bomb.timer % 10 < 5) { // blink every 10 frames (1/6 sec)
            glColor3f(0,0,0); // set bomb color to black
        } else {
            glColor3f(1,1,0); // set bomb color to red
        }
        glBegin(GL_QUADS);
        glVertex2i(cent[0]-5, cent[1]-5);
        glVertex2i(cent[0]-5, cent[1]+5);
        glVertex2i(cent[0]+5, cent[1]+5);
        glVertex2i(cent[0]+5, cent[1]-5);
        glEnd();
    } else {
        // Bomb has exploded, show explosion
        explodeBomb();
    }

    // Update timer
    g.bomb.timer++; // increment timer on every frame
*/

/*
//When Bomb explodes it calls on explodeBomb() to draw the radius of the explosion
void explodeBomb() {
    int explosionTimer = 0; // make the timer static so it persists across calls
    // Draw explosion
    glColor3f(1,0,0); // set color to red
    glBegin(GL_QUADS);
    for(int i=ge.bomb.pos[0]-1; i<=ge.bomb.pos[0]+1; i++) {
        for(int j=ge.bomb.pos[1]-1; j<=ge.bomb.pos[1]+1; j++) {
            if (i>=0 && j>=0 && i<MAX_SIZE && j<MAX_SIZE && walls[i][j]==0) { // check if valid location
                int cent[2];
                getGridCenter(j,i,cent);
                glVertex2i(cent[0]-5, cent[1]-5);
                glVertex2i(cent[0]-5, cent[1]+5);
                glVertex2i(cent[0]+5, cent[1]+5);
                glVertex2i(cent[0]+5, cent[1]-5);
            }
        }
    }
    glEnd();
    if (explosionTimer >= 10) { // wait for 10 seconds (60 frames per second * 10 seconds = 600 frames)
        explosionTimer = 0;
        initBomb(); // respawn a new bomb
    } else {
        explosionTimer++; // increment the timer on every frame
    }
}
*/
//*****************************************************************************

//when number 9 key is pressed it goes into feature mode
void featureMode() {
    //cout << "featureMode()" << endl;
    // Set the color to yellow
    glColor3f(1.0, 1.0, 0.0);
    // Draw the outer rectangle around the screen with a 30-pixel border
    glBegin(GL_QUADS);
    // Bottom border
    glVertex2i(0, 0);
    glVertex2i(ge.xres, 0);
    glVertex2i(ge.xres, 40);
    glVertex2i(0, 40);
    // Left border
    glVertex2i(0, 0);
    glVertex2i(30, 0);
    glVertex2i(30, ge.yres);
    glVertex2i(0, ge.yres);
    // Top border
    glVertex2i(0, ge.yres - 30);
    glVertex2i(ge.xres, ge.yres - 30);
    glVertex2i(ge.xres, ge.yres);
    glVertex2i(0, ge.yres);
    // Right border
    glVertex2i(ge.xres - 30, 0);
    glVertex2i(ge.xres, 0);
    glVertex2i(ge.xres, ge.yres);
    glVertex2i(ge.xres - 30, ge.yres);
    glEnd();
}
