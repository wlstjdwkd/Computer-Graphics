//#include <glut.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//
//void MyDisplay()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glutSolidTeapot(0.5);
//	glFlush();
//}
//
//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);
//	glutCreateWindow("OpenGL Example");
//	glutDisplayFunc(MyDisplay);
//	glutMainLoop();
//	return 0;
//}

#include <glut.h>						
#include <GL/gl.h>							
#include <GL/glu.h>						

#include <stdio.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glutWireTeapot(0.5);
	glFlush();
}

int main(int argc, char *argv[]) {

	glutInit(&argc, argv);
	glutInitWindowSize(300, 300); // ������ ũ��
	glutInitWindowPosition(100, 100); // (100,100) ��ġ�� ������ 
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	glutCreateWindow("OpenGL Example");
	glutSetWindowTitle("Updated OpenGL Example");

	int screenWidth, screenHeight;
	int windowWidth, windowHeight;
	int windowX, windowY;

	// Properties
	screenWidth = glutGet(20); // ȭ�� �ʺ�
	screenHeight = glutGet(GLUT_SCREEN_HEIGHT); // ȭ�� ũ��
	windowWidth = glutGet(20); // ������ �ʺ�
	windowHeight = glutGet(GLUT_WINDOW_HEIGHT); // ������ ũ��

	windowX = glutGet(GLUT_INIT_WINDOW_X); // ������ X ��ǥ
	windowY = glutGet(GLUT_INIT_WINDOW_Y); // ������ Y ��ǥ

	printf("Screen Info: %d %d\n", screenWidth, screenHeight);
	printf("Window Info: %d %d\n", windowWidth, windowHeight);
	printf("Window pos.: %d %d\n", windowX, windowY);

	glutDisplayFunc(MyDisplay); // �߿� �ڵ� ������ (���÷��� �ݹ� ���)

	glutMainLoop(); // �߿� �ڵ� ������ (�̺�Ʈ ����)
	return 0;
}