#pragma once

#include <QtNetwork>
#include <QtWidgets>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QWidget
{
    Q_OBJECT

public:
    Server(QWidget *parent = 0);

private slots:
    void sessionOpened();
    void connected();
    void readMessage();
    void sendMessage();

private:
    QTextEdit *chatField;
    QTextEdit *messageField;
    QLabel *statusLabel;
    QPushButton *enterButton;

    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    QNetworkSession *networkSession;
    quint16 blockSize;
};
