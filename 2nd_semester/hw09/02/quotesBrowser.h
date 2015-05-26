#pragma once

#include <QtWidgets>
#include <QXmlStreamReader>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

namespace Ui {
class QuotesBrowser;
}

class QuotesBrowser : public QWidget
{
    Q_OBJECT

public:
    explicit QuotesBrowser(QWidget *parent = 0);
    ~QuotesBrowser();

private slots:
    void loadQuotes();
    void showNextQuote();

private:
    Ui::QuotesBrowser *ui;
    QXmlStreamReader reader;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QList<QString> quotesList;
    int currentQuote;
};

