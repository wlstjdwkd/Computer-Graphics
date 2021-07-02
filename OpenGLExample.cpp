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
	glutInitWindowSize(300, 300); // 윈도우 크기
	glutInitWindowPosition(100, 100); // (100,100) 위치에 윈도우 
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	glutCreateWindow("OpenGL Example");
	glutSetWindowTitle("Updated OpenGL Example");

	int screenWidth, screenHeight;
	int windowWidth, windowHeight;
	int windowX, windowY;

	// Properties
	screenWidth = glutGet(20); // 화면 너비
	screenHeight = glutGet(GLUT_SCREEN_HEIGHT); // 화면 크기
	windowWidth = glutGet(20); // 윈도우 너비
	windowHeight = glutGet(GLUT_WINDOW_HEIGHT); // 윈도우 크기

	windowX = glutGet(GLUT_INIT_WINDOW_X); // 윈도우 X 좌표
	windowY = glutGet(GLUT_INIT_WINDOW_Y); // 윈도우 Y 좌표

	printf("Screen Info: %d %d\n", screenWidth, screenHeight);
	printf("Window Info: %d %d\n", windowWidth, windowHeight);
	printf("Window pos.: %d %d\n", windowX, windowY);

	glutDisplayFunc(MyDisplay); // 중요 코드 생략됨 (디스플레이 콜백 등록)

	glutMainLoop(); // 중요 코드 생략됨 (이벤트 루프)
	return 0;
}