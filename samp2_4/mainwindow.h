#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QSpinBox>
#include <QFontComboBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//private:
//    void iniSignalSlots();
private slots:
    void on_actFontBold_triggered(bool checked);

    void on_actFontItalic_triggered(bool checked);

    void on_actFontUnder_triggered(bool checked);

    void on_txtEdit_copyAvailable(bool b);

    void on_txtEdit_selectionChanged();

//    void on_spinBoxFontSize_valueChanged(int aFontSize);

//    void on_comboFont_currentIndexChanged(const QString &arg1);


private:
    Ui::MainWindow *ui;
    QLabel *fLabCurFile;
    QProgressBar *progressBar1;
    QSpinBox *spinFontSize;
    QFontComboBox *comboFont;

    void iniUI();
};



#endif // MAINWINDOW_H
