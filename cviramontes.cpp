//enemy pathing to player
#include <vector>
#include <csdtlib>
#include <ctime>


//enemy & player are placeholder for desired game character names
bool playerCollision(float x1, float y1, float width1, float height1, float x2, float y2, float width2, float height2) {
    return (x1 < x2 + width2 && x1 + width1 > x2 && y1 < y2 + height2 && y1 + height1 > y2);
}

void moveEnemyToPlayer(float enemyX, float enemyY, float playerX, float playerY, float deltaTime) { 
    float speed = 0.1f; //adjust for desired speed
    float dx = playerX - enemyX;
    float dy = playerY - enemyY;
    float distance = sqrt((dx * dx) + (dy * dy));
    if (distance > 0.0f) {
	float dirX = dx / distance;
	float dirY = dy / distance;
	float movX = speed * dirX * deltaTime;
	float movY = speed * dirY * deltaTime;
	float nextX = enemyX + movX;
	float nextY = enemyY + movY;
	if (!playerCollision(nextX, nextY, enemyWidth, enemyHeight, playerX, playerY, playerWidth, playerHeight)) {
	    enemyX = nextX;
	    enemyY = nextY;
	}
    }
}
