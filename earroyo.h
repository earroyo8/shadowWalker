//Estevan Arroyo
//earroyo.h file
//
#define MAX_SIZE 40

extern int score;

extern void featureMode();
extern void initSpy();
extern void initGuard();
extern void initKey();
extern void resetGame(int n);
extern void incrementScore();
extern void drawBomb(int xpos, int ypos, int timer);
extern void drawBombs(int numBombs, int timer);
