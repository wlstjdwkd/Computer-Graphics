#include <glut.h>
#include <GL/gl.h>	
#include <GL/glu.h>

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBegin(GL_LINES);
	glColor3f(1, 0, 0);	// X
	glVertex3f(-1, 0, 0);		glVertex3f(1, 0, 0);
	glColor3f(0, 1, 0);	// Y
	glVertex3f(0, -1, 0);		glVertex3f(0, 1, 0);
	glColor3f(0, 0, 1);	// Z
	glVertex3f(0, 0, -1);		glVertex3f(0, 0, 1);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glutWireTeapot(0.3);

	glPushMatrix();
	glTranslatef(2.0, 2.0, 0.0);
	glutWireTeapot(0.3);

	glPushMatrix();
	glTranslatef(3.0, -1.0, 0.0);
	glRotatef(45, 0.0, 0.0, 1.0);
	glScalef(2.0, 2.0, 2.0);
	glutWireTeapot(0.3);
	glPopMatrix();
	glPopMatrix();

	glTranslatef(0.0, -2.0, 0.0);
	glutWireTeapot(0.3);

	glFlush();

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitWindowSize(600, 600);
	glutCreateWindow("OpenGL Sample Drawing");

	glClearColor(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-6.0, 6.0, -6.0, 6.0, -1.0, 1.0);

	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
