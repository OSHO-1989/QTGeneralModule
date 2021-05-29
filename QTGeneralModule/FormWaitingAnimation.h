#pragma once

#include <QWidget>


class QLabel;

class FormWaitingAnimation : public QWidget
{
	Q_OBJECT

public:
	FormWaitingAnimation(QWidget *parent = nullptr);
	~FormWaitingAnimation();

private:
	QLabel* m_pMovieLabel;
};
