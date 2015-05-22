#include "server.h"

Server::Server(QWidget *parent)
    : QWidget(parent), tcpServer(0), tcpSocket(0), networkSession(0)
{
    statusLabel = new QLabel;

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
    setLayout(mainLayout);

    setWindowTitle(tr("Chat Server"));

    chatField = new QTextEdit;
    mainLayout->addWidget(chatField);
    chatField->setDisabled(true);
    chatField->setReadOnly(true);

    messageField = new QTextEdit;
    mainLayout->addWidget(messageField);
    messageField->setMaximumHeight(50);
    messageField->setPlaceholderText("Enter your message here");
    messageField->setDisabled(true);

    enterButton = new QPushButton(tr("Enter"));
    mainLayout->addWidget(enterButton);
    enterButton->setDisabled(true);

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        networkSession = new QNetworkSession(manager.defaultConfiguration(), this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        statusLabel->setText(tr("Opening network session."));
        networkSession->open();
    }
    else
        sessionOpened();

    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(connected()));
    connect(enterButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
}


void Server::sessionOpened()
{
    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen())
    {
        QMessageBox::critical(this, tr("Chat Server"),
                              tr("Unable to start the server: %1.")
                              .arg(tcpServer->errorString()));
        close();
        return;
    }

    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address())
        {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                            "Run the Chat Client now.")
                         .arg(ipAddress).arg(tcpServer->serverPort()));
}

void Server::connected()
{
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, SIGNAL(disconnected()), tcpSocket, SLOT(deleteLater()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    statusLabel->setText("Connected");
    chatField->setEnabled(true);
    messageField->setEnabled(true);
    enterButton->setEnabled(true);
    chatField->append("<New chat started>");
}

void Server::readMessage()
{
    QDataStream in(tcpSocket);
    //in.setVersion(QDataStream::Qt_4_0);

    if (blockSize == 0)
    {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blockSize;
    }

    if (tcpSocket->bytesAvailable() < blockSize)
        return;

    QString message;
    in >> message;
    chatField->append("CLIENT: " + message);
    blockSize = 0;
}

void Server::sendMessage()
{
    chatField->append("SERVER: ");
    chatField->append(messageField->toPlainText());
    chatField->append("");
    messageField->clear();

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    //out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << messageField->toPlainText();
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    tcpSocket->write(block);
}
