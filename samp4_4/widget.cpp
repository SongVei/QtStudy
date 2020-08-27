#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    this->setLayout(ui->horizontalLayout);
    QObject::connect(ui->SliderGreen,SIGNAL(valueChanged(int)),  //���� SliderGreen ��valueChanged()
                     this,SLOT(on_SliderRed_valueChanged(int)));

    QObject::connect(ui->SliderBlue,SIGNAL(valueChanged(int)), //���� SliderBlue��valueChanged()
                     this,SLOT(on_SliderRed_valueChanged(int)));

    QObject::connect(ui->SliderAlpha,SIGNAL(valueChanged(int)),  //���� SliderAlpha��valueChanged()
                     this,SLOT(on_SliderRed_valueChanged(int)));
//
    //
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_dial_valueChanged(int value)
{
    ui->LCDDisplay->display(value);
}

void Widget::on_radioBtnDec_clicked()
{//����LCD��ʾʮ������
    ui->LCDDisplay->setDigitCount(3);
    ui->LCDDisplay->setDecMode();

}

void Widget::on_radioBtnBin_clicked()
{ //����LCD��ʾ��������
    ui->LCDDisplay->setDigitCount(8);
    ui->LCDDisplay->setBinMode();
}

void Widget::on_radioBtnOct_clicked()
{ //����LCD��ʾ�˽�����
    ui->LCDDisplay->setDigitCount(4);
    ui->LCDDisplay->setOctMode();
}

void Widget::on_radioBtnHex_clicked()
{ //����LCD��ʾʮ��������
    ui->LCDDisplay->setDigitCount(3);
    ui->LCDDisplay->setHexMode();
}

void Widget::on_SliderH_valueChanged(int value)
{
    ui->progBarH->setValue(value); //
    ui->ScrollBarH->setValue(value);//
}

void Widget::on_SliderV_valueChanged(int value)
{
    ui->progBarV->setValue(value);
    ui->ScrollBarV->setValue(value);
    //    ui->progBarH->setValue(value);
}

void Widget::on_ScrollBarH_sliderMoved(int position)
{
    ui->progBarH->setValue(position);
}

void Widget::on_ScrollBarV_sliderMoved(int position)
{
    ui->progBarV->setValue(position);
}

void Widget::on_SliderRed_valueChanged(int value)
{   //�϶�Red��Green��Blue ��ɫ������ʱ����textEdit�ĵ�ɫ
    Q_UNUSED(value);
    QColor  color;
    int R=ui->SliderRed->value();  //��ȡSliderRed�ĵ�ǰֵ
    int G=ui->SliderGreen->value();//��ȡ SliderGreen �ĵ�ǰֵ
    int B=ui->SliderBlue->value();//��ȡ SliderBlue �ĵ�ǰֵ
    int alpha=ui->SliderAlpha->value();//��ȡ SliderAlpha �ĵ�ǰֵ
    color.setRgb(R,G,B,alpha); //ʹ��QColor��setRgb()���� �����ɫ

    QPalette pal=ui->textEdit->palette();//��ȡtextEditԭ�е� palette
    pal.setColor(QPalette::Base,color); //����palette�Ļ�ɫ��������ɫ��

    ui->textEdit->setPalette(pal);//����ΪtextEdit��palette,�ı�textEdit�ĵ�ɫ


}
