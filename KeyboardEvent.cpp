#include <glut.h>						
#include <GL/gl.h>							
#include <GL/glu.h>						

int zRotate = 0; // 회전 값을 보관

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	glRotatef(zRotate, 0.0, 0.0, 1.0); // (x, y, z) 중에서 z가 1에 해당하여 z 축 회전임

	glutSolidTeapot(0.5);

	glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y)
{
	switch (KeyPressed){
	case 'Q':
		exit(0); break;
	case 'q':
		exit(0); break;
	case 'Z':
		zRotate += 10; break;
	case 'z':
		zRotate -= 10; break;
	}

	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutCreateWindow("OpenGL Example");
	glutDisplayFunc(MyDisplay);

	glutKeyboardFunc(MyKeyboard); // 키보드 콜백 추가

	glutMainLoop();
	return 0;
}