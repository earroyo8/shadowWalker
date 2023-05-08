#ifndef _CVIRAMONTES_H_
#define _CVIRAMONTES_H_

//def and const
#define DIRECTION_DOWN 0
#define DIRECTION_LEFT 1
#define DIRECTION_UP 2
#define DIRECTION_RIGHT  3
#define NO_MOVEMENT 4

extern void updateGuardPos(int& direction, int& x, int& y);
extern void initguardCone(float angle, float distance);
extern void incrementGuard(int& enemyCount);

#endif
