#include "FormCustomTitleTest.h"
#include <QtWidgets/QApplication>
#include <QGuiApplication>
#include <QFile>
#include <QStyleHints>
#include <QDesktopWidget>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include "UIResourceHelper.h"


int main(int argc, char *argv[])
{
	//解决Qt在Retina屏幕上图片模糊问题
	QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication app(argc, argv);

	UIResourceHelper uiHelper;
	uiHelper.setStyleSheet(":/Application/Resources/Styles/ApplicationStyles.qss");

	FormCustomTitleTest w;
	if (!QGuiApplication::styleHints()->showIsFullScreen() && !QGuiApplication::styleHints()->showIsMaximized()) 
	{
		const QRect availableGeometry = QApplication::desktop()->availableGeometry(&w);
		w.resize(availableGeometry.width() / 2, availableGeometry.height() * 2 / 3);
		w.move((availableGeometry.width() - w.width()) / 2, (availableGeometry.height() - w.height()) / 2);
	}
	w.show();

    return app.exec();
}
