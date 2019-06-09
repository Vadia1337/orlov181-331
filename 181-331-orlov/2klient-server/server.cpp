#include "server.h"

#include <QTcpServer>
#include <QTcpSocket>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QDataStream>
#include <QTime>
#include <string>

int checkx = 0; int checko = 0;

Server::Server(quint16 port): _nextBlockSize(0){

_tcpServer = new QTcpServer(this);

if (!_tcpServer->listen(QHostAddress::Any, port)){

_tcpServer->close();

return;

}

connect(_tcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));

//connect(_tcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection1()));

_text = new QTextEdit();
_text->setReadOnly(true);
QVBoxLayout *layout = new QVBoxLayout;
layout->addWidget(new QLabel("<H1>Server</H1>"));
layout->addWidget(_text);
setLayout(layout);
resize(400,400);

}

void Server::slotNewConnection(){

//_clientSocket = _tcpServer->nextPendingConnection();

//connect(_clientSocket, SIGNAL(disconnected()), _clientSocket, SLOT(deleteLater()));

//connect(_clientSocket, SIGNAL(readyRead()), this, SLOT(slotReadClient()));

//sendToClient(_clientSocket, "Server response: connected.");

//_clientSocket->write("Server response: connected.\n\r");

    QTcpSocket* clientSocket=_tcpServer->nextPendingConnection();
    int idusersocs=clientSocket->socketDescriptor();
    SClients[idusersocs]=clientSocket;
    connect(SClients[idusersocs],SIGNAL(readyRead()),this, SLOT(slotReadClient()));

}


void Server::slotReadClient(){

//Вариант 1

//while(_clientSocket->bytesAvailable()>0){

//QByteArray array = _clientSocket->readAll();

//_clientSocket->write(array);

//}

//Вариант 2

//QTcpSocket *sckt = dynamic_cast<QTcpSocket *>(sender());

/*if (!_clientSocket->canReadLine()) return;

char buf[1024];

_clientSocket->readLine(buf, sizeof(buf));

_clientSocket->write(buf);

//_text->setText(buf);*/

//Вариант 3

foreach(int i ,SClients.keys()){

    QDataStream in(SClients[i]);

//in.setVersion(QDataStream::Qt_5_10);

while(true){
if (_nextBlockSize == 0){
 if (SClients[i]->bytesAvailable() <static_cast<int>(sizeof(quint16))){
break;
}
in >> _nextBlockSize;
}
 if (SClients[i]->bytesAvailable() < _nextBlockSize){
break;
}

QTime time;
QString str;
QString result;
QString a[9];
in >> time >> str;

a[0]="1";
a[1]="2";
a[2]="3";
a[3]="4";
a[4]="5";
a[5]="6";
a[6]="7";
a[7]="8";
a[8]="9";




result = result = "|" + a[0] + "|" + a[1] + "|" + a[2] + "|" + "\n" + "|" + a[3] + "|" + a[4] + "|" + a[5] + "|" + "\n"+ "|" + a[6] + "|" + a[7] + "|" + a[8] + "|" + "\n" ;






sendToClient(SClients[i], "Ваш ход!");


if (checkx == 0) {
sendToClient(SClients[i], "За x или за o ?");
}


if (str == "x"){
 checkx = 1;
    _tcpServer->listen();
    sendToClient(SClients[i], "Вы играете за O");
   sendToClient(SClients[i], "Введите номер ячейки...");

}
else if (str == "o"){
 checko = 1;
   sendToClient(SClients[i], "Вы играете за X");
   sendToClient(SClients[i], "Введите номер ячейки...");


}






//sendToClient(SClients[i], "Поле игры ""\n" + result); //ВАЖНО



/*
if(str ==  "x"){
    _tcpServer->listen();
   QString message = time.toString() + " " + "server open - " + str + ".";
      QString message1 = time.toString() + " " + "Client has sent  - " + str + ".";
        sendToClient(SClients[i], "Server response: received \"" + str + "\".");

    _text->append(message);
    _text->append(message1);
}
else if (str == "o") {
    QString message = time.toString() + " " + "server close - " + str + ".";
       sendToClient(SClients[i], "close \"" + str + "\".");
      _text->append(message);
     _tcpServer->close();
}
*/
_nextBlockSize = 0;

}

}
}

void Server::sendToClient(QTcpSocket* socket, const QString &str){

QByteArray arrBlock;

QDataStream out(&arrBlock, QIODevice::WriteOnly);

//out.setVersion(QDataStream::Qt_5_10);

out << quint16(0) << QTime::currentTime() << str;

out.device()->seek(0);

out << quint16(arrBlock.size() - static_cast<int>(sizeof(quint16)));

socket->write(arrBlock);

}


