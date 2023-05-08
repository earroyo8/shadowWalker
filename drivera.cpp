//Daniel Rivera
#include <GL/glx.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "fonts.h"
#include "drivera.h"
#include "nflessati.h"

//Log of other changes made not found here:
//-----------------------------------------
//Changed Spy and Guard colors
//Changed Board color
//Changed background image
//Changed Spy hitting Guard to a reset instead of gameover (add lives)
//-----------------------------------------
int width = 800;
int height = 600;
Rect r;
int buttonWidth = 10;
int buttonHeight = 10;
int buttonX = (width - buttonWidth) / 3.1;
int buttonY = (height - buttonHeight) / 3.22;

//prints pause screen text, I couldn't find a way to condense this
//or format it well enough using fonts.h
void tutorial(Rect r)
{
    ggprint16(&r, 20, 0x00ffffff, "*Game Paused*");    
    ggprint12(&r, 20, 0x00ffffff, "\n\nWelcome to Shadow Walker! This game is all about navigating your way through");
    ggprint12(&r, 20, 0x00ffffff, "a maze while avoiding your enemies. Watch out for the guards, sneak around");
    ggprint12(&r, 50, 0x00ffffff, "the map, and collect 3 golden keys to win! (Press 'P' to unpause)");
    //insert other tutorials, key inputs, or other important information here 
    ggprint16(&r, 20, 0x00ffffff, "Game Features");
    ggprint12(&r, 20, 0x00ffffff, "Use the arrow keys to navigate the maze"); 
    ggprint12(&r, 20, 0x00ffffff, "Press 'W' to turn off the walls and make the game more challenging"); 
    ggprint12(&r, 20, 0x00ffffff, "        Press 'M' to enable constant movement                     ");
    ggprint12(&r, 20, 0x00ffffff, "    Press 'P' to access this pause menu again while playing       ");
    ggprint12(&r, 20, 0x00ffffff, "Hold 'SHIFT' to sprint");
    ggprint12(&r, 50, 0x00ffffff, "Press 'D' to enter Debug Mode");
    //next set of text
    ggprint16(&r, 20, 0x00ffffff, "Game Legend");
    ggprint12(&r, 20, 0x00ffffff, "-The Spy (This is the player's character)");
    ggprint12(&r, 20, 0x00ffffff, "-The Key (Remember this is your goal)    ");
    ggprint12(&r, 20, 0x00ffffff, "-The Guards (avoid them at all cost)     ");
    ggprint12(&r, 20, 0x00ffffff, "-The Bomb (its a bomb...)               ");
    ggprint12(&r, 20, 0x00ffffff, "-The Teleporters (Press 'T' while on them)");
}

void debugText(Rect r)
{
    ggprint16(&r, 20, 0x00ffffff, "Debug On");
    ggprint12(&r, 20, 0x00ffffff, "'Q' score--");
    ggprint12(&r, 20, 0x00ffffff, "'E' score++");
    ggprint12(&r, 20, 0x00ffffff, "'C' collision");
    ggprint12(&r, 20, 0x00ffffff, "'K' to win");
    ggprint12(&r, 20, 0x00ffffff, "'L' to lose");
}
//win or lose text
void gameOverText(Rect r, int n) 
{
    //win
    if (n == 2) {
        ggprint16(&r, 20, 0x00ffffff, "CONGRATULATIONS YOU HAVE WON!");
        ggprint12(&r, 20, 0x00ffffff, "You are pretty good at this espionage thing.");
        ggprint12(&r, 20, 0x00ffffff, "If you want to play again press 'R' or 'ESC' to quit");
    }
    //lose
    if (n == 1) {
        ggprint16(&r, 20, 0x00ffffff, "YOU LOSE!");
        ggprint12(&r, 20, 0x00ffffff, "Hey, its alright champ not everyone can be a world class spy");
        ggprint12(&r, 20, 0x00ffffff, "If you want to try again press 'R' or 'ESC' to quit");
    }


}

//integer to check a button toggle
int toggle(int n)
{
    if (n == 1)
        n = 0;
    else
        n = 1;
    return n;

}

//returns an integer from a global variable
int checklives(int n)
{
    n--;
    if (n < 1) {
        return n;
    }
    return n;
}

//uses a for loop to draw 3 boxes so the player knows their objectives
void drawMBox(int x, int y, int w, int h, float r, float g, float b) 
{
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {

        if (i == 1) {
            r = 1.0, g = 1.0, b = 0.0;
        }
        if (i == 2) {
            r = 1.0, g = 0.1, b = 0.0;
        }
        if (i == 3) {
            r = 0.0, g = 0.0, b = 0.0;
        }
        if (i == 4) {
            r = 0.0, g = 0.0, b = 1.0;
        } 
        
        glColor3f(r, g, b);
        glVertex2i(x, y-i*20);
        glVertex2i(x + w, y-i*20);
        glVertex2i(x + w, y + h - i*20);
        glVertex2i(x, y + h - i*20);
    
        if (i == 4) {
            r = 1.0, g = 0.5, b = 0.0;
            glColor3f(r, g, b);
            glVertex2i(x-15, y-i*20);
            glVertex2i(x-15 + w, y-i*20);
            glVertex2i(x-15 + w, y + h - i*20);
            glVertex2i(x-15, y + h - i*20);
        }
    }
    glEnd();
}

//first button has set color values
void drawMMenu() 
{
    drawMBox(buttonX, buttonY, buttonWidth, buttonHeight, 0.0, 1.0, 0.1);
}

//draw the buttons
void Mrender() 
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawMMenu();
}

//draws the menu
void showMenu(Rect r)
{
    Mrender();
    tutorial(r);
}


void loseScreen(int x, int y, int w, int h) 
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(x, y);
    glVertex2i(x + w, y);
    glVertex2i(x + w, y + h);
    glVertex2i(x, y + h);
    glEnd();

}

void winScreen(int x, int y, int w, int h) 
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.3, 0.5);
    glVertex2i(x, y);
    glVertex2i(x + w, y);
    glVertex2i(x + w, y + h);
    glVertex2i(x, y + h);
    glEnd();

}

//either display the lose or win screen
void winOrLose(Rect r, int n)
{
    if (n == 1) {
        loseScreen(0, 0, 1500, 1600);
        gameOverText(r, n);
    }
    if (n == 2) {
        winScreen(0, 0, 1500, 1600);
        gameOverText(r, n);
    }
}



