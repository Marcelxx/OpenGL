
#include <QtWidgets/QApplication>
#include "GLWidget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CGLWidget w;
	w.show();
	return a.exec();
}
