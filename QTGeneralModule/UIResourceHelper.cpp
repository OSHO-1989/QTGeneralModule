#include "UIResourceHelper.h"
#include <QApplication>
#include <QFontDatabase>
#include <QResource>
#include <QTranslator>
#include <QFile>
#include <QFont>


bool UIResourceHelper::setStyleSheet(const QString& filepath)
{
	//加载样式文件
	QFile qss(filepath);
	if (qss.open(QFile::ReadOnly))
	{
		QString stylesheet = QLatin1String(qss.readAll());
		qApp->setStyleSheet(stylesheet);
		qss.close();
		return true;
	}

	return false;
}

void UIResourceHelper::setLibraryPaths(const QStringList& filepath)
{
	QApplication::setLibraryPaths(filepath);
}

QStringList UIResourceHelper::addApplicationFont(const QString& fontPath)
{
	int fontId = QFontDatabase::addApplicationFont(fontPath);
	return QFontDatabase::applicationFontFamilies(fontId);
}

bool UIResourceHelper::registerResource(const QString& rccFileName)
{
	return QResource::registerResource(rccFileName);
}

bool UIResourceHelper::unregisterResource(const QString& rccFileName)
{
	return QResource::unregisterResource(rccFileName);
}

void UIResourceHelper::installTranslator(const QStringList& translatorFile)
{
	QStringList::const_iterator constIter;
	for (constIter = translatorFile.constBegin(); constIter != translatorFile.constEnd(); ++constIter)
	{
		QTranslator translator;
		// 各自load不同的qm文件（qm文件已添加到当前工程的资源中）
		translator.load(*constIter);
		// 分别安装翻译文件
		qApp->installTranslator(&translator);
	}
}
