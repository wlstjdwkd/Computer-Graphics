#include "glut.h"						
#include <GL/gl.h>							
#include <GL/glu.h>						

GLint xValue = 0;
GLint yValue = 0;
GLint zValue = 0;

GLint clickDown = 0;
GLint fixX = 0;
GLint fixY = 0;

void MyDisplay(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 차후 강의에서 설명됨
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//gluLookAt(xValue, yValue, zValue, 0, 0, 0, 0, 0, 1);

	glRotatef(xValue, 1.0, 0.0, 0.0);
	glRotatef(yValue, 0.0, 1.0, 0.0);
	glRotatef(zValue, 0.0, 0.0, 1.0);
	glBegin(GL_LINES);   // 좌표축
	glColor3f(1, 0, 0);	// X
	glVertex3f(-1, 0, 0);	glVertex3f(1, 0, 0);
	glColor3f(0, 1, 0);	// Y
	glVertex3f(0, -1, 0);	glVertex3f(0, 1, 0);
	glColor3f(0, 0, 1);	// Z
	glVertex3f(0, 0, -1);	glVertex3f(0, 0, 1);
	glEnd();

	// 도형 그리는 코드 

	
		
		glPushMatrix();
			glTranslatef(0.2, 0, 0);
			glColor3f(1, 0, 0);
			glutSolidCube(0.4);
			
			glPushMatrix();
				glTranslatef(0.4, 0, 0);
				glColor3f(0, 0, 1);
				glutSolidCube(0.4);
					
				glPushMatrix();
					glTranslatef(0, 0.2, 0);
					glColor3f(1, 1, 0);
					glRotatef(-90, 1, 0, 0);
					glutSolidCone(0.2, 0.3, 50, 50);
	
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	
		glTranslatef(-0.2, 0, 0);
		glColor3f(1, 0, 0);
		glutSolidCube(0.4);
	
		glTranslatef(-0.4, 0, 0);
		glColor3f(0, 0, 1);
		glutSolidCube(0.4);
	
		glTranslatef(0, 0.2, 0);
		glColor3f(1, 1, 0);
		glRotatef(-90, 1, 0, 0);
		glutSolidCone(0.2, 0.3, 50, 50);

	glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y){
	switch (KeyPressed){
	case 'X':
	case 'x':
		xValue += 1;
		if (xValue > 360) xValue -= 360;
		break;
	case 'Y':
	case 'y':
		yValue += 1;
		if (yValue > 360) yValue -= 360;
		break;
	case 'Z':
	case 'z':
		zValue += 1;
		if (zValue > 360) zValue -= 360;
		break;
	case 'Q':
	case 'q':
		exit(0); break;
	case 32: // SPACE key
		xValue = 0;
		yValue = 0;
		zValue = 0;
		break;
	case 27: // ESC key
		exit(0);
		break;
	case 3: // CTRL + C
		exit(0);
		break;
	}

	glutPostRedisplay();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y){
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN){
		fixX = X;
		fixY = Y;
		clickDown = 1;
	}
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_UP){
		clickDown = 0;
	}
}

void MyMouseMove(GLint X, GLint Y){

	if (clickDown == 1)
	{
		yValue = yValue + (fixX - X);
		xValue = xValue + (fixY - Y);

		fixX = X;
		fixY = Y;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH); // 차후 강의에서 설명됨

	glutInitWindowSize(600, 600);
	glutCreateWindow("OpenGL Sample Drawing");

	glMatrixMode(GL_PROJECTION);  // 차후 강의에서 설명됨
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -2.0, 2.0);  // 차후 강의에서 설명됨	
	glClearColor(1.0, 1.0, 1.0, 1.0);  // 차후 강의에서 설명됨

	glEnable(GL_DEPTH_TEST); // 차후 강의에서 설명됨

	glutDisplayFunc(MyDisplay);

	glutKeyboardFunc(MyKeyboard);
	glutMouseFunc(MyMouseClick);
	glutMotionFunc(MyMouseMove);

	glutMainLoop();
	return 0;
}

//#include <glut.h>
//#include <GL/gl.h>	
//#include <GL/glu.h>
//
//void MyDisplay()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	gluLookAt(0, 0.3, 0.4, 0, 0, 0, 0, 1, 0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glBegin(GL_LINES);
//	glColor3f(1, 0, 0);	// X
//	glVertex3f(-1, 0, 0);		glVertex3f(1, 0, 0);
//	glColor3f(0, 1, 0);	// Y
//	glVertex3f(0, -1, 0);		glVertex3f(0, 1, 0);
//	glColor3f(0, 0, 1);	// Z
//	glVertex3f(0, 0, -1);		glVertex3f(0, 0, 1);
//	glEnd();
//
//	// 장면 모델링 코드
//	
//
//	glLoadIdentity();
//	
//	glPushMatrix();
//		glTranslatef(0.2, 0, 0);
//		glColor3f(1, 0, 0);
//		glutSolidCube(0.4);
//		
//		glPushMatrix();
//			glTranslatef(0.4, 0, 0);
//			glColor3f(0, 0, 1);
//			glutSolidCube(0.4);
//				
//			glPushMatrix();
//				glTranslatef(0, 0.2, 0);
//				glColor3f(1, 1, 0);
//				glRotatef(-90, 1, 0, 0);
//				glutSolidCone(0.2, 0.3, 50, 50);
//
//			glPopMatrix();
//		glPopMatrix();
//	glPopMatrix();
//
//	glTranslatef(-0.2, 0, 0);
//	glColor3f(1, 0, 0);
//	glutSolidCube(0.4);
//
//	glTranslatef(-0.4, 0, 0);
//	glColor3f(0, 0, 1);
//	glutSolidCube(0.4);
//
//	glTranslatef(0, 0.2, 0);
//	glColor3f(1, 1, 0);
//	glRotatef(-90, 1, 0, 0);
//	glutSolidCone(0.2, 0.3, 50, 50);
//
//	
//
//	/*glPushMatrix();
//		glTranslatef(0.6, 0.2, 0);
//		glColor3f(1, 1, 0);
//		glutSolidCone(0.2, 0.3, 50, 50);
//		
//		glPushMatrix();
//			glTranslatef(0, -0.2, 0);
//			glColor3f(0, 0, 1);
//			glutSolidCube(0.4);
//				
//			glPushMatrix();
//				glTranslatef(-0.4, 0, 0);
//				glColor3f(1, 0, 0);
//				glutSolidCube(0.4);
//	
//			glPopMatrix();
//			glutSolidCube(0.4);*/
//	glFlush();
//
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//
//	glutInitWindowSize(600, 600);
//	glutCreateWindow("OpenGL Sample Drawing");
//
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//
//	glMatrixMode(GL_PROJECTION); // 차후 강의에서 설명
//	glLoadIdentity(); // 차후 강의에서 설명
//	
//
//	glutDisplayFunc(MyDisplay);
//	glutMainLoop();
//	return 0;
//}
