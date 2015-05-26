#include "quotesBrowser.h"
#include "ui_QuotesBrowser.h"

QuotesBrowser::QuotesBrowser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuotesBrowser),
    currentQuote(0)
{
    ui->setupUi(this);


    manager = new QNetworkAccessManager(this);
    QUrl bashRss("http://bash.im/rss/");
    reply = manager->get(QNetworkRequest(bashRss));
    connect(reply, SIGNAL(finished()), this, SLOT(loadQuotes()));
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(showNextQuote()));
}

QuotesBrowser::~QuotesBrowser()
{
    delete ui;
}

void QuotesBrowser::loadQuotes()
{
    QByteArray data(reply->readAll());

    QXmlStreamReader xml(data);
    while(!xml.atEnd())
    {
        if (xml.isCDATA())
            quotesList.append(xml.text().toString());
        xml.readNext();
    }

    if (currentQuote == 0)
        showNextQuote();
}

void QuotesBrowser::showNextQuote()
{
    if (currentQuote == quotesList.length())
    {
         ui->quotesView->append("You have read all quotes."
                                "Press next to start over");
         return;
    }
    if (currentQuote > quotesList.length())
        currentQuote = 0;

    ui->quotesView->clear();
    ui->quotesView->append(quotesList[currentQuote]);
    ui->quotesView->verticalScrollBar()->setSliderPosition(0);
    currentQuote++;
}
