#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "BunnyModel.h"

// 와이어프레임 렌더링
void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	glColor3f(1.0f, 1.0f, 1.0f);

	unsigned int i;
	int j;
	for (i = 0; i<(sizeof(face_indicies) / sizeof(face_indicies[0])); i++)
	{
		int vi;

		glBegin(GL_LINES);
		vi = face_indicies[i][0];	glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][1];	glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);

		vi = face_indicies[i][1];	glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][2];	glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);

		vi = face_indicies[i][2];	glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][0];	glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		glEnd();

		/*
		glBegin(GL_LINES);
		vi=face_indicies[i][0];	glVertex3fv(vertices[vi]);
		vi=face_indicies[i][1];	glVertex3fv(vertices[vi]);

		vi=face_indicies[i][1];	glVertex3fv(vertices[vi]);
		vi=face_indicies[i][2];	glVertex3fv(vertices[vi]);

		vi=face_indicies[i][2];	glVertex3fv(vertices[vi]);
		vi=face_indicies[i][0];	glVertex3fv(vertices[vi]);
		glEnd ();
		*/
	}
	glFlush();
}

//// 솔리드 렌더링
//void MyDisplay()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glLoadIdentity();
//
//	glColor3f(1.0f, 1.0f, 1.0f);
//
//	unsigned int i;
//	int j;
//
//	for (i = 0; i<(sizeof(face_indicies) / sizeof(face_indicies[0])); i++)
//	{
//		int vi;
//
//		glBegin(GL_TRIANGLES);
//		vi = face_indicies[i][0];
//		glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
//		vi = face_indicies[i][1];
//		glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
//		vi = face_indicies[i][2];
//		glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
//		glEnd();
//
//		/*
//		glBegin(GL_TRIANGLES);
//		vi=face_indicies[i][0];	glVertex3fv(vertices[vi]);
//		vi=face_indicies[i][1];	glVertex3fv(vertices[vi]);
//		vi=face_indicies[i][2];	glVertex3fv(vertices[vi]);
//		glEnd ();
//		*/
//	}
//
//	glFlush();
//}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutCreateWindow("OpenGL Example");
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}