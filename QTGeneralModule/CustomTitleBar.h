#pragma once

/**
 * @brief �������������
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
     * @brief ���ñ���������
     * @param title�����������õı���
     */
    void setWindowTitle(const QString& title);

    /**
     * @brief ���ñ�������ͼ��
     * @param iconPath��������ͼ���·��
     */
    void SetTitleBarIcon(const QString& iconPath);

protected:
    /**
     * @brief ���˫���¼�������
     * @param event���������¼�
     * @note ˫�����������н�������/��ԭ
     */
    virtual void mouseDoubleClickEvent(QMouseEvent* event) override;

    /**
     * @brief ��갴���¼�������
     * @param event���������¼�
     * @note ����������
     */
    virtual void mousePressEvent(QMouseEvent* event) override;
    /**
     * @brief ����ƶ��¼�������
     * @param event���������¼�
     * @note �ƶ����
     */
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    /**
     * @brief ����ͷ��¼�������
     * @param event���������¼�
     * @note �ͷ����
     */
    virtual void mouseReleaseEvent(QMouseEvent* event) override;

    /**
     * @brief �¼����˴�����
     * @param obj������
     * @param event���������¼�
     * @return �ɹ�����true��ʧ�ܷ���false
     * @note ���ñ��⡢ͼ��
     */
    virtual bool eventFilter(QObject* watched, QEvent* event) override;

    /**
     * @brief ���/��ԭ
     */
    void updateMaximize();

protected slots:
    /**
     * @brief ��С�������/��ԭ���رհ�ť���ʱ��Ӧ�Ĳۺ���
     */
    void onClicked();

private:
    QLabel* m_pIconLabel;
    QLabel* m_pTitleLabel;
    QPushButton* m_pMinimizeButton;
    QPushButton* m_pMaximizeButton;
    QPushButton* m_pCloseButton;
    QPoint m_start;//��ʼ��
    QPoint m_end;//������
    bool m_bLeftButtonPressed;//���������±��
};
