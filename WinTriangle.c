#include <GL/glut.h>

int WinWidth  = 700,
    WinHeight = 500;

void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	glFlush();
}

int main( int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WinWidth, WinHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Triangle");
	glClearColor(1, 1, 1, 1.0);

	glutDisplayFunc(display);



	glutMainLoop();
	return 0;
}	
