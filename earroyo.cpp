//Estevan Arroyo
//earroyo.cpp file
//
#include <GL/glx.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include "earroyo.h"
/*
typedef struct key {
    int status;
    int pos[2];
} Key;
*/

struct Global {
//    Key key;
    int gameover;
    int winner;
} ge;

void resetGame() {
    initSpy();
    initGuard();
//    initKey();
    ge.gameover  = 0;
    ge.winner    = 0;
}

/*
//Draw Key on board
void drawKey() {
    int cent[2];
    getGridCenter(ge.key.pos[10],ge.key.pos[10]+1,cent);
    glColor3f(0.8, 0.498039f, 0.196078f);
    glBegin(GL_QUADS);
    glVertex2i(cent[0]-4, cent[1]-4);
    glVertex2i(cent[0]-4, cent[1]+4);
    glVertex2i(cent[0]+4, cent[1]+4);
    glVertex2i(cent[0]+4, cent[1]-4);
    glEnd();
}
*/

/*
void initKey() {
    ge.key.status = 1;
    ge.key.pos[0] = 30 ;
    ge.key.pos[1] = 2;
}
*/


/*
// physics
    //did the spy get the key???
    if (headpos[0] == g.key.pos[0] && headpos[1] == g.key.pos[1]) {
        int collision=0;
        int ntries=0;
        while (1) {
            g.key.pos[0] = rand() % g.gridDim;
            g.key.pos[1] = rand() % g.gridDim;
            collision=0;
                for (i=0; i<g.spy.length; i++) {
                    if (g.key.pos[0] == g.spy.pos[i][0] &&
                        g.key.pos[1] == g.spy.pos[i][1]) {
                        collision=1;
                        break;
                    }
                }
                if (!collision) break;
                if (++ntries > 1000000) break;
        }
        return;
    }

//render - Draw Key on board
void drawKey() {
     getGridCenter(g.key.pos[10],g.key.pos[10]+1,cent);
     glColor3f(0.8, 0.498039f, 0.196078f);
     glBegin(GL_QUADS);
     glVertex2i(cent[0]-4, cent[1]-4);
     glVertex2i(cent[0]-4, cent[1]+4);
     glVertex2i(cent[0]+4, cent[1]+4);
     glVertex2i(cent[0]+4, cent[1]-4);
     glEnd();
}
*/

/*
// WORK IN PROGRESS -- ScoreBoard --
ScoreBoard::ScoreBoard(void)
    :packagesFound(0),
    displayScore(true),
    resetButton("Reset",Point(0,0,0),20,20,Color(1.0,1.0,1.0,1.0),Color(0.0,0.0,0.0,1.0))
{
    defaultMessage="Key Found: ";
}

ScoreBoard::ScoreBoard(Point newCorner, GLfloat newHeight, GLfloat newWidth,char* Text, int newPackagesFound)
    :cornerPt(newCorner),
    height(newHeight),
    width(newWidth),
    displayScore(true),
    keyFound(newKeyFound),
    resetButton("Reset",newCorner,20,30,Color(1.0,1.0,1.0,1.0),Color(0.0,0.0,0.0,1.0))
{
    defaultMessage = Text;
}

ScoreBoard::~ScoreBoard(void)
{
}

void ScoreBoard::incrementKeyFound()
{
    keyFound++;
}

void ScoreBoard::resetPackagesFound()
{
    keysFound=0;
}
void ScoreBoard::display(bool overheadView)
{
    //resetButton.display();
     stringstream ss (stringstream::in | stringstream::out);

        glColor3f(1.0,1.0,1.0);
        glRasterPos2f(cornerPt.x,cornerPt.y);
        int len = (int) strlen(defaultMessage);
        for (int i = 0; i < len; i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, defaultMessage[i]);
        }
        if(displayScore)
        {
            ss << packagesFound;
            string tmpMsg;
            ss>>tmpMsg;
            len = (int)strlen(tmpMsg.c_str());
            for (int i = 0; i < len; i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, tmpMsg[i]);
            }
        }
         stringstream ss2 (stringstream::in | stringstream::out);

        len=strlen(msg2);
        if(overheadView)
            glRasterPos2f(cornerPt.x,cornerPt.y+2);
        else
            glRasterPos2f(cornerPt.x,cornerPt.y+1.5);
        for (int i = 0; i < len; i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg2[i]);
        }
}

void ScoreBoard::setDimensions(Point newCorner,GLfloat newHeight, GLfloat newWidth)
{
    cornerPt = newCorner;
    height = newHeight;
    width = newWidth;

    resetButton.setDimensions(Point(cornerPt.x+newWidth/2,cornerPt.y,0),newHeight/15,newWidth/5);
}

Button& ScoreBoard::getResetButton()
{
    return resetButton;
}

void ScoreBoard::setMessage(char* newMessage)
{
    defaultMessage = newMessage;
}

void ScoreBoard::setMsg2(char* newMessage)
{
    msg2 = newMessage;
}
void ScoreBoard::setDisplayScore(bool newDisplayScore)
{
    displayScore = newDisplayScore;
}
*/

/*
// FEATURE - PROGRESS Main charachter will cast ambient light - rest of the board will go dark
void light() {
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    vec3 result = ambient * objectColor;
    FragColor = vec4(result, 1.0);
    //
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aNormal;

    glVertexAttribPointer(0,3, GL_Float, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}
*/
