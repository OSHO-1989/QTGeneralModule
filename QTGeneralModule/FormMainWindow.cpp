#include "FormMainWindow.h"
#include "FormWaitingAnimation.h"


FormMainWindow::FormMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	m_pMaskLayer = new FormWaitingAnimation(this);
	m_pMaskLayer->setFixedSize(this->size());//设置窗口大小
	m_pMaskLayer->setVisible(false);//初始状态下隐藏，待需要显示时使用
	this->stackUnder(m_pMaskLayer);//其中pWrapper为当前窗口的QWidget
}

void FormMainWindow::resizeEvent(QResizeEvent* event)
{
	if (event) {}//消除警告提示

	if (m_pMaskLayer != nullptr)
	{
		m_pMaskLayer->setAutoFillBackground(true); //这个很重要，否则不会显示遮罩层
		QPalette pal = m_pMaskLayer->palette();
		pal.setColor(QPalette::Background, QColor(0x00, 0x00, 0x00, 0x20));
		m_pMaskLayer->setPalette(pal);
		m_pMaskLayer->setFixedSize(this->size());
	}
}
//显示
void FormMainWindow::showWaitingForm()
{
	if (m_pMaskLayer != nullptr)
	{
		m_pMaskLayer->setVisible(true);
	}
}
//隐藏
void FormMainWindow::hideWaitingForm()
{
	if (m_pMaskLayer != nullptr)
	{
		m_pMaskLayer->setVisible(false);
	}
}