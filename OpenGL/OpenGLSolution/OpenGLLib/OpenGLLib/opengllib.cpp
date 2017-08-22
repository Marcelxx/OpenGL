#include "opengllib.h"
#include <GL\gl.h>

#pragma comment(lib,"E:\\work_xx\\OpenGL\\OpenGLSolution\\OpenGLLib\\OpenGLLib\\glut.lib")
#pragma comment(lib,"E:\\work_xx\\OpenGL\\OpenGLSolution\\OpenGLLib\\OpenGLLib\\glut32.lib")

COpenGLWidget::COpenGLWidget(QWidget *parant /*= NULL*/)
	:QGLWidget(parant)
{

}

COpenGLWidget::~COpenGLWidget()
{

}

void COpenGLWidget::initializeGL()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

void COpenGLWidget::resizeGL(int w, int h)
{
	glViewport(0, 0, w, h);

	//∂®“Â–ﬁºÙ«¯”Ú
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
	{
		glOrtho(0.0, 250.0, 0.0, 250.0f*h/w, 50.0, -50.0);
	}
	else
	{
		glOrtho(0.0, 250.0*w/h, 0.0, 250.0f, 50.0, -50.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void COpenGLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glRectf(100.0, 150.0, 150.0, 100.0);
	glFlush();
}
