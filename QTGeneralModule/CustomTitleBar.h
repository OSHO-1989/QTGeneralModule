#pragma once

/**
 * @brief 标题栏界面基类
 * @author
 */

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QApplication>
#include <QEvent>
#include <QMouseEvent>
#include <QPoint>
#include <QPixmap>
#include <QString>


class CustomTitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit CustomTitleBar(QWidget* parent = nullptr);

    /**
     * @brief 设置标题栏标题
     * @param title，参数，设置的标题
     */
    void setWindowTitle(const QString& title);

    /**
     * @brief 设置标题栏的图标
     * @param iconPath，参数，图标的路径
     */
    void SetTitleBarIcon(const QString& iconPath);

protected:
    /**
     * @brief 鼠标双击事件处理函数
     * @param event，参数，事件
     * @note 双击标题栏进行界面的最大化/还原
     */
    virtual void mouseDoubleClickEvent(QMouseEvent* event) override;

    /**
     * @brief 鼠标按下事件处理函数
     * @param event，参数，事件
     * @note 按下鼠标左键
     */
    virtual void mousePressEvent(QMouseEvent* event) override;
    /**
     * @brief 鼠标移动事件处理函数
     * @param event，参数，事件
     * @note 移动鼠标
     */
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    /**
     * @brief 鼠标释放事件处理函数
     * @param event，参数，事件
     * @note 释放鼠标
     */
    virtual void mouseReleaseEvent(QMouseEvent* event) override;

    /**
     * @brief 事件过滤处理器
     * @param obj，参数
     * @param event，参数，事件
     * @return 成功返回true，失败返回false
     * @note 设置标题、图标
     */
    virtual bool eventFilter(QObject* watched, QEvent* event) override;

    /**
     * @brief 最大化/还原
     */
    void updateMaximize();

protected slots:
    /**
     * @brief 最小化、最大化/还原、关闭按钮点击时响应的槽函数
     */
    void onClicked();

private:
    QLabel* m_pIconLabel;
    QLabel* m_pTitleLabel;
    QPushButton* m_pMinimizeButton;
    QPushButton* m_pMaximizeButton;
    QPushButton* m_pCloseButton;
    QPoint m_start;//起始点
    QPoint m_end;//结束点
    bool m_bLeftButtonPressed;//鼠标左键按下标记
};
