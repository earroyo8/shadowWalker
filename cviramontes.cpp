//name: Christian Viramontes

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>

#include "cviramontes.h"

//instead of press-release, it'll be
//press-hold-release
int checkKeys(XEvent *e)
{
	static int shift=0;
	if (e->type != KeyRelease && e->type != KeyPress)
		return 0;
	int key = (XLookupKeysym(&e->xkey, 0) & 0x0000ffff);
	if (e->type == KeyRelease) {
		if (key == XK_Shift_L || key == XK_Shift_R)
			shift=0;
		return 0;
	}
	if (key == XK_Shift_L || key == XK_Shift_R) {
		shift=1;
		return 0;
	}
	(void)shift;
	switch (key) {
		case XK_r:
			resetGame();
			break;
		case XK_equal:
			g.snake.delay *= 0.9;
			if (g.snake.delay < 0.001)
				g.snake.delay = 0.001;
			break;
		case XK_minus:
			g.snake.delay *= (1.0 / 0.9);
			break;
		case XK_Left:
			g.snake.direction = DIRECTION_LEFT;
			break;
		case XK_Right:
			g.snake.direction = DIRECTION_RIGHT;
			break;
		case XK_Up:
			g.snake.direction = DIRECTION_UP;
			break;
		case XK_Down:
			g.snake.direction = DIRECTION_DOWN;
			break;
	}
	return 0;
}

int checkMouse(XEvent *e)
{
	static int savex = 0;
	static int savey = 0;
	int i,x,y;
	int lbutton=0;
	int rbutton=0;
	//
	if (e->type == ButtonRelease)
		return 0;
	if (e->type == ButtonPress) {
		if (e->xbutton.button==1) {
			//Left button is down
			lbutton=1;
		}
		if (e->xbutton.button==3) {
			//Right button is down
			rbutton=1;
			if (rbutton){}
		}
	}
	x = e->xbutton.x;
	y = e->xbutton.y;
	y = g.yres - y;
	if (savex != e->xbutton.x || savey != e->xbutton.y) {
		//Mouse moved
		savex = e->xbutton.x;
		savey = e->xbutton.y;
	}
	for (i=0; i<g.nbuttons; i++) {
		g.button[i].over=0;
		if (x >= g.button[i].r.left &&
			x <= g.button[i].r.right &&
			y >= g.button[i].r.bot &&
			y <= g.button[i].r.top) {
			g.button[i].over=1;
			if (g.button[i].over) {
				if (lbutton) {
					switch (i) {
						case 0:
							resetGame();
							break;
						case 1:
							printf("Quit was clicked!\n");
							return 1;
					}
				}
			}
		}
	}
	return 0;
}