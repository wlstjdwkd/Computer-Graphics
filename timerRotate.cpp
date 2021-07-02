#include <glut.h>						
#include <GL/gl.h>							
#include <GL/glu.h>		

int zRotate = 0; // 회전 값을 보관
int zDir = 0;

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	glLoadIdentity();

	glRotatef(zRotate, 0.0, 0.0, 1.0);

	glutWireTeapot(0.5);

	glFlush();
}

void MyTimer(int Value)
{
	if (zDir == 1)
		zRotate += 10;
	else
		zRotate -= 10;

	glutTimerFunc(100, MyTimer, 1);
	glutPostRedisplay();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y)
{
	switch (KeyPressed){
	case 'Q':
		exit(0); break;
	case 'q':
		exit(0); break;
	case 'Z':
		zDir = 1;
		break;
	case 'z':
		zDir = 0;
		break;
	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutCreateWindow("OpenGL Example");

	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);

	glutTimerFunc(100, MyTimer, 1);

	glutMainLoop();
	return 0;
}