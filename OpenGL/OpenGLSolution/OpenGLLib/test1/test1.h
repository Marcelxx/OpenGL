#ifndef TEST1_H
#define TEST1_H

#include <QtWidgets/QWidget>
#include "../OpenGLLib/opengllib.h"

class test1 : public COpenGLWidget
{
	Q_OBJECT

public:
	test1(QWidget *parent = 0);
	~test1();

private:
};

#endif // TEST1_H
