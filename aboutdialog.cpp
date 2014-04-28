#include "aboutdialog.h"
#include <QHBoxLayout>
AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent)
{
    //设置为模态对话框
    this->setModal(true);
    this->name = new QLabel(tr("QCounter"));
    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(name);
//    logo = new QImage("/Image/calc.png");
//    QVBoxLayout *leftLayout = new QVBoxLayout;
//    leftLayout->addWidget(logo);
//    topLeftLayout->addLayout(leftLayout);
    setLayout(topLeftLayout);

}
