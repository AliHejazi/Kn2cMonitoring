#ifndef SERIAL_H
#define SERIAL_H
#include <QSerialPort>
#include <QObject>
#include <QTimer>

class serial : public QObject
{
    Q_OBJECT
public:
    explicit serial(QObject* parent = 0);
private:
    QSerialPort *wifiPort;
    QTimer *mytime;
    bool enableParity;
    bool flowControl;
    QSerialPort::BaudRate br;
    QSerialPort::DataBits databits;
    QString portName;
};

#endif // SERIAL_H
