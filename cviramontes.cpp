#include <iostream>
#include <cmath>
#include <GL/glx.h>

void initguardCone(float angle, float distance) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); //center of cone
    glColor3f(1.0f, 0.0f, 1.0f); //cone to purple
    for (float i = -angle / 2; i <= angle / 2; i += 1.0f) {
        float rad = i * (M_PI / 180.0f);
        float x = distance * cos(rad);
        float y = distance * sin(rad);
        glVertex2f(x, y);
    }
    glEnd();
}
