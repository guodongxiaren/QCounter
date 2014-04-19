#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setEnabled(false);
    ui->lineEdit->setAlignment(Qt::AlignRight);//设置显示居右
    ui->lineEdit->setText("0");//设置初试文本为0
    ui->lineEdit->setStyleSheet("font-size:18px");//设置字体大小为18px
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
    QString s = ui->lineEdit->text();
    if(s!="0")
        ui->lineEdit->setText(s+".");
    else
        ui->lineEdit->setText(".");
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
