#include <glut.h>						
#include <GL/gl.h>							
#include <GL/glu.h>		

#include <stdio.h>

GLuint g_stanfordBunnyID = -1;

GLint xValue = 0;
GLint yValue = 0;
GLint zValue = 0;

GLint clickDown = 0;
GLint fixX = 0;
GLint fixY = 0;

GLint zDistance = 2; //  -2;   // increase & decrease + / -
GLint fovValue = 45; // 45;	// increase & decrease [ / ]


void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glViewport(0,0,300,300);
	glColor3f(0, 1, 0.4);
	glPushMatrix();
	gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);
	glutWireTeapot(0.5);
	glPopMatrix();
	
	glViewport(0, 300, 300, 300);
	glColor3f(1, 0.2, 0.3);
	glPushMatrix();
	gluLookAt(0, 1, 0, 0, 0, 0, 1, 0, 0);
	glutWireTeapot(0.5);
	glPopMatrix();

	glViewport(300, 300, 300, 300);
	glColor3f(0, 0, 0.7);
	glPushMatrix();
	gluLookAt(1, 0, 1, 0, 0, 0, 0, 1, 0);

	glutWireTeapot(0.5);
	glPopMatrix();

	glViewport(300, 0, 300, 300);
	glColor3f(0.5, 0.2, 0.4);
	glPushMatrix();
	gluLookAt(1, 0, 0, 0, 0, 0, 0, 1, 0);

	glutWireTeapot(0.5);
	glPopMatrix();

	glFlush();

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutCreateWindow("OpenGL Example");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -2.0, 2.0);

	glClearColor(0.0, 0.0, 0.0, 0.0);


	glutDisplayFunc(MyDisplay);
	glutMainLoop();

	return 0;
}
