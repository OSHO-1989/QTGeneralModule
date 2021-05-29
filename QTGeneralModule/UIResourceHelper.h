#pragma once
#include <QString>
#include <QList>

class UIResourceHelper
{
public:

	/**
	* @brief 为应用程序设置QSS样式表
	* @param filepath，输入参数，QSS文件路径
	*/
	bool setStyleSheet(const QString& filepath);

	/**
	* @brief 为应用程序设置插件路径
	* @param libraryPath，输入参数，插件文件路径
	*/
	void setLibraryPaths(const QStringList& libraryPath);

	/**
	* @brief 为应用程序添加字体
	* @param fontPath，输入参数，字体文件路径
	*/
	QStringList addApplicationFont(const QString& fontPath);

	/**
	* @brief 为应用程序注册rcc资源文件
	* @param rccFileName，输入参数，rcc资源文件路径
	*/
	bool registerResource(const QString& rccFileName);

	/**
	* @brief 为应用程序反注册rcc资源文件
	* @param rccFileName，输入参数，rcc资源文件路径
	*/
	bool unregisterResource(const QString& rccFileName);

	/**
	* @brief 为应用程序加载翻译文件
	* @param translatorFile，输入参数，翻译文件列表(可将QT对话框对应的翻译合并加载)
	*/
	void installTranslator(const QStringList& translatorFile);
};
