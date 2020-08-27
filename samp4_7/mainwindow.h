#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include    <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    void    setActionsForButton();
    void    createSelectionPopMenu();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actListClear_triggered();  //清除项

    void on_actListIni_triggered(); //项初始化

    void on_chkBoxListEditable_clicked(bool checked);

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_actListInsert_triggered();

    void on_actListAppend_triggered();

    void on_actListDelete_triggered();

    void on_listWidget_customContextMenuRequested(const QPoint &pos);

    void on_toolBox_currentChanged(int index);

    void on_actSelALL_triggered();

    void on_actSelNone_triggered();

    void on_actSelInvs_triggered();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
