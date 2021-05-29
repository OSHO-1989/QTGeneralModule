#include "FormWaitingAnimation.h"
#include <QMovie>
#include <QLabel>
#include <QVBoxLayout>


FormWaitingAnimation::FormWaitingAnimation(QWidget *parent)
	: QWidget(parent),
	m_pMovieLabel(nullptr)
{
	setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	setStyleSheet("background-color: transparent;");

	QVBoxLayout* pMainLayout = new QVBoxLayout(this);
	m_pMovieLabel = new QLabel(this);
	pMainLayout->addWidget(m_pMovieLabel);
	setLayout(pMainLayout);

	QMovie* movie = new QMovie("");
	m_pMovieLabel->setMovie(movie);
}

FormWaitingAnimation::~FormWaitingAnimation()
{
}
