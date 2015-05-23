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
    void setupConnection();
    void readMessage();
    void sendMessage();
    void enableSetupConnectionButton();

private:
    QTextEdit *chatField;
    QTextEdit *messageField;
    QLabel *statusLabel;
    QPushButton *enterButton;

    QLabel *hostLabel;
    QLabel *portLabel;
    QComboBox *hostCombo;
    QLineEdit *portLineEdit;
    QPushButton *setupConnectionButton;

    QTcpSocket *tcpSocket;
    QNetworkSession *networkSession;
    quint16 blockSize;
};
