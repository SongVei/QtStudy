#include "widget.h"
#include "ui_widget.h"
#include <QTextBlock>
#include    <QMenu>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnIniItems_clicked()
{
    QIcon   icon;
    icon.addFile(":/image/icons/aim.ico");
    ui->comboBox->clear();
    for(int i=0;i<10;i++)
        ui->comboBox->addItem(icon,QString::asprintf("Item %d",i));
//    ui->comboBox_2->addItem(QString::asprintf("Itee %d",i));

        QStringList strList;
        strList<<"北京"<<"上海"<<"天津"<<"河北省"<<"山东省"<<"山西省";
        ui->comboBox->addItems(strList);
}

void Widget::on_btnIni2_clicked()
{
    QMap<QString , int>City_Zone;
    City_Zone.insert("北京",10);
    City_Zone.insert("上海",11);
    City_Zone.insert("天津",12);
    City_Zone.insert("重庆",13);
    City_Zone.insert("深圳",231);
    ui->comboBox2->clear();
    foreach(const QString &str,City_Zone.keys())
        ui->comboBox2->addItem(str,City_Zone.value(str));
}

void Widget::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->plainTextEdit->appendPlainText(arg1);
}

void Widget::on_comboBox2_currentIndexChanged(const QString &arg1)
{
    QString zone = ui->comboBox2->currentData().toString();
    ui->plainTextEdit->appendPlainText(arg1+":区号"+zone);
}

void Widget::on_btnToComboBox_clicked()
{//plainTextEdit 的内容逐行添加为 comboBox 的条目
    QTextDocument*  doc=ui->plainTextEdit->document(); //QPlainTextEdit 的内容保存在一个 QTextDocument 里
    int cnt=doc->blockCount();//QTextDocument分块保存内容，文本文件就是硬回车符是一个block,

    QIcon   icon(":/images/icons/aim.ico");

    ui->comboBox->clear();  //清除条目
    for (int i=0; i<cnt;i++) //扫描所有 blobk
    {
         QTextBlock textLine=doc->findBlockByNumber(i);//用blobk编号获取block，就是获取一行
         QString str=textLine.text(); //转换为文本
         QString x = doc->findBlockByNumber(i).text();
         ui->comboBox->addItem(icon,str); //添加一个条目到comboBox
    }
}

void Widget::on_pushButton_clicked()
{
     ui->plainTextEdit->clear();
}

void Widget::on_chkBoxReadonly_clicked(bool checked)
{
    ui->plainTextEdit->setReadOnly(checked);
}

void Widget::on_plainTextEdit_customContextMenuRequested(const QPoint &pos)
{
    QMenu* menu=ui->plainTextEdit->createStandardContextMenu(); //创建标准右键菜单
//    menu->exec(QCursor::pos());//在鼠标光标位置显示右键快捷菜单
    menu->exec(pos);//在鼠标光标位置显示右键快捷菜单
}

void Widget::on_btnClearItems_clicked()
{
    ui->comboBox->clear(); //清除条目
}

void Widget::on_chkBoxEditable_clicked(bool checked)
{
    ui->comboBox->setEditable(checked);
}
