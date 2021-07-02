#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glutSolidSphere(0.5, 100, 100);

	glBegin(GL_POLYGON);

	glEnd();

	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutCreateWindow("OpenGL Example");
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}