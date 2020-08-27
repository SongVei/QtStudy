#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*下面这些属性都可以直接在ui设计界面设计*/
    ui->spbTotal->setPrefix("$");
    ui->spbPrice->setPrefix("$");
    ui->spbDec->setPrefix("Dec   ");
    ui->spbHex->setPrefix("Hex   ");
    ui->spbBin->setPrefix("Bin   ");
    ui->spbBin->setMaximum(255);
    ui->spbDec->setMaximum(255);
    ui->spbHex->setMaximum(255);
    ui->spbBin->setDisplayIntegerBase(2);
    ui->spbHex->setDisplayIntegerBase(16);

    //asdasdasdad关联三个函数
    QObject::connect(ui->GreenSd,SIGNAL(valueChanged(int)),this,SLOT(on_redSd_valueChanged(int)));
    QObject::connect(ui->BlueSd,SIGNAL(valueChanged(int)),this,SLOT(on_redSd_valueChanged(int)));
    QObject::connect(ui->redSd,SIGNAL(valueChanged(int)),this,SLOT(on_redSd_valueChanged(int)));
    MainWindow::initUI();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initUI()
{
    ui->redSd->setMinimum(0);
    ui->redSd->setMaximum(255);
    ui->GreenSd->setMinimum(0);
    ui->GreenSd->setMaximum(255);
    ui->BlueSd->setMinimum(0);
    ui->BlueSd->setMaximum(255);
    ui->HorSd->setTickPosition(QSlider::TicksAbove);
}

void MainWindow::on_BtnCal_clicked()
{
    QString str = ui->editNum->text();
    int num = str.toInt();
    str = ui->editPrice->text();
    double price = str.toDouble();
    double total = num * price ;
    str = str.sprintf("%.2lf",total);
    ui->editTotal->setText(str);

}

void MainWindow::on_btnDec_clicked()
{
    QString str = ui->DecimalEdit->text();
    int val = str.toInt();
    str = str.setNum(val,16);
//    str = QString :: number(val,16);
    str =str.toUpper();
    ui->HexadecimalEdit->setText(str);

    str = str.setNum(val,2);
//    str = QString::number(val,2);
    ui->BinaryEdit->setText(str);

}

void MainWindow::on_btnHex_clicked()
{
    QString str = ui->HexadecimalEdit->text();
    bool ok;
    int val = str.toInt(&ok,16);
    str = QString::number(val);
    ui->DecimalEdit->setText(str);

    str = str.setNum(val,2);
    ui->BinaryEdit->setText(str);
}

void MainWindow::on_btnBin_clicked()
{
    QString str = ui->BinaryEdit->text();
    bool ok;
    int val = str.toInt(&ok,2);
    str = QString::number(val);
    ui->DecimalEdit->setText(str);

    str = str.setNum(val,16);
    str = str.toUpper();
    ui->HexadecimalEdit->setText(str);
}

void MainWindow::on_btnAppend_clicked()
{
    QString str1 = ui->str1_text->currentText();
    QString str2 = ui->str_text->text();
    str1 = str1.append(str2);
    ui->resultText->setText(str1);
}

void MainWindow::on_btnPrepend_clicked()
{
    QString str1 = ui->str1_text->currentText();
    QString str2 = ui->str_text->text();
    str1 = str1.prepend(str2);
    ui->resultText->setText(str1);
}

void MainWindow::on_btnToUpper_clicked()
{
    QString str1 = ui->resultText->text();
    str1 = str1.toUpper();
    ui->resultText->setText(str1);
}

void MainWindow::on_btnToLower_clicked()
{
    QString str1 = ui->resultText->text();
    str1 = str1.toLower();
    ui->resultText->setText(str1);
}

void MainWindow::on_btnCount_clicked()
{
    QString str = ui->resultText->text();
    int N = str.count();
    ui->spinBox->setValue(N);
}

void MainWindow::on_btnSize_clicked()
{
    QString str = ui->resultText->text();
    int N = str.size();
    ui->spinBox->setValue(N);
}

void MainWindow::on_btnTrimmed_clicked()
{
    QString str = ui->resultText->text();
    str = str.trimmed();
    ui->resultText->setText(str);
}

void MainWindow::on_btnSimpli_clicked()
{
    QString str = ui->resultText->text();
    str = str.simplified();
    ui->resultText->setText(str);
}

void MainWindow::on_btnIndex_clicked()
{
    QString str = ui->resultText->text();
    QString fnd = ui->str_text->text();
    int N = str.indexOf(fnd);
    ui->spinBox->setValue(N);
}

void MainWindow::on_btnLastIndexOf_clicked()
{
    QString str = ui->resultText->text();
    QString fnd = ui->str_text->text();
    int N = str.lastIndexOf(fnd);
    ui->spinBox->setValue(N);
}

void MainWindow::on_btnIsNull_clicked()
{
    QString str = ui->str_text->text();
    bool N = str.isNull();
    QString strx = N ? "true" : "false" ;
    ui->resultText->setText(strx);
}

void MainWindow::on_btnIsEmpty_clicked()
{
    QString str = ui->str_text->text();
    bool N = str.isEmpty();
    QString strx = N ? "true" : "false" ;
    ui->resultText->setText(strx);
}

void MainWindow::on_btnContains_clicked()
{
    QString str1 = ui->str1_text->currentText();
    QString str2 = ui->str_text->text();
    bool N ;
    if (ui->radioButton->isChecked())
    {
        N = str1.contains(str2,Qt::CaseInsensitive);//不区分大小写
    }
    else N = str1.contains(str2,Qt::CaseSensitive); //区分大小写
    QString strx = N ? "true" : "false" ;
    ui->resultText->setText(strx);
}


void MainWindow::on_BtnCal_7_clicked()
{
    int num = ui->spbNum->value();
    double price = ui->spbPrice->value();
    double total = num*price;
    ui->spbTotal->setValue(total);
    ui->spbTotal->setPrefix("$");
}

void MainWindow::on_btnBin_7_clicked()
{
    int val = ui->spbBin->value();
    ui->spbDec->setValue(val);
    ui->spbHex->setValue(val);
}

void MainWindow::on_btnDec_7_clicked()
{
    int val = ui->spbDec->value();
    ui->spbBin->setValue(val);
    ui->spbHex->setValue(val);
}

void MainWindow::on_Btn_22_clicked()
{
    int val = ui->spbHex->value();
    ui->spbBin->setValue(val);
    ui->spbDec->setValue(val);
}

void MainWindow::on_redSd_valueChanged(int value)
{
    Q_UNUSED(value);
    QColor color;

    int R=ui->redSd->value();  //读取SliderRed的当前值
    int G=ui->GreenSd->value();//读取 SliderGreen 的当前值
    int B=ui->BlueSd->value();//读取 SliderBlue 的当前值
    int alpha=ui->AlpheSd->value();//读取 SliderAlpha 的当前值
    color.setRgb(R,G,B,alpha); //使用QColor的setRgb()函数 获得颜色

    QPalette pal=ui->textColorx->palette();//获取textEdit原有的 palette
    pal.setColor(QPalette::Base,color); //设置palette的基色（即背景色）

    ui->textColorx->setPalette(pal);//设置为textEdit的palette,改变textEdit的底色


}

void MainWindow::on_HorSd_valueChanged(int value)
{
    Q_UNUSED(value);
    int val = ui->HorSd->value();
    ui->progressBar->setValue(val);
}

void MainWindow::on_dial_valueChanged(int value)
{
    //设置LCD的显示值等于Dial的值
    ui->lcdNumber->display(value);
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->lcdNumber->setDigitCount(3);
    ui->lcdNumber->setDecMode();
}

void MainWindow::on_radioButton_3_clicked()
{
    ui->lcdNumber->setDigitCount(8);
    ui->lcdNumber->setBinMode();
}

void MainWindow::on_radioButton_5_clicked()
{
    ui->lcdNumber->setDigitCount(4);
    ui->lcdNumber->setOctMode();
}

void MainWindow::on_radioButton_4_clicked()
{
    ui->lcdNumber->setDigitCount(3);
    ui->lcdNumber->setHexMode();
}

void MainWindow::on_VerSd_valueChanged(int value)
{
    ui->progressBar_2->setValue(value);
    ui->VerSd->setValue(value);
}
