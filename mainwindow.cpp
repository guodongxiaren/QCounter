#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowIcon(QIcon("icon.ico"));
    ui->setupUi(this);
    ui->lineEdit->setEnabled(false);
    ui->lineEdit->setAlignment(Qt::AlignRight);//设置显示居右
    ui->lineEdit->setStyleSheet("font-size:18px");//设置字体大小为18px
    ui->lineEdit->setText("0");//设置初试文本为0
    init();

}

MainWindow::~MainWindow()
{
    delete ui;
}
//初始化操作.不仅开头调用，每次计算完结果都会调用。
void MainWindow::init()
{
    if(!expStack.isEmpty())
        expStack.clear();
    if(!opStack.isEmpty())
        opStack.clear();
    opStack.push('#');
    complete=true;
}
void MainWindow::on_btn0_clicked()
{
    QString s = ui->lineEdit->text();
    if(!complete)
        ui->lineEdit->setText(s+"0");
    else
    {
        ui->lineEdit->setText("0");
        complete = false;
    }
}

void MainWindow::on_btn1_clicked()
{
    QString s = ui->lineEdit->text();
    if(!complete)
        ui->lineEdit->setText(s+"1");
    else
    {
        ui->lineEdit->setText("1");
        complete = false;
    }
}

void MainWindow::on_btn2_clicked()
{
    QString s = ui->lineEdit->text();
    if(!complete)
        ui->lineEdit->setText(s+"2");
    else
    {
        ui->lineEdit->setText("2");
        complete = false;
    }
}

void MainWindow::on_btn3_clicked()
{
    QString s = ui->lineEdit->text();
    if(!complete)
        ui->lineEdit->setText(s+"3");
    else
    {
        ui->lineEdit->setText("3");
        complete = false;
    }
}

void MainWindow::on_btn4_clicked()
{
    QString s = ui->lineEdit->text();
    if(!complete)
        ui->lineEdit->setText(s+"4");
    else
    {
        ui->lineEdit->setText("4");
        complete = false;
    }
}

void MainWindow::on_btn5_clicked()
{
    QString s = ui->lineEdit->text();
    if(!complete)
        ui->lineEdit->setText(s+"5");
    else
    {
        ui->lineEdit->setText("5");
        complete = false;
    }
}

void MainWindow::on_btn6_clicked()
{
    QString s = ui->lineEdit->text();
    if(!complete)
        ui->lineEdit->setText(s+"6");
    else
    {
        ui->lineEdit->setText("6");
        complete = false;
    }
}

void MainWindow::on_btn7_clicked()
{
    QString s = ui->lineEdit->text();
    if(!complete)
        ui->lineEdit->setText(s+"7");
    else
    {
        ui->lineEdit->setText("7");
        complete = false;
    }
}

void MainWindow::on_btn8_clicked()
{
    QString s = ui->lineEdit->text();
    if(!complete)
        ui->lineEdit->setText(s+"8");
    else
    {
        ui->lineEdit->setText("8");
        complete = false;
    }
}

void MainWindow::on_btn9_clicked()
{
    QString s = ui->lineEdit->text();
    if(!complete)
        ui->lineEdit->setText(s+"9");
    else
    {
        ui->lineEdit->setText("9");
        complete = false;
    }
}

void MainWindow::on_btnDot_clicked()
{
    //如果是小数点,那么不能以小数点打头
    QString s = ui->lineEdit->text();
    if(!complete)
        ui->lineEdit->setText(s+".");
}
///////////////////////////////////////////////////
//加号和减号应做特殊处理。因为也可以理解为正负号
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
//////////////////////////////////////////////////////
void MainWindow::on_btnMuti_clicked()
{
    QString s = ui->lineEdit->text();
    if(!complete)
        ui->lineEdit->setText(s+"*");
    else
    {
        ui->lineEdit->setText("*");
        complete = false;
    }
}

void MainWindow::on_btnDivi_clicked()
{
    QString s = ui->lineEdit->text();
    if(!complete)
        ui->lineEdit->setText(s+"/");
}
void MainWindow::on_btnLeft_clicked()
{
    QString s = ui->lineEdit->text();
    if(!complete)
        ui->lineEdit->setText(s+"(");
    else
    {
        ui->lineEdit->setText("(");
        complete = false;
    }
}

void MainWindow::on_btnRight_clicked()
{
    QString s = ui->lineEdit->text();
    if(!complete)
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
    QString exp = ui->lineEdit->text();
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
            postfix.push_back(' ');
            while(opStack.top()!='(')
            {
                postfix.push_back(opStack.pop());qDebug()<<postfix;
            }
            opStack.pop();
        }
        else if(getLevel(exp[i])>getLevel(opStack.top()))
        {
            postfix.push_back(' ');qDebug()<<"postfix";
            opStack.push(exp[i]);
        }
        else
        {
            postfix.push_back(' ');qDebug()<<postfix;
            while(getLevel(exp[i])<=getLevel(opStack.top()))
                postfix.push_back(opStack.pop());
            opStack.push(exp[i]);
        }
    }
    while(opStack.top()!='#')
    {
        QChar c = opStack.pop();
        postfix.push_back(' ');
        postfix.push_back(c);
    }
    qDebug()<<postfix;
}
//
void MainWindow::evaluation()
{
    QString tem;
    QStack<double> ans;
    for(int i=0;i<postfix.size();i++)
    {
        qDebug()<<postfix[i]<<i;
        if(postfix[i].isDigit()||postfix[i]=='.')
            tem.push_back(postfix[i]);
        else if(postfix[i]==' ')
        {
            if(!tem.isEmpty())
            {
                ans.push(tem.toDouble());
                tem.clear();
            }
            qDebug()<<ans.top()<<tem.isEmpty();
        }
        else
        {
            double a,b;
            a=ans.pop();qDebug()<<a<<"a";
            b=ans.pop();qDebug()<<b<<"b";
            switch(postfix[i].cell())
            {
            case '+':ans.push(b+a);break;
            case '-':ans.push(b-a);break;
            case '*':ans.push(b*a);break;
            case '/':ans.push(b/a);break;
            case '%':ans.push((int)a%(int)b);break;
            }
            qDebug()<<ans.top()<<"top";
        }

    }
    //qDebug()<<ans.top();
    ui->lineEdit->setText(QString::number(ans.top()));
}
//等于号的槽函数。
void MainWindow::on_btnEqual_clicked()
{
    toPostfix();
    evaluation();
    init();
}


void MainWindow::on_btnClear_clicked()
{
    init();
}


void MainWindow::on_btnBack_clicked()
{
    QString s = ui->lineEdit->text();
    s=s.mid(0,s.size()-1);
    ui->lineEdit->setText(s);
}

void MainWindow::on_btnPer_clicked()
{
    QString s = ui->lineEdit->text();
    if(!complete)
        ui->lineEdit->setText(s+"9");
    else
    {
        ui->lineEdit->setText("9");
        complete = false;
    }
}

void MainWindow::on_action_2_triggered()
{
    AboutDialog *ad = new AboutDialog();
    ad->show();
}
