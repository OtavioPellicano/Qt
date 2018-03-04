#ifndef ARDUINO_H
#define ARDUINO_H

//#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QList>
#include <QDebug>
#include <QMessageBox>
#include <QString>


namespace opmm {

class Arduino : public QSerialPort
{
    Q_OBJECT
public:
    explicit Arduino(QSerialPort *parent = nullptr);

signals:
    void arduinoRead(unsigned int);

public slots:
    void readyRead();

public:
    void setup()throw(QString);

    void setCounter(unsigned int counter);

private:
    QSerialPort mArduino;
    QList<QSerialPortInfo> mPortAvailable;

    unsigned int mCounter = 0;


};

}


#endif // ARDUINO_H
