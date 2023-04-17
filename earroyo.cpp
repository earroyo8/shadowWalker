//Estevan Arroyo
//earroyo.cpp file
//moved reset fucntion here
//
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "earroyo.h"

struct Global {
/*    int xres, yres;
    Grid grid[MAX_GRID][MAX_GRID];
    Spy spy;
    Guard guard;
    int gridDim;
    int boardDim;               */
    int gameover;
    int winner;
/*    Image *marbleImage;
    GLuint marbleTexture;
    Button button[MAXBUTTONS];
    int nbuttons;
    //
    ALuint alBufferDrip, alBufferTick;
    ALuint alSourceDrip, alSourceTick;
    Global() {
        xres = 800;
        yres = 600;
        gridDim = 40;
        gameover = 0;
        winner = 0;
        nbuttons = 0;
        marbleImage=NULL;
    }                           */
} ge;

void resetGame()
{
    initSpy();
    initGuard();
    ge.gameover  = 0;
    ge.winner    = 0;
}

