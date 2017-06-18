#include "networkmanager.h"

NetworkManager::NetworkManager(QObject *parent) : QObject(parent)
{
    initSockets();
}

void NetworkManager::initSockets() {
    networkSocket.reset(new QUdpSocket(this));

    networkSocket->bind(QHostAddress::Any, 3142);

    connect(networkSocket.data(), SIGNAL(readyRead()), this, SLOT(transmissionReceived()));
}

void NetworkManager::transmitText(QString text) {
    QByteArray datagram = text.toUtf8();

    networkSocket->writeDatagram(datagram.data(), datagram.size(),
                                 QHostAddress::Broadcast, 3142);
}

void NetworkManager::transmissionReceived() {
    while(networkSocket->hasPendingDatagrams()) {
        QString transmissionString;
        QByteArray datagram;
        datagram.resize(networkSocket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        networkSocket->readDatagram(datagram.data(), datagram.size(),
                                    &sender, &senderPort);

        transmissionString = QString(datagram);

        emit transmission(transmissionString);
    }
}
