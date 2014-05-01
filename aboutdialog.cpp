#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    setModal(true);
    //setWindowTitle("About QCounter");
    ui->setupUi(this);
   // ui->logoLabel->show();
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
