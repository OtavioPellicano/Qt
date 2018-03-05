#include "arduino.h"

namespace opmm {

Arduino::Arduino(QSerialPort *parent) : QSerialPort(parent)
{
}

void Arduino::readyRead()
{

    QByteArray dataRead = mArduino.readAll();
    if(dataRead.size() != 0)
    {
        if(mCounter < 100)
        {
            ++mCounter;
            qDebug() << mCounter;
            emit arduinoRead(mCounter);
        }
    }

}


void Arduino::setup() throw(QString)
{
    mPortAvailable = QSerialPortInfo::availablePorts();

    if (mPortAvailable.size() > 1)
    {
        throw QString("Just one serial port must be connected!");

    } else if(mPortAvailable.empty())
    {
        throw QString("There is no connected device!");
    }

    for(QList<QSerialPortInfo>::iterator itSPI = mPortAvailable.begin(); itSPI != mPortAvailable.end(); ++itSPI)
    {
        qDebug() << (*itSPI).portName();
        mArduino.setPortName((*itSPI).portName());
    }

    mArduino.setBaudRate(QSerialPort::Baud9600);
    mArduino.setParity(QSerialPort::NoParity);
    mArduino.setDataBits(QSerialPort::Data8);
    mArduino.setFlowControl(QSerialPort::NoFlowControl);
    mArduino.setStopBits(QSerialPort::TwoStop);

    mArduino.open(QIODevice::ReadWrite);
    if (mArduino.isOpen())
    {
        qDebug() << "Serial port is opened";
        connect(&mArduino, SIGNAL(readyRead()), this, SLOT(readyRead()));
    }
    else
    {
        throw QString("Impossible to open the serial port");
    }

}

void Arduino::setCounter(unsigned int counter)
{
    mCounter = counter;
}

}
