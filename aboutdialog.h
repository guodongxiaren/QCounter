#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QLabel>
class AboutDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AboutDialog(QWidget *parent = 0);

signals:

public slots:

private:
    QLabel *name;
    QImage *logo;
};

#endif // ABOUTDIALOG_H
