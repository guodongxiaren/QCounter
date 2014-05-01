#include "aboutdialog.h"
AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    //设置为模态对话框
    this->setModal(true);

}
