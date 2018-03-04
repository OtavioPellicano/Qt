#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "arduino.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();


public slots:
    void arduinoRead(unsigned int data);

private slots:
    void on_pushButton_connect_clicked();


private:
    Ui::Dialog *ui;

    opmm::Arduino *mArduino;

};

#endif // DIALOG_H
