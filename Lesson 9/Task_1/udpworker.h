#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDateTime>


#define BIND_PORT1 12345
#define BIND_PORT2 54321

class UDPworker : public QObject
{
    Q_OBJECT
public:
    explicit UDPworker(QObject *parent = nullptr);
    void InitSocket( void );
    void ReadDatagram( QNetworkDatagram datagram);
    void SendDatagram(QByteArray data );
    void ReadDatagramText( QNetworkDatagram datagram, QString address);
    void SendDatagramText(QByteArray data );


private slots:
    void readPendingDatagrams(void);
    void readPendingDatagramsText(void);

private:
    QUdpSocket* serviceUdpSocket;
    QUdpSocket* sizeTextUdpSocket;

signals:
    void sig_sendTimeToGUI(QDateTime data);
    void sig_sendsize(int data, QString address);
};

#endif // UDPWORKER_H
