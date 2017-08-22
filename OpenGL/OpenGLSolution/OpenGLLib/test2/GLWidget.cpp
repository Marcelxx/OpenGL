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
 * Brif  :OpenGL的坐标原点在屏幕的左下方。。。。。 
 * Para	 :GL_LINES，两个一组直线
 * Para  :GL_LINE_STRIP:依次将点连成线
 * Para  :GL_LINE_LOOP:依次将点连成线，将第一个点和最后一个点连起组成一个封闭曲线
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
 * Brif  :绘图是在修剪区上上进行绘制的，所以绘图的坐标是要看修剪区的定义的。
 * Para  :使用glMatrixMode(GL_PROJECTION);定义修剪区
 * Para  :如此例，glViewPort只是用来确定绘图的图显示在窗口的哪部分，和绘图没有关系。只和在设备上的最终显示有关系。
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
 * Brif  :绘制三角形，三角形的点的环绕方向要一直，即顺时针就一直顺时针，逆时针就一直逆时针。绘制多边形时，多边形默认会用当前的颜色进行填充。
 * Para  :默认绘制的多边形的图元是实心的。使用glPolygonMode(GL_BACK/GL_FRONT,GL_LINE/GL_FILL);设置成填充模式或者线框模式。
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
 * Brif  :设置边界点为false，表示该定点和下一个定点之间的连线不是边界线，即不绘制。
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