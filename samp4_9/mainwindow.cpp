#include "mainwindow.h"
#include "ui_mainwindow.h"
#include    <QDate>

void MainWindow::createItemsARow(int rowNo,QString Name,QString Sex,QDate birth,QString Nation,bool isPM,int score)
{ //为一行的单元格创建 Items
    QTableWidgetItem    *item;
    QString str;
    uint StudID=202008000; //学号基数

//姓名
    //新建一个Item，设置单元格type为自定义的MainWindow::ctName
    item=new  QTableWidgetItem(Name,MainWindow::ctName);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter); //文本对齐格式
    StudID  +=rowNo; //学号=基数+ 行号
    item->setData(Qt::UserRole,QVariant(StudID));  //设置studID为data
    ui->tableInfo->setItem(rowNo,MainWindow::colName,item); //为单元格设置Item

//性别
    QIcon   icon;
    if (Sex=="男")
        icon.addFile(":/images/icons/boy.ico");
    else
        icon.addFile(":/images/icons/girl.ico");
    item=new  QTableWidgetItem(Sex,MainWindow::ctSex); //新建一个Item，设置单元格type为自定义的 MainWindow::ctSex
    item->setIcon(icon);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//为单元格设置Item
    ui->tableInfo->setItem(rowNo,MainWindow::colSex,item);//为单元格设置Item

//出生日期
    str=birth.toString("yyyy-MM-dd"); //日期转换为字符串
    item=new  QTableWidgetItem(str,MainWindow::ctBirth);//新建一个Item，设置单元格type为自定义的 MainWindow::ctBirth
    item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter); //文本对齐格式
    ui->tableInfo->setItem(rowNo,MainWindow::colBirth,item);//为单元格设置Item

//民族
    item=new  QTableWidgetItem(Nation,MainWindow::ctNation); //新建一个Item，设置单元格type为自定义的 MainWindow::ctNation
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//文本对齐格式
    ui->tableInfo->setItem(rowNo,MainWindow::colNation,item);//为单元格设置Item

//是否党员
    item=new  QTableWidgetItem("党员",MainWindow::ctPartyM);//新建一个Item，设置单元格type为自定义的 MainWindow::ctPartyM
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//文本对齐格式
    if (isPM)
        item->setCheckState(Qt::Checked);
    else
        item->setCheckState(Qt::Unchecked);
    item->setBackgroundColor(Qt::yellow);//Qt::green  lightGray  yellow
    ui->tableInfo->setItem(rowNo,MainWindow::colPartyM,item);//为单元格设置Item

//分数
    str.setNum(score);
    item=new  QTableWidgetItem(str,MainWindow::ctScore);//新建一个Item，设置单元格type为自定义的 MainWindow::ctPartyM
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//文本对齐格式
    ui->tableInfo->setItem(rowNo,MainWindow::colScore,item);//为单元格设置Item
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->splitterMain);

    labCellIndex = new QLabel("当前单元格坐标",this);
    labCellIndex ->setMinimumWidth(250);
    labCellType = new QLabel("当前单元格类型",this);
    labCellType ->setMinimumWidth(200);
    labStudID = new QLabel("学生ID:",this);
    labStudID ->setMinimumWidth(200);
    ui->statusbar->addWidget(labStudID);
    ui->statusbar->addWidget(labCellIndex);
    ui->statusbar->addWidget(labCellType);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnSetHeader_clicked()
{
    QTableWidgetItem *headerItem;
    QStringList headerText;

    headerText<<"姓名"<<"性别"<<"出生日期"<<"民族"<<"分数"<<"是否党员";
    ui->tableInfo->setColumnCount(headerText.count());
//    ui->tableInfo->setHorizontalHeaderLabels(headerText);

    for(int i=0;i<ui->tableInfo->columnCount();i++)
    {
        headerItem = new QTableWidgetItem(headerText.at(i));
        QFont font = headerItem ->font();
        font.setBold(true);
        font.setPointSize(12);
        headerItem->setTextColor(Qt::red);
        headerItem->setFont(font);
        ui->tableInfo->setHorizontalHeaderItem(i,headerItem);
    }

//    ui->tableInfo->setItemDelegateForColumn()
}

void MainWindow::on_btnIniData_clicked()
{
    QString strName,strSex;
    bool isParty = false;
    QDate birth;
    birth.setDate(1999,4,2);
    ui->tableInfo->clearContents();
    int Rows = ui->tableInfo->rowCount();
    for(int i=0;i<Rows;i++)
    {
        strName = QString::asprintf("学生%d",i);
        if((i%2))strSex="女";
        else strSex="男";

        createItemsARow(i,strName,strSex,birth,"汉族",isParty,70);
//        createItemsARow(i, strName, strSex, birth,"汉族",isParty,70); //为某一行创建items

        birth = birth.addDays(20);
        isParty = !isParty;
    }
}

void MainWindow::on_btnSetRows_clicked()
{
    ui->tableInfo->setRowCount(ui->spinRowCount->value());
    ui->tableInfo->setAlternatingRowColors(ui->chkBoxRowColor);
}


void MainWindow::on_chkBoxTabEditable_clicked(bool checked)
{
    if(checked)
        ui->tableInfo->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
    else
        ui->tableInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::on_chkBoxRowColor_clicked(bool checked)
{
    ui->tableInfo->setAlternatingRowColors(checked);
}



void MainWindow::on_chkBoxHeaderH_clicked(bool checked)
{
    ui->tableInfo->horizontalHeader()->setVisible(checked);
}


void MainWindow::on_chkBoxHeaderV_clicked(bool checked)
{
    ui->tableInfo->verticalHeader()->setVisible(checked);
}

void MainWindow::on_rBtnSelectItem_clicked()
{
    ui->tableInfo->setSelectionBehavior(QAbstractItemView::SelectItems);
}


void MainWindow::on_rBtnSelectRow_clicked()
{
    ui->tableInfo->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::on_tableInfo_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    Q_UNUSED(previousRow);
    Q_UNUSED(previousColumn);

    QTableWidgetItem* item = ui->tableInfo->item(currentRow,currentColumn);
    if(item==NULL)
        return ;
    labCellIndex->setText(QString::asprintf("当前单元格坐标: %d 行,%d 列",currentRow,currentColumn));

    int cellType = item->type();
    labCellType ->setText(QString::asprintf("当前单元格类型:%d",cellType));

    item = ui->tableInfo->item(currentRow,MainWindow::colName);
    int ID = item->data(Qt::UserRole).toInt();
    labStudID->setText(QString::asprintf("学生ID:%d",ID));

}

void MainWindow::on_btnInsertRow_clicked()
{
    int curRow = ui->tableInfo->currentRow();
    ui->tableInfo->insertRow(curRow);
    createItemsARow(curRow,"新学生","男",QDate::fromString("1999-1-1","yyyy-M-d"),"苗族",true,60);
//    createItemsARow(curRow,"新学生","男",QDate::fromString("1990-1-1","yyyy-M-d"),"苗族",true,60 ); //为某一行创建items

}


void MainWindow::on_btnAppendRow_clicked()
{
    int curRow = ui->tableInfo->rowCount();
    ui->tableInfo->insertRow(curRow);
    createItemsARow(curRow,"新生","女",QDate::fromString("2000-01-1","yyyy-M-d"),"满族",true,55);

}


void MainWindow::on_btnDelCurRow_clicked()
{
    int curRow = ui->tableInfo->currentRow();
    ui->tableInfo->removeRow(curRow);
}



void MainWindow::on_btnAutoHeght_clicked()
{
    ui->tableInfo->resizeRowsToContents();

}

void MainWindow::on_btnAutoWidth_clicked()
{
    ui->tableInfo->resizeColumnsToContents();

}

void MainWindow::on_btnReadToEdit_clicked()
{
    QString str;
    QTableWidgetItem *cellItem;

    ui->textEdit->clear();
    for(int i=0;i<ui->tableInfo->rowCount();i++)
    {
        str=QString::asprintf("第%d行",i+1);
        for(int j=0;j<ui->tableInfo->columnCount()-1;j++)
        {
            cellItem = ui->tableInfo->item(i,j);
            str=str+cellItem->text()+"   ";
        }
        cellItem = ui->tableInfo->item(i,colPartyM);
        str = (cellItem->checkState()==Qt::Checked) ? str+"党员" : str+"群众";
//        if(cellItem->checkState()==Qt::Checked)
//            str = str+"党员";
//        else str = str + "群众";
        ui->textEdit->appendPlainText(str);
    }
}
