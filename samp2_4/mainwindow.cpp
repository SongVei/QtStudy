#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iniUI();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::iniUI()
{
    //״̬��������
    fLabCurFile = new QLabel;
    fLabCurFile->setMinimumWidth(150);
    fLabCurFile->setText(QString::fromLocal8Bit("��ǰ�ļ�:"));
    ui->statusBar->addWidget(fLabCurFile); //��ӵ�״̬��

    progressBar1 = new QProgressBar;
    progressBar1->setMaximumWidth(200);
    progressBar1->setMinimum(5);
    progressBar1->setMaximum(50);
    ui->statusBar->addWidget(progressBar1); //��ӵ�״̬��

    //��������������
    spinFontSize = new QSpinBox;
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
//    spinFontSize->setValue(ui->txtEdit->font.pointSize()); ���ϴ��ȴ������ �ɻ�ing
    spinFontSize->setMinimumWidth(50);

    ui->mainToolBar->addWidget(new QLabel(QString::fromLocal8Bit("�����С")));
    ui->mainToolBar->addWidget(spinFontSize); //��ӵ�������

    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addWidget(new QLabel(QString::fromLocal8Bit(" ���� ")));
    comboFont = new QFontComboBox;
    comboFont->setMinimumWidth(150);
    ui->mainToolBar->addWidget(comboFont); //��ӵ�������


    setCentralWidget(ui->txtEdit);
}

void MainWindow::on_actFontBold_triggered(bool checked)
{
    QTextCharFormat fmt ;
    fmt =ui->txtEdit->currentCharFormat();
    if(checked)
    {
        fmt.setFontWeight(QFont::Bold);
    }
    else {
        fmt.setFontWeight(QFont::Normal);
    }
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actFontItalic_triggered(bool checked)
{
    QTextCharFormat fmt ;
    fmt =ui->txtEdit->currentCharFormat();
    if(checked)
    {
        fmt.setFontItalic(true);
    }
    else {
        fmt.setFontItalic(false);
    }
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actFontUnder_triggered(bool checked)
{
    QTextCharFormat fmt ;
    fmt =ui->txtEdit->currentCharFormat();
    if(checked)
    {
        fmt.setFontUnderline(true);
    }
    else {
        fmt.setFontUnderline(false);
    }
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_txtEdit_copyAvailable(bool b)
{
    //����cut, copy, paste
    ui->actCut->setEnabled(b);
    ui->actCopy->setEnabled(b);
    ui->actPaste->setEnabled(ui->txtEdit->canPaste());
}

void MainWindow::on_txtEdit_selectionChanged()
{
    //���´��壬б�壬�»���3��action��checked����
    QTextCharFormat fmt;
    fmt = ui->txtEdit->currentCharFormat();
    ui->actFontItalic->setChecked(fmt.fontItalic());
    ui->actFontBold->setChecked(fmt.font().bold());
    ui->actFontUnder->setChecked(fmt.fontUnderline());
}
