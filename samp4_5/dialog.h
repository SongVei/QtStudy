#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include    <QTimer>
#include    <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT
private:
    QTimer *fTimer;  //��ʱ��

    QTime   fTimeCounter;//��ʱ��

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

private slots:
    void on_timer_timeout(); //��ʱ���жϴ���ۺ���,�ֹ�����


    void on_btnGetTime_clicked();
    void on_calendarWidget_selectionChanged();
    void on_btnSetTime_clicked();
    void on_btnSetDate_clicked();
    void on_btnSetDateTime_clicked();
    void on_btnSetIntv_clicked();
    void on_btnStart_clicked();
    void on_btnStop_clicked();
};
#endif // DIALOG_H
