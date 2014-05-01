#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H
#include "ui_aboutdialog.h"

#include <QDialog>
#include <QLabel>
class AboutDialog : public QDialog,public Ui::Dialog
{
    Q_OBJECT
public:
    explicit AboutDialog(QWidget *parent = 0);

signals:

public slots:

};

#endif // ABOUTDIALOG_H
