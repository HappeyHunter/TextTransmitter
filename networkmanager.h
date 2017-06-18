#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QUdpSocket>

class NetworkManager : public QObject
{
    Q_OBJECT
public:
    NetworkManager(QObject *parent = 0);
    void transmitText(QString text);

private:
    void initSockets();

private:
    QScopedPointer<QUdpSocket> networkSocket;

signals:
    void transmission(QString transmissionString);

private slots:
    void transmissionReceived();
};

#endif // NETWORKMANAGER_H
