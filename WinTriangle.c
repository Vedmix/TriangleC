#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float ax, ay, bx, by, cx, cy;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

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
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Triangle");
    glClearColor(1, 1, 1, 1.0);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}

