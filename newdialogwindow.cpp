#include "newdialogwindow.h"
#include "ui_newdialogwindow.h"
#include <QtGui>
#include "dialog.h"
#include <QIcon>
#include"ProgrammableInputOutputMacro.h"




NewDialogWindow::NewDialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDialogWindow)
{
    ui->setupUi(this);
   // WarningImage();

}
void NewDialogWindow::WarningImage()
{
// ui->label->pixmap();

}

NewDialogWindow::~NewDialogWindow()
{
    delete ui;
}



void NewDialogWindow::on_Accept_clicked()
{
    emit this->SignalForXmlWrite();
    close();

}



void NewDialogWindow::on_Abort_clicked()
{
    QWidget::close();
}
