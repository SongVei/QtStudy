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
    //状态栏添加组件
    fLabCurFile = new QLabel;
    fLabCurFile->setMinimumWidth(150);
    fLabCurFile->setText(QString::fromLocal8Bit("当前文件:"));
    ui->statusBar->addWidget(fLabCurFile); //添加到状态栏

    progressBar1 = new QProgressBar;
    progressBar1->setMaximumWidth(200);
    progressBar1->setMinimum(5);
    progressBar1->setMaximum(50);
    ui->statusBar->addWidget(progressBar1); //添加到状态栏

    //工具栏上添加组件
    spinFontSize = new QSpinBox;
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
//    spinFontSize->setValue(ui->txtEdit->font.pointSize()); 书上打的却不能用 疑惑ing
    spinFontSize->setMinimumWidth(50);

    ui->mainToolBar->addWidget(new QLabel(QString::fromLocal8Bit("字体大小")));
    ui->mainToolBar->addWidget(spinFontSize); //添加到工具栏

    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addWidget(new QLabel(QString::fromLocal8Bit(" 字体 ")));
    comboFont = new QFontComboBox;
    comboFont->setMinimumWidth(150);
    ui->mainToolBar->addWidget(comboFont); //添加到工具栏


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
    //更新cut, copy, paste
    ui->actCut->setEnabled(b);
    ui->actCopy->setEnabled(b);
    ui->actPaste->setEnabled(ui->txtEdit->canPaste());
}

void MainWindow::on_txtEdit_selectionChanged()
{
    //更新粗体，斜体，下划线3种action的checked属性
    QTextCharFormat fmt;
    fmt = ui->txtEdit->currentCharFormat();
    ui->actFontItalic->setChecked(fmt.fontItalic());
    ui->actFontBold->setChecked(fmt.font().bold());
    ui->actFontUnder->setChecked(fmt.fontUnderline());
}
