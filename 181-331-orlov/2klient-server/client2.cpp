#include "client2.h"
#include <QTcpSocket>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QTime>

Client2::Client2(const QString &strHost, quint16 port): _nextBlockSize1(0){
    _tcpSocket1 = new QTcpSocket(this);
    _tcpSocket1->connectToHost(strHost, port);

    connect(_tcpSocket1, SIGNAL(connected()), this, SLOT(slotConnected()));
    connect(_tcpSocket1, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));

    _textInfo1 = new QTextEdit();
    _textInput1 = new QLineEdit();
    _textInfo1->setReadOnly(true);
    QPushButton *button = new QPushButton("Send");

    connect(button, SIGNAL(clicked()), SLOT(slotSendToServer()));
    connect(_textInput1, SIGNAL(returnPressed()), this, SLOT(slotSendToServer()));

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(new QLabel("<H1>Client2</H1>"));
    layout->addWidget(_textInfo1);
    layout->addWidget(_textInput1);
    layout->addWidget(button);
    setLayout(layout);
}

void Client2::slotReadyRead(){
    QDataStream in(_tcpSocket1);
    //in.setVersion(QDataStream::Qt_5_10);

    while(true){
        if (_nextBlockSize1 == 0){
            if (_tcpSocket1->bytesAvailable() <static_cast<int>(sizeof(quint16))){
                break;
            }

            in >> _nextBlockSize1;
        }

        if (_tcpSocket1->bytesAvailable() < _nextBlockSize1){
            break;
        }

        QTime time1;
        QString str1;
        in >> time1 >> str1;
        _textInfo1->append(time1.toString() + " " + str1);

        _nextBlockSize1 = 0;
    }
}

void Client2::slotSendToServer(){
    QByteArray  arrBlock1;
    QDataStream out1(&arrBlock1, QIODevice::WriteOnly);
    //out.setVersion(QDataStream::Qt_5_10);

    out1 << quint16(0) << QTime::currentTime() << _textInput1->text();
    out1.device()->seek(0);
    out1<< quint16(arrBlock1.size() - static_cast<int>(sizeof(quint16)));

    _tcpSocket1->write(arrBlock1);
    _textInput1->setText("");
}

void Client2::slotConnected(){
    _textInfo1->append("Received the \"connected tooo\" signal.");
}

/*void Client::slotError(QAbstractSocket::SocketError err)

}*/
