#include "qmywidget.h"
#include "ui_qmywidget.h"

QmyWidget::QmyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QmyWidget)
{
    ui->setupUi(this);
    boy = new Qperson("����");
    boy->setProperty("score",95);
    boy->setProperty("age",15);
    boy->setProperty("sex","Boy");
    connect(boy,&Qperson::ageChanged,this,&QmyWidget::on_ageChanged);


    girl = new Qperson("����");
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
    //��Ӧ�ź�
    Q_UNUSED(value);
    Qperson *aPerson = qobject_cast<Qperson *>(sender());
    QString hisName = aPerson->property("name").toString();
    QString  hisSex = aPerson->property("Sex").toString();
    int hisAge = aPerson->age();
//    int hisAge = aPerson->property("age").toInt();
    ui->textEdit->appendPlainText(hisName.toUtf8()+","+hisSex.toLocal8Bit()+QString::asprintf(",����=%d",hisAge));
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
    //������෽�� ������д�Ĳ���ȫ�� ����bug
    //����������������������⻹�������
    //������
     /*
    const QMetaObject *meta = boy->metaObject();
    ui->textEdit->clear();
    ui->textEdit->appendPlainText("===Ԫ������Ϣ===");
    ui->textEdit->appendPlainText(QString("������: %1\n").arg(meta->className()));
    ui->textEdit->appendPlainText("property");
    for(int i = meta->propertyOffset();i < meta->propertyCount() ; i++){
        QMetaProperty prop = meta->proeprty(i);
        const char* proName = prop.name();
        QString propValue = boy->property(propName).toString();
        ui->textEdit->appendPlainText(QString("��������=%1������ֵ=%2").arg(propName).toString);
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
