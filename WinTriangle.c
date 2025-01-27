
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float ax, ay, bx, by, cx, cy;
int WinW = 800,
    WinH = 800;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_LINE_LOOP);
        glVertex2f(ax / 5, ay / 5); 
        glVertex2f(bx / 5, by / 5); 
        glVertex2f(cx / 5, cy / 5); 
    glEnd();

    glFlush();
}

int main(int argc, char *argv[]) {

    ax = atof(argv[1]);
    ay = atof(argv[2]);
    bx = atof(argv[3]);
    by = atof(argv[4]);
    cx = atof(argv[5]);
    cy = atof(argv[6]);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WinW, WinH);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Triangle");
    glClearColor(1, 1, 1, 1.0);

    glOrtho(-WinW / 2, WinW / 2, WinH / 2, -WinH / 2, 0, 0);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
