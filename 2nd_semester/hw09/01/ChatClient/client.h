#pragma once

#include <QtNetwork>
#include <QtWidgets>
#include <QTcpSocket>

class Client : public QWidget
{
    Q_OBJECT

public:
    Client(QWidget *parent = 0);

private slots:
    void sessionOpened();
    void connected();
    void setConnection();
    void readMessage();
    void sendMessage();
    void enableSetConnectionButton();

private:
    QTextEdit *chatField;
    QTextEdit *messageField;
    QLabel *statusLabel;
    QPushButton *enterButton;

    QLabel *hostLabel;
    QLabel *portLabel;
    QComboBox *hostCombo;
    QLineEdit *portLineEdit;
    QPushButton *setConnectionButton;

    QTcpSocket *tcpSocket;
    QNetworkSession *networkSession;
    qint16 blockSize;
};
