//Nathan Flessati
#include <GL/glx.h>
#include <cstdlib>
#include <iostream>
#include "nflessati.h"

void getGridCenter(const int i, const int j, int cent[2]);


int walls[MAX_SIZE][MAX_SIZE];

int guardHit(int headpos[2], int xpos,int ypos)
{
    int gameover = 0;
    if (headpos[0] == xpos && headpos[1] == ypos) {
        gameover=1;
    }

    return gameover;
}
bool wallHit(int spyposx,int spyposy)
{
    bool result = false;
    if (walls[spyposy][spyposx]==1)
    {
        result = true;
    }
    return result;
}

void randDir(int directions[4])
{
    int i;
    int r = rand()%4;
    int temp1[4];
    int temp2[4];
    for (i=0;i<4;i++) {
        temp1[i]=directions[i];
        temp2[i]=directions[i];
    }
    for (i=0;i<4;i++) {
        if (r!=i) {
        directions[i]=temp1[r];
        directions[r]=temp2[i];
        r = rand()%4;
        }
    }
}
void expand(int row, int col) 
{
    int rDir[4]={1,2,3,4};
    randDir(rDir);
    int i;
    int length = sizeof(rDir)/sizeof(rDir[0]);
    for (i=0;i<length;i++) {
        switch (rDir[i]) {

            case 1: //up
                if (row-2<=0) {
                    continue;
                }
                if (walls[row-2][col] != 0) {
                    walls[row-2][col]=0;
                    walls[row-1][col]=0;
                    expand(row-2,col);
                }
                break;

            case 2: //down
                if (row+2>=MAX_SIZE-1) {
                    continue;
                }
                if (walls[row+2][col] != 0) {
                    walls[row+2][col]=0;
                    walls[row+1][col]=0;
                    expand(row+2,col);
                }
                break;

            case 3: //right
                if (col+2>=MAX_SIZE-1) {
                    continue;
                }
                if (walls[row][col+2]!=0) {
                    walls[row][col+2]=0;
                    walls[row][col+1]=0;
                    expand(row,col+2);
                }
                break;
            case 4: //left
                if (col-2<=0) {
                    continue;
                }
                if (walls[row][col-2]!=0) {
                    walls[row][col-2]=0;
                    walls[row][col-1]=0;
                    expand(row,col-2);
                }
                break;
        }
    }

}



void initWalls() 
{
    int i;
    int j;
    for (i=0;i<MAX_SIZE;i++) {
        for (j=0;j<MAX_SIZE;j++) {
            walls[i][j]=1;
        }
    } 

    int row = rand() % MAX_SIZE;
    while (row%2 ==0) {
        row = rand() % MAX_SIZE;
    }
    int col = rand() % MAX_SIZE;
    while (col%2 ==0) {
        col = rand() % MAX_SIZE;
    }

    walls[row][col] = 0;

    expand(row,col);

}

void drawWalls()
{
    int i;
    int j;
    int cent[2];
    for (i=0;i<MAX_SIZE;i++) {
        for (j=0;j<MAX_SIZE;j++) {
            if (walls[i][j] == 0) {
                glColor3f(1.0f, 1.0f, 1.0f);
                glBegin(GL_QUADS);
                getGridCenter(i,j,cent);
                glVertex2i(cent[0]+4, cent[1]+4);
                glVertex2i(cent[0]+4, cent[1]-4);
                glVertex2i(cent[0]-4, cent[1]-4);
                glVertex2i(cent[0]-4, cent[1]+4);
                glEnd();
            } else {
                glColor3f(0.5f, 0.5f, 0.5f);
                glBegin(GL_QUADS);
                getGridCenter(i,j,cent);
                glVertex2i(cent[0]+5, cent[1]+5);
                glVertex2i(cent[0]+5, cent[1]-5);
                glVertex2i(cent[0]-5, cent[1]-5);
                glVertex2i(cent[0]-5, cent[1]+5);
                glEnd();

            }
        }
    }
}
