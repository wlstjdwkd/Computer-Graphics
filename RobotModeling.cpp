#include <glut.h>						
#include <GL/gl.h>							
#include <GL/glu.h>		

#include "math.h"

void drawLeftArm();
void drawRightArm();
void drawLeftLeg();
void drawRightLeg();
void drawHead();
void drawBody();
void MyDisplay();

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);	// Depth Testing
	glutInitWindowSize(500, 500);
	glutCreateWindow("OpenGL Drawing");

	glEnable(GL_DEPTH_TEST);			// Depth Testing

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.0, 5.0, -5.0, 5.0, -10.0, 10.0);

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutDisplayFunc(MyDisplay);

	glutMainLoop();
	return 0;
}

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//gluLookAt(4, 0, 0, 0, 0, 0, 0, 0, 1);
	//gluLookAt(4, 4, 4, 0, 0, 0, 0, 1, 0);

	// Axis
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);	glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(5.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);	glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(0.0f, 5.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);	glVertex3f(0.0f, 0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 5.0f);
	glEnd();

	// ¸öÅë
	drawBody();

	// ¸Ó¸® 
	drawHead();

	// ÆÈ
	drawLeftArm();
	drawRightArm();

	// ´Ù¸®
	drawLeftLeg();
	drawRightLeg();

	glFlush();
}

void drawHead()
{
	glPushMatrix();
	glColor3f(0.2, 0.3, 0.1);
	glTranslatef(0, 2.8, 0);
	glRotatef(270, 0, 1, 0);
	glutSolidTeapot(0.8);
	glPopMatrix();
}

void drawBody()
{
	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(0, 1, 0);
	glScalef(1, 1, 0.4);
	glutSolidCube(2);
	glPopMatrix();
}

void drawLeftArm()
{
	glColor3f(0.4, 0.5, 0.1);
	glPushMatrix();
	glTranslatef(-1.5, 1, 0);
	glScalef(1, 4, 1);
	glutSolidCube(0.5);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, -0.35, 0);
	glScalef(1, 0.25, 1);
	glutSolidSphere(0.3, 10, 10);
	glPopMatrix();

	glPopMatrix();

}

void drawRightArm()
{
	glColor3f(1, 0.5, 0.1);
	glPushMatrix();
	glTranslatef(1.5, 1, 0);
	glScalef(1, 4, 1);
	glutSolidCube(0.5);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, -0.35, 0);
	glScalef(1, 0.25, 1);
	glutSolidSphere(0.3, 10, 10);
	glPopMatrix();

	glPopMatrix();
}

void drawLeftLeg()
{
	glColor3f(0, 1, 0.5);
	glPushMatrix();
		glTranslatef(-0.5, -2, 0);
		glScalef(1, 6.66, 1);
		glutSolidCube(0.6);
	
		glPushMatrix();
			glColor3f(0, 0, 0);
			glScalef(1, 0.15, 2);
			glTranslatef(0, -2.4, 0.1);
			
			glutSolidCube(0.6);
	
		glPopMatrix();
	glPopMatrix();

}

void drawRightLeg()
{
	glColor3f(0, 1, 0.5);
	glPushMatrix();
	glTranslatef(0.5, -2, 0);
	glScalef(1, 6.66, 1);
	glutSolidCube(0.6);

	glPushMatrix();
	glColor3f(0, 0, 0);
	
	glScalef(1, 0.15, 2);
	glTranslatef(0, -2.4, 0.1);
	glutSolidCube(0.6);

	glPopMatrix();
	glPopMatrix();
}