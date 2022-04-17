#ifndef ARDUINO_H
#define ARDUINO_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>

class arduino
{


public:
    arduino();

    int connect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray);
    int writeStringToArduino(const char*);
    QByteArray read_from_arduino();

    /// getters
    QSerialPort* getserial();
    QString getarduino_port_name();
private :
    QSerialPort * serial;
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_prod_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;
};

#endif // ARDUINO_H
