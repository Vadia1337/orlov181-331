#ifndef SEVER_H

#define SEVER_H

#include <QWidget>
#include <QObject>
#include <QByteArray>
#include <QMap>
class QTcpServer;

class QTcpSocket;

class QTextEdit;
class Server: public QWidget{

Q_OBJECT

private:

QTcpServer *_tcpServer;

QTcpSocket *_clientSocket;

int server_status;
QMap<int,QTcpSocket *> SClients;

quint16 _nextBlockSize;
bool stack=false;

QTextEdit *_text;


void sendToClient(QTcpSocket *socket, const QString &str);


public:

Server(quint16 port);

public slots:

virtual void slotNewConnection();

void slotReadClient();


};

#endif // SEVER_H
