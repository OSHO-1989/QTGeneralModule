#include "FormCustomTitleTest.h"

FormCustomTitleTest::FormCustomTitleTest(QWidget *parent)
	: QFrame(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);

	ui.CustomTitleWidget->setWindowTitle(u8"���������Դ���");
}	

FormCustomTitleTest::~FormCustomTitleTest()
{

}
