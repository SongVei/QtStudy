#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initUI();

private slots:
    void on_BtnCal_clicked();

    void on_btnDec_clicked();

    void on_btnHex_clicked();

    void on_btnBin_clicked();

    void on_btnAppend_clicked();

    void on_btnPrepend_clicked();

    void on_btnToUpper_clicked();

    void on_btnToLower_clicked();

    void on_btnCount_clicked();

    void on_btnSize_clicked();

    void on_btnTrimmed_clicked();

    void on_btnSimpli_clicked();

    void on_btnIndex_clicked();

    void on_btnLastIndexOf_clicked();

    void on_btnIsNull_clicked();

    void on_btnIsEmpty_clicked();

    void on_btnContains_clicked();


    void on_BtnCal_7_clicked();

    void on_btnBin_7_clicked();

    void on_btnDec_7_clicked();

    void on_Btn_22_clicked();

    void on_redSd_valueChanged(int value);

    void on_HorSd_valueChanged(int value);

    void on_dial_valueChanged(int value);

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_4_clicked();

    void on_VerSd_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
