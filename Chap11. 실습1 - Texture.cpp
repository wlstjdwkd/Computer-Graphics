
#include <stdio.h>

#include <glut.h>	
#include <GL/gl.h>
#include <GL/glu.h>

#include "bmp.h"


GLfloat xrot = 0.9f;
GLfloat yrot = 0.8f;
GLfloat zrot = 1.0f;

unsigned int MyTextureObject[1];

AUX_RGBImageRec * pTextureImage[1]; //�ؽ��� ���� ������ ����Ű�� ������    

char fileName[16] = "./test.bmp";

void MyDisplay()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);

	// �ո�
	glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);			
		glTexCoord2f(3, 3); glVertex3f(1, 1, 1);
		glTexCoord2f(3, 0);    glVertex3f(1, -1, 1);
		glTexCoord2f(0, 0); glVertex3f(-1, -1, 1);
		glTexCoord2f(0, 3); glVertex3f(-1, 1, 1);
	glEnd();
	// �޸�
	glBegin(GL_POLYGON);
		glColor3f(0, 1 ,0);		
		glTexCoord2f(1, 1); glVertex3f(1, 1, -1);
		glTexCoord2f(1, 0); glVertex3f(1, -1, -1);
		glTexCoord2f(0, 0); glVertex3f(-1, -1, -1);
		glTexCoord2f(0, 1); glVertex3f(-1, 1, -1);
	glEnd();
	// ����
	glBegin(GL_POLYGON);
		glColor3f(0, 0, 1);		
		glTexCoord2f(1, 1); glVertex3f(1, 1, 1);
		glTexCoord2f(1, 0); glVertex3f(1, 1, -1);
		glTexCoord2f(0, 0); glVertex3f(-1, 1, -1);
		glTexCoord2f(0, 1); glVertex3f(-1, 1, 1);
	glEnd();
	// �Ʒ���
	glBegin(GL_POLYGON);
		glColor3f(1, 1, 0);		
		glTexCoord2f(1, 1); glVertex3f(1, -1, 1);
		glTexCoord2f(1, 0); glVertex3f(1, -1, -1);
		glTexCoord2f(0, 0); glVertex3f(-1, -1, -1);
		glTexCoord2f(0, 1); glVertex3f(-1, -1, 1);
	glEnd();
	// ������
	glBegin(GL_POLYGON);
		glColor3f(1, 0, 1);		
		glTexCoord2f(1, 1); glVertex3f(1, 1, 1);
		glTexCoord2f(1, 0); glVertex3f(1, 1, -1);
		glTexCoord2f(0, 0); glVertex3f(1, -1, -1);
		glTexCoord2f(0, 1); glVertex3f(1, -1, 1);
	glEnd();
	// ������
	glBegin(GL_POLYGON);
		glColor3f(0, 1, 1);		
		glTexCoord2f(1, 1); glVertex3f(-1, 1, 1);
		glTexCoord2f(1, 0); glVertex3f(-1, 1, -1);
		glTexCoord2f(0, 0); glVertex3f(-1, -1, -1);
		glTexCoord2f(0, 1); glVertex3f(-1, -1, 1);
	glEnd();

	//glutWireTeapot(1.0);

	glutSwapBuffers();
}

//void MyDisplay()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);
//
//	// �ո�
//	glBegin(GL_POLYGON);
//	glColor3f(0, 0, 1);
//	glTexCoord2f(3, 3); glVertex3f(1, 1, 1);
//	glTexCoord2f(3, 0);    glVertex3f(1, -1, 1);
//	glTexCoord2f(0, 0); glVertex3f(-1, -1, 1);
//	glTexCoord2f(0, 3); glVertex3f(-1, 1, 1);
//	glEnd();
//	// �޸�
//	glBegin(GL_POLYGON);
//	glColor3f(1, 1, 0);
//	glTexCoord2f(1, 1); glVertex3f(1, 1, -1);
//	glTexCoord2f(1, 0); glVertex3f(1, -1, -1);
//	glTexCoord2f(0, 0); glVertex3f(-1, -1, -1);
//	glTexCoord2f(0, 1); glVertex3f(-1, 1, -1);
//	glEnd();
//	// ����
//	glBegin(GL_POLYGON);
//	glColor3f(1, 0, 1);
//	glTexCoord2f(1, 1); glVertex3f(1, 1, 1);
//	glTexCoord2f(1, 0); glVertex3f(1, 1, -1);
//	glTexCoord2f(0, 0); glVertex3f(-1, 1, -1);
//	glTexCoord2f(0, 1); glVertex3f(-1, 1, 1);
//	glEnd();
//	// �Ʒ���
//	glBegin(GL_POLYGON);
//	glColor3f(1, 0, 0);
//	glTexCoord2f(1, 1); glVertex3f(1, -1, 1);
//	glTexCoord2f(1, 0); glVertex3f(1, -1, -1);
//	glTexCoord2f(0, 0); glVertex3f(-1, -1, -1);
//	glTexCoord2f(0, 1); glVertex3f(-1, -1, 1);
//	glEnd();
//	// ������
//	glBegin(GL_POLYGON);
//	glColor3f(0, 1, 1);
//	glTexCoord2f(1, 1); glVertex3f(1, 1, 1);
//	glTexCoord2f(1, 0); glVertex3f(1, 1, -1);
//	glTexCoord2f(0, 0); glVertex3f(1, -1, -1);
//	glTexCoord2f(0, 1); glVertex3f(1, -1, 1);
//	glEnd();
//	// ������
//	glBegin(GL_POLYGON);
//	glColor3f(0, 1, 0);
//	glTexCoord2f(1, 1); glVertex3f(-1, 1, 1);
//	glTexCoord2f(1, 0); glVertex3f(-1, 1, -1);
//	glTexCoord2f(0, 0); glVertex3f(-1, -1, -1);
//	glTexCoord2f(0, 1); glVertex3f(-1, -1, 1);
//	glEnd();
//
//	glutSwapBuffers();
//}

void MyTimer(int Value)
{
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(zrot, 0.0f, 0.0f, 1.0f);

	glutPostRedisplay();

	glutTimerFunc(50, MyTimer, 1);
}

int LoadGLTextures(char* szFilePath)			//������ �ε��ϰ� �ؽ��ķ� ��ȯ	
{
	int Status = FALSE;

	glClearColor(0.0, 0.0, 0.0, 0.5);

	memset(pTextureImage, 0, sizeof(void *)* 1); 

	//��Ʈ���� �ε��ϰ� ����Ȯ��
	if (pTextureImage[0] = auxDIBImageLoad(szFilePath))
	{
		Status = TRUE;							//���� �÷��� True��

		glGenTextures(1, &MyTextureObject[0]);	//�ؽ��� ���� (1�� texture)
		glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);

		glTexImage2D(GL_TEXTURE_2D, 0, 3,
			pTextureImage[0]->sizeX, pTextureImage[0]->sizeY,
			1, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage[0]->data);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // Minimization Filter (GL_NEAREST / GL_LINEAR)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // Maximization Filter (GL_NEAREST / GL_LINEAR)

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// S Direction  
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);	// T Direction

		glEnable(GL_TEXTURE_2D);
	}

	if (pTextureImage[0]) {					//�ؽ��İ� �����ϸ�		
		if (pTextureImage[0]->data) {		//�ؽ��� ������ �����ϸ�		
			free(pTextureImage[0]->data);	//�ؽ��� ������� �ݳ�
		}
		free(pTextureImage[0]);				//�ؽ��� �ݳ�			
	}

	return Status;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutCreateWindow("OpenGL Example");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);

	glutDisplayFunc(MyDisplay);
	glutTimerFunc(500, MyTimer, 1);

	glEnable(GL_DEPTH_TEST);

	if(LoadGLTextures(fileName))
	{
		glutMainLoop();
	}
}

