

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float ax, ay, bx, by, cx, cy;
int WinW = 1000,
    WinH = 1000;
void points(){
    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_LINE_LOOP);
        glVertex2f(ax * 10, ay * 10);
        glVertex2f(bx * 10, by * 10);
        glVertex2f(cx * 10, cy * 10);
    glEnd();
}

void grid(){
    glColor3f(0.8, 0.8, 0.8);

    glBegin(GL_LINES);
    for (float i = -WinW / 2; i <= WinW / 2; i += 10) {

            glVertex2f(i, -WinH / 2);
            glVertex2f(i, WinH / 2);

            glVertex2f(-WinW / 2, i);
            glVertex2f(WinW / 2, i);
    }
    glEnd();
}

void axes(){
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_LINES);
        glVertex2f(-WinW / 2, 0);
        glVertex2f(WinW / 2, 0);
        glVertex2f(0, -WinH / 2);
        glVertex2f(0, WinH / 2);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
        grid();
        axes();
        points();
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

    glOrtho(-WinW / 2, WinW / 2, -WinH / 2, WinH / 2, -1, 1);


    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
