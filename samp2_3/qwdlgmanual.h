#ifndef QWDLGMANUAL_H
#define QWDLGMANUAL_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QHBoxLayout>

class QWDlgManual : public QDialog
{
    Q_OBJECT
private:
    QCheckBox *chkBoxUnder;
    QCheckBox *chkBoxItalic;
    QCheckBox *chkBoxBold;
    QRadioButton *rBtnBlack;
    QRadioButton *rBtnBlue;
    QRadioButton *rBtnRed;
    QPlainTextEdit *txtEdit;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QPushButton *btnClose;

    void iniUI();
    void iniSignalSlots();

private slots:
    void on_chkBoxUnder_clicked(bool checked);
    void on_chkBoxItalic_clicked(bool checked);
    void on_chkBoxBold_clicked(bool checked);
    void setTextColor();

public:
    QWDlgManual(QWidget *parent = 0);
    ~QWDlgManual();
};

#endif // QWDLGMANUAL_H
