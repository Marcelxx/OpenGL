#include "GLWidget.h"

#define GL_PI 3.1415f

CGLWidget::CGLWidget(QWidget *parent)
{
	ui.setupUi(this);
}

CGLWidget::~CGLWidget()
{

}


GLfloat xRot = 10;
GLfloat yRot = 10;




/*
 * Func  :
 * Brif  :OpenGL������ԭ������Ļ�����·����������� 
 * Para	 :GL_LINES������һ��ֱ��
 * Para  :GL_LINE_STRIP:���ν���������
 * Para  :GL_LINE_LOOP:���ν��������ߣ�����һ��������һ�����������һ���������
 * return:
*/
#if 0
void CGLWidget::paintGL()
{
	glColor3f(0.0, 1.0, 0.0);
	glPushMatrix();
	glBegin(GL_LINES);
	{
		glVertex3f(0, 0, 0);
		glVertex3f(50, 50, 0);
	}
	glEnd();


	glBegin(GL_LINE_STRIP);
	{
		glVertex3f(10, 10, 5);
		glVertex3f(14, 16, 0);
		glVertex3f(60, 35, 0);
		glVertex3f(73, 21, 0);
	}
	glEnd();

	glBegin(GL_LINE_LOOP);
	{
		glVertex3f(341, 14, 0);
		glVertex3f(131, 231, 0);
		glVertex3f(45, 91, 0);
		glVertex3f(142, 97, 0);
	}
	glEnd();

	glPopMatrix();
}
#endif
/*
 * Func  :
 * Brif  :��ͼ�����޼������Ͻ��л��Ƶģ����Ի�ͼ��������Ҫ���޼����Ķ���ġ�
 * Para  :ʹ��glMatrixMode(GL_PROJECTION);�����޼���
 * Para  :�������glViewPortֻ������ȷ����ͼ��ͼ��ʾ�ڴ��ڵ��Ĳ��֣��ͻ�ͼû�й�ϵ��ֻ�����豸�ϵ�������ʾ�й�ϵ��
 * return:
*/
#if 0
void CGLWidget::paintGL()
{
	glColor3f(0.0, 1.0, 0.0);

	GLfloat x, y, z, angle;

	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	if (width() <= height())
	{
		glTranslated(250 / 2, 250.0f*height() / width() / 2, 0);
	}
	else
	{
		glTranslated(250.0*width() / height() / 2, 250 / 2.0,0);
	}
	
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);

	glBegin(GL_POINTS);
	z = -50.f;
	for (angle = 0.0f; angle <= (2.0*GL_PI)*3.0f; angle += 0.1f)
	{
		x = 50.0f *sin(angle);
		y = 50.0f *cos(angle);

		glVertex3f(x, y, z);
		z += 0.5f;
	}
	glEnd();

	glPopMatrix();
	glFlush();
}
#endif


#if 0
/*
 * Func  :
 * Brif  :���������Σ������εĵ�Ļ��Ʒ���Ҫһֱ����˳ʱ���һֱ˳ʱ�룬��ʱ���һֱ��ʱ�롣���ƶ����ʱ�������Ĭ�ϻ��õ�ǰ����ɫ������䡣
 * Para  :Ĭ�ϻ��ƵĶ���ε�ͼԪ��ʵ�ĵġ�ʹ��glPolygonMode(GL_BACK/GL_FRONT,GL_LINE/GL_FILL);���ó����ģʽ�����߿�ģʽ��
 * return:
*/
void CGLWidget::paintGL()
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	{
		glVertex3f(50, 50, 0);
		glVertex3f(100, 100, 0);
		glVertex3f(100, 150, 0);
	}
	glEnd();
}
#endif



#if 1

/*
 * Func  :
 * Brif  :���ñ߽��Ϊfalse����ʾ�ö������һ������֮������߲��Ǳ߽��ߣ��������ơ�
 * Para  :
 * return:
*/
void CGLWidget::paintGL()
{
	glColor3f(1.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT, GL_LINE);
	glBegin(GL_TRIANGLES);
	{
		//1
		glEdgeFlag(true);
		glVertex3f(50, 50, 0);
		
		glVertex3f(100, 50, 0);
		glEdgeFlag(false);
		glVertex3f(50, 100, 0);

		//2
		glEdgeFlag(false);
		glVertex3f(50, 100, 0);
		glEdgeFlag(true);
		glVertex3f(100, 50, 0);
		
		glVertex3f(100, 100, 0);
	}
	glEnd();
}

#endif