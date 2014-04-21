#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setEnabled(false);
    ui->lineEdit->setAlignment(Qt::AlignRight);//设置显示居右
    ui->lineEdit->setText("0");//设置初试文本为0
    ui->lineEdit->setStyleSheet("font-size:18px");//设置字体大小为18px
    opStack.push('#');
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn0_clicked()
{
    ui->lineEdit->setText("0");
}

void MainWindow::on_btn1_clicked()
{
    QString s = ui->lineEdit->text();
    if(s!="0")
        ui->lineEdit->setText(s+"1");
    else
        ui->lineEdit->setText("1");
}

void MainWindow::on_btn2_clicked()
{
    QString s = ui->lineEdit->text();
    if(s!="0")
        ui->lineEdit->setText(s+"2");
    else
        ui->lineEdit->setText("2");
}

void MainWindow::on_btn3_clicked()
{
    QString s = ui->lineEdit->text();
    if(s!="0")
        ui->lineEdit->setText(s+"3");
    else
        ui->lineEdit->setText("3");
}

void MainWindow::on_btn4_clicked()
{
    QString s = ui->lineEdit->text();
    if(s!="0")
        ui->lineEdit->setText(s+"4");
    else
        ui->lineEdit->setText("4");
}

void MainWindow::on_btn5_clicked()
{
    QString s = ui->lineEdit->text();
    if(s!="0")
        ui->lineEdit->setText(s+"5");
    else
        ui->lineEdit->setText("5");
}

void MainWindow::on_btn6_clicked()
{
    QString s = ui->lineEdit->text();
    if(s!="0")
        ui->lineEdit->setText(s+"6");
    else
        ui->lineEdit->setText("6");
}

void MainWindow::on_btn7_clicked()
{
    QString s = ui->lineEdit->text();
    if(s!="0")
        ui->lineEdit->setText(s+"7");
    else
        ui->lineEdit->setText("7");
}

void MainWindow::on_btn8_clicked()
{
    QString s = ui->lineEdit->text();
    if(s!="0")
        ui->lineEdit->setText(s+"8");
    else
        ui->lineEdit->setText("8");
}

void MainWindow::on_btn9_clicked()
{
    QString s = ui->lineEdit->text();
    if(s!="0")
        ui->lineEdit->setText(s+"9");
    else
        ui->lineEdit->setText("9");
}

void MainWindow::on_btnDot_clicked()
{
    //如果是小数点,那么不考虑前导符为0的情况
    QString s = ui->lineEdit->text();
    ui->lineEdit->setText(s+".");
}

void MainWindow::on_btnAdd_clicked()
{
    QString s = ui->lineEdit->text();
    if(s!="0")
        ui->lineEdit->setText(s+"+");
    else
        ui->lineEdit->setText("+");
}

void MainWindow::on_btnSub_clicked()
{
    QString s = ui->lineEdit->text();
    if(s!="0")
        ui->lineEdit->setText(s+"-");
    else
        ui->lineEdit->setText("-");
}

void MainWindow::on_btnMuti_clicked()
{
    QString s = ui->lineEdit->text();
    if(s!="0")
        ui->lineEdit->setText(s+"*");
    else
        ui->lineEdit->setText("*");
}

void MainWindow::on_btnDivi_clicked()
{
    QString s = ui->lineEdit->text();
    if(s!="0")
        ui->lineEdit->setText(s+"/");
    else
        ui->lineEdit->setText("/");
}
//得到运算符的优先级
int MainWindow::getLevel(const QChar &oper)
{
    int level=0;
    switch(oper.cell())
    {
    case '#':level = 0;break;
    case ')':level = 1;break;
    case '+':
    case '-':level = 2;break;
    case '*':
    case '/':
    case '%':level = 3;break;
    case '(':level = 4;break;
    }
    return level;
}
/*比较两个运算符优先级大小
 *若大于返回true,小于等于返回false
 */
bool MainWindow::greater(const QChar& oper1, const QChar& oper2)
{
    if(getLevel(oper1)>getLevel(oper2))
        return true;
    return false;
}
//等于号的槽函数。实现最主要功能
void MainWindow::on_btnEqual_clicked()
{
    QString exp = ui->lineEdit->text();
    QString::iterator it;
    QChar tem;
    for(it=exp.begin();it<exp.end();++it)
    {
        if(it->isDigit()||it->cell()=='.')
           {
             qDebug()<<*it<<"if";
            expStack.push(*it);}
        else if(greater(*it,opStack.top()))
           { opStack.push(*it); qDebug()<<*it<<"else if";
        }
        else
        {
            qDebug()<<*it<<"else";
            tem = *it;
            expStack.push(*(++it));
            expStack.push(tem); qDebug()<<*it<<"else2";
        }
    }
    while(!opStack.isEmpty())
    {
        QChar c = opStack.pop();qDebug()<<c<<"wh";
        if(c.cell()!=')'&&c.cell()!='('&&c.cell()!='#')
        expStack.push(c);
    }
    QString s;
    for(it=expStack.begin();it!=expStack.end();++it)
    {
        s+=*it;
    }
    ui->lineEdit->setText(s);
}
void MainWindow::on_btnLeft_clicked()
{
    QString s = ui->lineEdit->text();
    ui->lineEdit->setText(s+"(");
}

void MainWindow::on_btnRight_clicked()
{
    QString s = ui->lineEdit->text();
    ui->lineEdit->setText(s+")");
}
