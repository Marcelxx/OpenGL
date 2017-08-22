#ifndef TEST2_H
#define TEST2_H

#include <QtWidgets/QWidget>
#include "ui_test2.h"
#include "../OpenGLLib/opengllib.h"

class CGLWidget : public COpenGLWidget
{
	Q_OBJECT

public:
	CGLWidget(QWidget *parent = 0);
	~CGLWidget();
protected:
	virtual void paintGL();
private:
	Ui::test2Class ui;
};

#endif // TEST2_H
