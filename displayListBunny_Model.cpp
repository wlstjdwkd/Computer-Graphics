#include <glut.h>					
#include <GL/gl.h>						
#include <GL/glu.h>	

#include "BunnyModel.h"

GLuint g_stanfordBunnyID = -1;

GLint GenerateCallList()
{
	unsigned int i;

	GLint lid = glGenLists(1);

	glNewList(lid, GL_COMPILE);

	glColor3f(1.0f, 0.0f, 0.0f);

	for (i = 0; i<(sizeof(face_indicies) / sizeof(face_indicies[0])); i++)
	{
		int vi;

		glBegin(GL_LINES);
		vi = face_indicies[i][0];
		glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][1];
		glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);

		vi = face_indicies[i][1];
		glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][2];
		glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);

		vi = face_indicies[i][2];
		glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][0];
		glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		glEnd();
	}

	glEndList();

	return lid;
}

void MyDisplay(){

	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	glColor3f(1.0f, 0.0f, 0.0f);

	// display Call Lists
	glCallList(g_stanfordBunnyID);

	glFlush();

}

void MyKeyboard(unsigned char KeyPressed, int X, int Y){
	switch (KeyPressed){
	case 'Q':
		exit(0); break;
	case 'q':
		exit(0); break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);

	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(0.0, 0.0, 0.0, 0.0);

	g_stanfordBunnyID = GenerateCallList();

	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutMainLoop();
	return 0;
}