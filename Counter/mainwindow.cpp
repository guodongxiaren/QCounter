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
void MainWindow::on_btnLeft_clicked()
{
    QString s = ui->lineEdit->text();
    if(s!="0")
        ui->lineEdit->setText(s+"(");
    else
        ui->lineEdit->setText("(");
}

void MainWindow::on_btnRight_clicked()
{
    QString s = ui->lineEdit->text();
    ui->lineEdit->setText(s+")");
}
//得到运算符的优先级
int MainWindow::getLevel(const QChar &oper)
{
    switch(oper.cell())
    {
    case '#':
    case '(':return 0;
    case '+':
    case '-':return 1;
    case '*':
    case '/':
    case '%':return 2;
    }
    return 0;
}
//转换为后缀表达式，实现最主要功能
void MainWindow::toPostfix()
{
    QString exp = ui->lineEdit->text(),postfix;
    //QString exp = "0.3/(5*2+1)",postfix;

    int j=0;
    qDebug()<<j;
    for(int i=0;i<exp.length();i++)
    {qDebug()<<i<<exp[i];
        if(exp[i].isDigit()||exp[i]=='.')
        {
            postfix.push_back(exp[i]);
        }
        else if(exp[i]=='(')
        {
            opStack.push(exp[i]);
        }
        else if(exp[i]==')')
        {
            while(opStack.top()!='(')
            {
                postfix.push_back(opStack.pop());
            }
            opStack.pop();
        }
        else if(getLevel(exp[i])>getLevel(opStack.top()))
            opStack.push(exp[i]);
        else
        {
            while(getLevel(exp[i])<=getLevel(opStack.top()))
                postfix.push_back(opStack.pop());
            opStack.push(exp[i]);
        }
    }
    while(!opStack.isEmpty())
    {
        QChar c = opStack.pop();qDebug()<<c<<"wh";
        postfix.push_back(c);
    }
    qDebug()<<postfix;
}
//等于号的槽函数。
void MainWindow::on_btnEqual_clicked()
{
    toPostfix();
}


void MainWindow::on_btnClear_clicked()
{
    QChar a('a');
    if(a=='a')
        qDebug()<<"YES";
}
