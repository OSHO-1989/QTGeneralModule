#include "FormMainWindow.h"
#include "FormWaitingAnimation.h"


FormMainWindow::FormMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	m_pMaskLayer = new FormWaitingAnimation(this);
	m_pMaskLayer->setFixedSize(this->size());//���ô��ڴ�С
	m_pMaskLayer->setVisible(false);//��ʼ״̬�����أ�����Ҫ��ʾʱʹ��
	this->stackUnder(m_pMaskLayer);//����pWrapperΪ��ǰ���ڵ�QWidget
}

void FormMainWindow::resizeEvent(QResizeEvent* event)
{
	if (event) {}//����������ʾ

	if (m_pMaskLayer != nullptr)
	{
		m_pMaskLayer->setAutoFillBackground(true); //�������Ҫ�����򲻻���ʾ���ֲ�
		QPalette pal = m_pMaskLayer->palette();
		pal.setColor(QPalette::Background, QColor(0x00, 0x00, 0x00, 0x20));
		m_pMaskLayer->setPalette(pal);
		m_pMaskLayer->setFixedSize(this->size());
	}
}
//��ʾ
void FormMainWindow::showWaitingForm()
{
	if (m_pMaskLayer != nullptr)
	{
		m_pMaskLayer->setVisible(true);
	}
}
//����
void FormMainWindow::hideWaitingForm()
{
	if (m_pMaskLayer != nullptr)
	{
		m_pMaskLayer->setVisible(false);
	}
}