#include "client.h"

Client::Client(QWidget *parent)
    : QWidget(parent), tcpSocket(new QTcpSocket(/*this*/)), networkSession(0), blockSize(0)
{
    hostLabel = new QLabel(tr("&Server name:"));
    portLabel = new QLabel(tr("S&erver port:"));

    hostCombo = new QComboBox;
    hostCombo->setEditable(true);
    // find out name of this machine
    QString name = QHostInfo::localHostName();
    if (!name.isEmpty()) {
        hostCombo->addItem(name);
        QString domain = QHostInfo::localDomainName();
        if (!domain.isEmpty())
            hostCombo->addItem(name + QChar('.') + domain);
    }
    if (name != QString("localhost"))
        hostCombo->addItem(QString("localhost"));
    // find out IP addresses of this machine
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // add non-localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (!ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());
    }
    // add localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());
    }

    portLineEdit = new QLineEdit;
    portLineEdit->setValidator(new QIntValidator(1, 65535, this));

    hostLabel->setBuddy(hostCombo);
    portLabel->setBuddy(portLineEdit);

    statusLabel = new QLabel(tr("You should run the "
                                "Chat Server as well."));

    setupConnectionButton = new QPushButton(tr("Setup connection"));
    setupConnectionButton->setDefault(true);
    setupConnectionButton->setEnabled(false);


    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(hostLabel, 0, 0);
    mainLayout->addWidget(hostCombo, 0, 1);
    mainLayout->addWidget(portLabel, 1, 0);
    mainLayout->addWidget(portLineEdit, 1, 1);
    mainLayout->addWidget(statusLabel, 2, 0, 1, 2);
    mainLayout->addWidget(setupConnectionButton, 3, 0, 1, 2);
    setLayout(mainLayout);

    setWindowTitle(tr("Chat Client"));
    portLineEdit->setFocus();

    QBoxLayout *chatLayout = new QBoxLayout(QBoxLayout::TopToBottom);

    chatField = new QTextEdit;
    chatLayout->addWidget(chatField);
    chatField->setDisabled(true);
    chatField->setReadOnly(true);

    messageField = new QTextEdit;
    chatLayout->addWidget(messageField);
    messageField->setMaximumHeight(50);
    messageField->setPlaceholderText("Enter your message here");
    messageField->setDisabled(true);

    enterButton = new QPushButton(tr("Enter"));
    chatLayout->addWidget(enterButton);
    enterButton->setDisabled(true);

    mainLayout->addLayout(chatLayout, 4, 0, 1, 2);

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        networkSession = new QNetworkSession(manager.defaultConfiguration(), this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        setupConnectionButton->setEnabled(false);
        statusLabel->setText(tr("Opening network session."));
        networkSession->open();
    }

    connect(setupConnectionButton, SIGNAL(clicked()), this, SLOT(setupConnection()));
    connect(tcpSocket, SIGNAL(connected()), this, SLOT(connected()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    connect(enterButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(portLineEdit, SIGNAL(textChanged(QString)), this, SLOT(enableSetupConnectionButton()));
}


void Client::sessionOpened()
{
    statusLabel->setText(tr("You should run the "
                            "Chat Server as well."));

    setupConnectionButton->setEnabled(true);
}

void Client::connected()
{
    statusLabel->setText("Connected");
    chatField->setEnabled(true);
    messageField->setEnabled(true);
    enterButton->setEnabled(true);
    chatField->append("<New chat started>");
}

void Client::setupConnection()
{
    setupConnectionButton->setEnabled(false);
    blockSize = 0;
    tcpSocket->abort();
    tcpSocket->connectToHost(hostCombo->currentText(), portLineEdit->text().toInt());
}

void Client::readMessage()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);

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
    chatField->append("SERVER:\n" + message);
    blockSize = 0;
}

void Client::sendMessage()
{
    chatField->append("CLIENT:\n" + messageField->toPlainText());

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << messageField->toPlainText();
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    tcpSocket->write(block);

    messageField->clear();
}

void Client::enableSetupConnectionButton()
{
    setupConnectionButton->setEnabled(true);
}
