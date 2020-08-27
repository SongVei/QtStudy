#include "qwdlgmanual.h"

QWDlgManual::QWDlgManual(QWidget *parent)
    : QDialog(parent)
{
    iniUI();
    iniSignalSlots();
    setWindowTitle("Form created manualy");
}

QWDlgManual::~QWDlgManual()
{

}
void QWDlgManual::on_chkBoxUnder_clicked(bool checked)
{
    QFont font = txtEdit ->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::on_chkBoxItalic_clicked(bool checked)
{
    QFont font = txtEdit ->font();
    font.setItalic(checked);
    txtEdit->setFont(font);

}

void QWDlgManual::on_chkBoxBold_clicked(bool checked)
{
    QFont font = txtEdit ->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::setTextColor()
{
    QPalette plet = txtEdit->palette();
    if(rBtnBlue->isChecked())
        plet.setColor(QPalette::Text,Qt::blue);
    else if(rBtnRed->isChecked())
        plet.setColor(QPalette::Text,Qt::red);
    else if(rBtnBlack->isChecked())
        plet.setColor(QPalette::Text,Qt::black);
    else
        plet.setColor(QPalette::Text,Qt::black);
    txtEdit->setPalette(plet);
}

void QWDlgManual::iniUI()
{
    //
    chkBoxUnder = new QCheckBox(tr("Underline"));
    chkBoxItalic = new QCheckBox(tr("Italic"));
    chkBoxBold = new QCheckBox(tr("Bold"));

    QHBoxLayout *HLay1 = new QHBoxLayout;
    HLay1->addWidget(chkBoxUnder);
    HLay1->addWidget(chkBoxItalic);
    HLay1->addWidget(chkBoxBold);

    //
    rBtnBlack = new QRadioButton(tr("Black"));
    rBtnBlue = new QRadioButton(tr("Blue"));
    rBtnRed = new QRadioButton(tr("Red"));
    rBtnBlack ->setChecked(true);

    QHBoxLayout *HLay2 = new QHBoxLayout;
    HLay2->addWidget(rBtnBlack);
    HLay2->addWidget(rBtnBlue);
    HLay2->addWidget(rBtnRed);

    //
    btnOK = new QPushButton(QString::fromLocal8Bit("确定"));
    btnCancel = new QPushButton(QString::fromLocal8Bit("取消"));
    btnClose = new QPushButton(QString::fromLocal8Bit("退出"));

    QHBoxLayout *HLay3 = new QHBoxLayout;
    HLay3->addStretch();
    HLay3->addWidget(btnOK);
    HLay3->addWidget(btnCancel);
    HLay3->addStretch();
    HLay3->addWidget(btnClose);

    //
    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("Hello World \n\nIt is my demo");
    QFont font = txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);

    //
    QVBoxLayout *VLay = new QVBoxLayout;
    VLay->addLayout(HLay1);
    VLay->addLayout(HLay2);
    VLay->addWidget(txtEdit);
    VLay->addLayout(HLay3);
    setLayout(VLay);
}

void QWDlgManual::iniSignalSlots()
{
    connect(rBtnBlue,SIGNAL(clicked()),this,SLOT(setTextColor()));
    connect(rBtnRed,SIGNAL(clicked()),this,SLOT(setTextColor()));
    connect(rBtnBlack,SIGNAL(clicked()),this,SLOT(setTextColor()));

    connect(chkBoxUnder,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxUnder_clicked(bool)));
    connect(chkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxItalic_clicked(bool)));
    connect(chkBoxBold,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxBold_clicked(bool)));

    connect(btnOK,SIGNAL(clicked()),this ,SLOT(accept()));
    connect(btnCancel,SIGNAL(clicked()),this ,SLOT(reject()));
    connect(btnClose,SIGNAL(clicked()),this ,SLOT(close()));


}

