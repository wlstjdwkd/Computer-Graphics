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

	//Scaling -> Translate -> Rotation
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glTranslatef(0.5, 0.0, 0.0);
	glScalef(2.0, 2.0, 2.0);
	

	/* Rotation -> Scaling -> Translate
	glTranslatef(0.5, 0.0, 0.0);
	glScalef(2.0, 2.0, 2.0);
	glRotatef(45.0, 0.0, 0.0, 1.0);
	*/

	/* Translation -> Rotation -> Scaling
	glScalef(2.0, 2.0, 2.0);		// check scaling effects
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glTranslatef(0.5, 0.0, 0.0);
	*/

	glColor3f(0.0, 0.0, 1.0);
	// glutSolidCube(0.4);
	// glutWireTeapot(0.4);
	glBegin(GL_POLYGON);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);

	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("OpenGL Sample Drawing");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	/*
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	*/

	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}