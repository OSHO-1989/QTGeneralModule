#include "CustomTitleBar.h"

// �������̶��߶�
const int TITLE_BAR_FIXED_HEIGHT = 30;

// ������ͼ��ߴ�
const int TITLE_ICON_WIDTH = 20;
const int TITLE_ICON_HEIGHT = 20;

// ���ڿ��ư�ť�ߴ�
const int SYSTEM_BUTTON_WIDTH = 27;
const int SYSTEM_BUTTON_HEIGHT = 22;


CustomTitleBar::CustomTitleBar(QWidget* parent) 
	: QWidget(parent),
	m_bLeftButtonPressed(false)
{
	setFixedHeight(TITLE_BAR_FIXED_HEIGHT);
	setWindowFlags(Qt::FramelessWindowHint);
	m_pIconLabel = new QLabel(this);
	m_pIconLabel->setFixedSize(TITLE_ICON_WIDTH, TITLE_ICON_HEIGHT);
	m_pIconLabel->setScaledContents(true);

	m_pTitleLabel = new QLabel(this);
	m_pTitleLabel->setAlignment(Qt::AlignLeft);
	m_pTitleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

	m_pMinimizeButton = new QPushButton(this);
	m_pMinimizeButton->setFixedSize(SYSTEM_BUTTON_WIDTH, SYSTEM_BUTTON_HEIGHT);
	m_pMinimizeButton->setObjectName("minimizeButton");

	m_pMaximizeButton = new QPushButton(this);
	m_pMaximizeButton->setFixedSize(SYSTEM_BUTTON_WIDTH, SYSTEM_BUTTON_HEIGHT);
	m_pMaximizeButton->setObjectName("maximizeButton");

	m_pCloseButton = new QPushButton(this);
	m_pCloseButton->setFixedSize(SYSTEM_BUTTON_WIDTH, SYSTEM_BUTTON_HEIGHT);
	m_pCloseButton->setObjectName("closeButton");

	QHBoxLayout* layout = new QHBoxLayout;
	layout->addWidget(m_pIconLabel);
	layout->addStretch(1);
	layout->addWidget(m_pTitleLabel);
	layout->addStretch(1);
	layout->addWidget(m_pMinimizeButton);
	layout->addWidget(m_pMaximizeButton);
	layout->addWidget(m_pCloseButton);
	setLayout(layout);

	setProperty("CustomTitleBar", true);
	setObjectName("CustomTitleBar");

	connect(m_pMinimizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
	connect(m_pMaximizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
	connect(m_pCloseButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
}

void CustomTitleBar::setWindowTitle(const QString& title)
{
	m_pTitleLabel->setText(title);
}

void CustomTitleBar::SetTitleBarIcon(const QString& iconPath)
{
	QPixmap map(iconPath);
	m_pIconLabel->setPixmap(map);
}

void CustomTitleBar::mouseDoubleClickEvent(QMouseEvent* event)
{
	m_pMaximizeButton->click();
}

void CustomTitleBar::mousePressEvent(QMouseEvent* event)
{
	// �����������¼�
	if (event->button() == Qt::LeftButton)
	{
		// ��¼������״̬
		m_bLeftButtonPressed = true;
		//��¼�������Ļ�е�λ��
		m_start = event->globalPos();
	}
}

void CustomTitleBar::mouseMoveEvent(QMouseEvent* event)
{
	// ������ס������Ӧ�¼�
	if (m_bLeftButtonPressed)
	{
		//���������ƶ���������ԭ����λ�ü�������ƶ���λ�ã�event->globalPos()-m_start
		parentWidget()->move(parentWidget()->geometry().topLeft() +
			event->globalPos() - m_start);
		//���������Ļ�е�λ���滻Ϊ�µ�λ��
		m_start = event->globalPos();
	}
}

void CustomTitleBar::mouseReleaseEvent(QMouseEvent* event)
{
	// �������ͷ�
	if (event->button() == Qt::LeftButton)
	{
		// ��¼���״̬
		m_bLeftButtonPressed = false;
	}
}

bool CustomTitleBar::eventFilter(QObject* obj, QEvent* event)
{
	switch (event->type())
	{
	case QEvent::WindowTitleChange: //���ñ���
	{
		QWidget* pWidget = qobject_cast<QWidget*>(obj);
		if (pWidget)
		{
			m_pTitleLabel->setText(pWidget->windowTitle());
			return true;
		}
	}
	case QEvent::WindowIconChange: //����ͼ��
	{
		QWidget* pWidget = qobject_cast<QWidget*>(obj);
		if (pWidget)
		{
			QIcon icon = pWidget->windowIcon();
			m_pIconLabel->setPixmap(icon.pixmap(m_pIconLabel->size()));
			return true;
		}
	}
	// ����״̬�仯�����ڴ�С�仯
	case QEvent::WindowStateChange:
	case QEvent::Resize:
		updateMaximize();
		return true;
	}
	return QWidget::eventFilter(obj, event);
}

void CustomTitleBar::updateMaximize()
{
	QWidget* pWindow = this->window();
	if (pWindow->isTopLevel())
	{
		bool bMaximize = pWindow->isMaximized();
		if (bMaximize)
		{
			m_pMaximizeButton->setToolTip(tr("Restore"));
			m_pMaximizeButton->setProperty("maximizeProperty", "restore");
		}
		else
		{
			m_pMaximizeButton->setProperty("maximizeProperty", "maximize");
			m_pMaximizeButton->setToolTip(tr("Maximize"));
		}

		m_pMaximizeButton->setStyle(QApplication::style());
	}
}

void CustomTitleBar::onClicked()
{
	QPushButton* pButton = qobject_cast<QPushButton*>(sender());
	QWidget* pWindow = this->window();
	if (pWindow->isTopLevel())
	{
		if (pButton == m_pMinimizeButton)
		{
			pWindow->showMinimized();
		}
		else if (pButton == m_pMaximizeButton)
		{
			pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();
		}
		else if (pButton == m_pCloseButton)
		{
			pWindow->close();
		}
	}
}
