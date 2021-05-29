#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FormMainWindow.h"

class FormMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    FormMainWindow(QWidget *parent = Q_NULLPTR);

public:
	void showWaitingForm();
	void hideWaitingForm();

protected:
	virtual void resizeEvent(QResizeEvent* event) override;

private:
    Ui::FormMainWindowClass ui;
    QWidget* m_pMaskLayer;
};
