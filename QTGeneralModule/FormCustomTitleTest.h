#pragma once

#include <QFrame>
#include "ui_FormCustomTitleTest.h"

class FormCustomTitleTest : public QFrame
{
	Q_OBJECT

public:
	FormCustomTitleTest(QWidget *parent = Q_NULLPTR);
	~FormCustomTitleTest();

private:
	Ui::FormCustomTitleTest ui;
};
