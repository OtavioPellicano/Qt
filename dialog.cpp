#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    mArduino = new opmm::Arduino();

}

Dialog::~Dialog()
{
    delete ui;
    delete mArduino;
}

void Dialog::arduinoRead(unsigned int data)
{
    ui->progressBar_rx->setValue(data);

    if(data == 100)
    {
        ui->pushButton_connect->setEnabled(true);
        disconnect(mArduino, SIGNAL(arduinoRead(uint)), this, SLOT(arduinoRead(uint)));
        QMessageBox::information(this, "Completed", "100 package has been sent!", QMessageBox::Ok);
    }
}

void Dialog::on_pushButton_connect_clicked()
{
    try {
        mArduino->setup();
        mArduino->setCounter(0);
    } catch (QString &qs) {
        QMessageBox::critical(this, "Setup Error", qs, QMessageBox::Ok);
        return;
    } catch(...)
    {
        QMessageBox::critical(this, "Setup Error" , "unexpected error!", QMessageBox::Ok);
    }

    connect(mArduino, SIGNAL(arduinoRead(uint)), this, SLOT(arduinoRead(uint)));
    ui->pushButton_connect->setEnabled(false);

}

