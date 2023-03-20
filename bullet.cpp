const int MAX_BULLETS = 15;

class Bullet {
    public: 
	Vec pos; 
	Vec vel;
	float color[3];
	struct timespec time;
    public: 
	Bullet() { }
};

void physics() {
    struct timespec bt;
    clock_gettime(CLOCK_REALTIME, &bt);
    int i = 0;
    while (i < g.nbullets) {
	Bullet *b = &g.bar[i];
	//bullet alive?
	double ts = timeDiff(&b->time, &bt);
	if (ts > 2.5) {
	    //delete bullet
	    memcpy(&g.barr[i], &g.barr[g.nbullets-1],
		    sizeof(Bullet));
	    g.nbullets--;
	    continue;
	}
	//move bullet
	b->pos[0] += b->vel[0];
	b->pos[1] += b->vel[1];
    }

    //check collision with rat?
    // 1. delete bullet
    // 2. delete rat
    a = g.ahead;
    while (a) {
	int i = 0;
	while (i < g.nbullets) { 
	    Bullet *b = &g.barr[i];
	    d0 = b->pos[0] - a->pos[0];
	    d1 = b->pos[1] - a->pos[1];
	    dist = (d0*d0 + d1*d1);
	    if (dist < (a->radius*a->radius)) {
		//delete bullet
		memcpy(&g.barr[i]. &g.barr[n.bullets-1], sizeof(Bullet));
		g.nbullets--;
		if (a == NULL)
		    break;
	    }
	    i++;
	}
	if (a == NULL)
	    break;
	a = a->next;
    }

    //shoot bullet
    if (gl.keys[]) {
	struct timespec bt;
	clock_gettime(CLOCK_REALTIME, &bt);
	double ts = timeDiff(&g.bulletTimer, &bt);
	if (ts > 0.1) {
	    timeCopy(g.nbullets < MAX_BULLETS) {
		Bullet *b = &g.barr[g.nbullets];
		timeCopy(&b->time, &bt);
		b->pos[0] = g.player.pos[0];
		b->pos[1] = g.player.pos[1];
		b->vel[0] = g.player.vel[0];
		b->vel[1] = g.player.vel[1];
	    }
	}
    }
}

void render() {
    for (int i=0; i<g.nbullets; i++) {
	Bullet *b = &g.barr[i];
	//Log("draw bullet...\n");
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2f(b->pos[0],      b->pos[1]);
	glVertex2f(b->pos[0]-1.0f, b->pos[1]);
	glVertex2f(b->pos[0]+1.0f, b->pos[1]);
	glVertex2f(b->pos[0],      b->pos[1]-1.0f);
	glVertex2f(b->pos[0],      b->pos[1]+1.0f);
	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(b->pos[0]-1.0f, b->pos[1]-1.0f);
	glVertex2f(b->pos[0]-1.0f, b->pos[1]+1.0f);
	glVertex2f(b->pos[0]+1.0f, b->pos[1]-1.0f);
	glVertex2f(b->pos[0]+1.0f, b->pos[1]+1.0f);
	glEnd();
    }
}
