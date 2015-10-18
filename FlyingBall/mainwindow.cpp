#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QBrush>
#include <QPen>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    santehnik.setInterval(30);
    santehnik.start();
    connect(&santehnik, SIGNAL(timeout()),
            this, SLOT(makeStep()));
}
void MainWindow::makeStep() {
    vasya.move();
    this->repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    vasya.draw(&painter);

}
