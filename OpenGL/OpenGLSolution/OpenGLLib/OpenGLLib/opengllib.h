#ifndef OPENGLLIB_H
#define OPENGLLIB_H

#include <QGLWidget> 
#include "opengllib_global.h"

class OPENGLLIB_EXPORT COpenGLWidget :public QGLWidget
{
	Q_OBJECT
public:
	COpenGLWidget(QWidget *parant = NULL);
	~COpenGLWidget();
protected:
	virtual void initializeGL();
	virtual void resizeGL(int w, int h);
	virtual void paintGL();
};

#endif // OPENGLLIB_H
