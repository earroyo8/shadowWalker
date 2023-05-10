//Estevan Arroyo
//earroyo.cpp file
//
#include <GL/glx.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include "earroyo.h"
#include "nflessati.h"
using namespace std;

void getGridCenter(const int i, const int j, int cent[2]);
void initBomb();

int score = 0;

struct Global {
//    Key key;
//    Bomb bomb;
    int xres, yres;
    int gameover;
    int winner;
} ge;
void resetGame(int n) {
    initSpy();
    initGuard();
    initKey();
    initBomb();
    ge.gameover  = 0;
    ge.winner    = 0;
    if (n == 1)
        score = 0;
}

void incrementScore() {
    score++;
}
//main bomb function
void drawBomb(int xpos, int ypos, int timer) {
    static int bombTimer = timer;
    static bool exploded = false;
    if (!exploded) {
        int cent[2];
        getGridCenter(xpos, ypos, cent);
        if (bombTimer < 60) { //explodes in 40 frames
            // Blink black and red
            if (bombTimer % 10 < 5) {
                glColor3f(0, 0, 0); // Black
            } else {
                glColor3f(1, 0, 0); // Red
            }
            glBegin(GL_QUADS);
            glVertex2i(cent[0] - 5, cent[1] - 5);
            glVertex2i(cent[0] - 5, cent[1] + 5);
            glVertex2i(cent[0] + 5, cent[1] + 5);
            glVertex2i(cent[0] + 5, cent[1] - 5);
            glEnd();
        } else {
            // Explode as a 3x3 square
            glColor3f(1, 0, 0); // Red
            cout << "explosion!";
            glBegin(GL_QUADS);
            for (int i = ypos - 1; i <= ypos + 1; i++) {
                for (int j = xpos - 1; j <= xpos + 1; j++) {
                    if (i >= 0 && j >= 0 && i < MAX_SIZE && j < MAX_SIZE && walls[i][j] == 0) {
                        int cent[2];
                        getGridCenter(j, i, cent);
                        glVertex2i(cent[0] - 5, cent[1] - 5);
                        glVertex2i(cent[0] - 5, cent[1] + 5);
                        glVertex2i(cent[0] + 5, cent[1] + 5);
                        glVertex2i(cent[0] + 5, cent[1] - 5);
                    }
                }
            }
            glEnd();
            exploded = true;
        }
        bombTimer++;
    }
}

//feature2. spawns 10 bombs
void drawBombs(int numBombs, int timer) {
    static int bombTimer = timer;
    static bool exploded[10] = { false };
    static int explosionTimer[10] = { 0 };
    srand(time(NULL)); 
    for (int i = 0; i < numBombs; i++) {
        if (!exploded[i]) {
            // generate a random xpos
            int xpos = rand() % MAX_SIZE;
            // generate a random y position
            int ypos = rand() % MAX_SIZE;
            int cent[2];
            getGridCenter(xpos, ypos, cent);
            
            //explodes in 40 frames
            if (bombTimer < 40) { 
                // Blink black and red
                if (bombTimer % 10 < 5) {
                    glColor3f(0, 0, 0); // Black
                } else {
                    glColor3f(1, 0, 0); // Red
                }
                glBegin(GL_QUADS);
                glVertex2i(cent[0] - 5, cent[1] - 5);
                glVertex2i(cent[0] - 5, cent[1] + 5);
                glVertex2i(cent[0] + 5, cent[1] + 5);
                glVertex2i(cent[0] + 5, cent[1] - 5);
                glEnd();
            } else {
                // try to Explode as a 3x3 square
                if (explosionTimer[i] < 6) {
                    glColor3f(1, 0, 0); // Red
                } else {
                    // Make the explosion disappear after 6 frames
                    exploded[i] = true;
                    continue;
                }
                glBegin(GL_QUADS);
                for (int j = ypos - 1; j <= ypos + 1; j++) {
                    for (int k = xpos - 1; k <= xpos + 1; k++) {
                        if (j >= 0 && k >= 0 && j < MAX_SIZE &&
                                k < MAX_SIZE && walls[j][k] == 0) {
                            int cent[2];
                            getGridCenter(k, j, cent);
                            glVertex2i(cent[0] - 5, cent[1] - 5);
                            glVertex2i(cent[0] - 5, cent[1] + 5);
                            glVertex2i(cent[0] + 5, cent[1] + 5);
                            glVertex2i(cent[0] + 5, cent[1] - 5);
                        }
                    }
                }
                glEnd();
                explosionTimer[i]++;
            }
        }
    }
    bombTimer++;
}


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
