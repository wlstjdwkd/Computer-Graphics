#include <glut.h>						
#include <GL/gl.h>							
#include <GL/glu.h>						

int zRotate = 0; // ȸ�� ���� ����

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	glRotatef(zRotate, 0.0, 0.0, 1.0); // (x, y, z) �߿��� z�� 1�� �ش��Ͽ� z �� ȸ����

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

	glutKeyboardFunc(MyKeyboard); // Ű���� �ݹ� �߰�

	glutMainLoop();
	return 0;
}