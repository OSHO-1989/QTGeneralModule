#pragma once
#include <QString>
#include <QList>

class UIResourceHelper
{
public:

	/**
	* @brief ΪӦ�ó�������QSS��ʽ��
	* @param filepath�����������QSS�ļ�·��
	*/
	bool setStyleSheet(const QString& filepath);

	/**
	* @brief ΪӦ�ó������ò��·��
	* @param libraryPath���������������ļ�·��
	*/
	void setLibraryPaths(const QStringList& libraryPath);

	/**
	* @brief ΪӦ�ó����������
	* @param fontPath����������������ļ�·��
	*/
	QStringList addApplicationFont(const QString& fontPath);

	/**
	* @brief ΪӦ�ó���ע��rcc��Դ�ļ�
	* @param rccFileName�����������rcc��Դ�ļ�·��
	*/
	bool registerResource(const QString& rccFileName);

	/**
	* @brief ΪӦ�ó���ע��rcc��Դ�ļ�
	* @param rccFileName�����������rcc��Դ�ļ�·��
	*/
	bool unregisterResource(const QString& rccFileName);

	/**
	* @brief ΪӦ�ó�����ط����ļ�
	* @param translatorFile����������������ļ��б�(�ɽ�QT�Ի����Ӧ�ķ���ϲ�����)
	*/
	void installTranslator(const QStringList& translatorFile);
};
