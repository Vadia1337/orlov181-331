#ifndef CLIENT2_H
#define CLIENT2_H

#include <QWidget>
#include <QTcpSocket>

class QTextEdit;
class QLineEdit;

class Client2: public QWidget{
    Q_OBJECT

private:
    QTcpSocket *_tcpSocket1;

    QTextEdit *_textInfo1;
    QLineEdit *_textInput1;
    quint16 _nextBlockSize1;

public:
    Client2(const QString &strHost, quint16 port);

public slots:
    void slotReadyRead();
    //void slotError(QAbstractSocket::SocketError);
    void slotSendToServer();
    void slotConnected();
};

#endif // CLIENT2_H
