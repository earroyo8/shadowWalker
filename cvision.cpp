#include <cmath>
#include <X11/Xlib.h>
#include <GL/glx.h>


//draw the cone of vision
void DrawLoopSegment(int centerX, int centerY, int sides, XColor color, float alpha, int innerRadius, int outerRadius, double startDegree, double endDegree, Display* display, GLXContext glxContext, GLXDrawable glxDrawable) {
    glXMakeCurrent(display, glxDrawable, glxContext);
    glColor4f(static_cast<float>(color.red) / 65535.0, static_cast<float>(color.green) / 65535.0, static_cast<float>(color.blue) / 65535.0, alpha);
    glBegin(GL_QUAD_STRIP);
    double degrees = endDegree - startDegree;
    for (int i = 0; i <= sides; i++) {
        glVertex3f(centerX + (sin(startDegree + (degrees * ((float) i / (float) sides)))) * innerRadius,
                   centerY - (cos(startDegree + (degrees * ((float) i / (float) sides)))) * innerRadius, 0);
        glVertex3f(centerX + (sin(startDegree + (degrees * ((float) i / (float) sides)))) * outerRadius,
                   centerY - (cos(startDegree + (degrees * ((float) i / (float) sides)))) * outerRadius, 0);
    }
    glEnd();
    glColor4f(1, 1, 1, 1);
}
