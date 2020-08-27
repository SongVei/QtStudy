#include "qmywidget.h"
#include "ui_qmywidget.h"

QmyWidget::QmyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QmyWidget)
{
    ui->setupUi(this);
    boy = new Qperson("张三");
    boy->setProperty("score",95);
    boy->setProperty("age",15);
    boy->setProperty("sex","Boy");
    connect(boy,&Qperson::ageChanged,this,&QmyWidget::on_ageChanged);


    girl = new Qperson("李四");
    girl->setProperty("score",71);
    girl->setProperty("age",19);
    girl->setProperty("sex","Girl");
    connect(girl,&Qperson::ageChanged,this,&QmyWidget::on_ageChanged);
    ui->spinBoy->setProperty("isBoy",true);
    ui->spinGirl->setProperty("isBoy",false);

    connect(ui->spinGirl,SIGNAL(valueChange(int)),this,SLOT(on_spin_valueChanged(int)));
    connect(ui->spinBoy,SIGNAL(valueChange(int)),this,SLOT(on_spin_valueChanged(int)));

}

QmyWidget::~QmyWidget()
{
    delete ui;
}

void QmyWidget::on_ageChanged(int value)
{
    //响应信号
    Q_UNUSED(value);
    Qperson *aPerson = qobject_cast<Qperson *>(sender());
    QString hisName = aPerson->property("name").toString();
    QString  hisSex = aPerson->property("Sex").toString();
    int hisAge = aPerson->age();
//    int hisAge = aPerson->property("age").toInt();
    ui->textEdit->appendPlainText(hisName.toUtf8()+","+hisSex.toLocal8Bit()+QString::asprintf(",年龄=%d",hisAge));
}

void QmyWidget::on_btnBoyInc_clicked()
{

    boy->incAge();
}

void QmyWidget::on_btnGirlInc_clicked()
{
    girl->incAge();
//ui->spinGirl->setValue(girl->age());
}

void QmyWidget::on_btnClear_clicked()
{
ui->textEdit->clear();
}

void QmyWidget::on_btnClassInfo_clicked()
{
    //这里的类方法 在书上写的并不全。 固有bug
    //整个程序还有中文乱码的问题还待解决。
    //过过过
     /*
    const QMetaObject *meta = boy->metaObject();
    ui->textEdit->clear();
    ui->textEdit->appendPlainText("===元对象信息===");
    ui->textEdit->appendPlainText(QString("类名称: %1\n").arg(meta->className()));
    ui->textEdit->appendPlainText("property");
    for(int i = meta->propertyOffset();i < meta->propertyCount() ; i++){
        QMetaProperty prop = meta->proeprty(i);
        const char* proName = prop.name();
        QString propValue = boy->property(propName).toString();
        ui->textEdit->appendPlainText(QString("属性名称=%1，属性值=%2").arg(propName).toString);
    }

    ui->textEdit->appendPlainText(" ");
    ui->textEdit->appendPlainText("ClassInfo");
    for (int i = meta->classInfoOffset();i<meta->classInfoCount();++i)
    {
        QMetaClassInfo classInfo = meta->classInfo(i);
        ui->textEdit->appendPlainText(QString("Name=%1; Value=%2").arg(classInfo.name()).arg(classInfo.value()));
    }*/
}

void QmyWidget::on_spin_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    QSpinBox *spinBox = qobject_cast<QSpinBox *>(sender());
    if(spinBox->property("isBoy").toBool())
        boy->setAge(spinBox->value());
    else girl->setAge(spinBox->value());
}
