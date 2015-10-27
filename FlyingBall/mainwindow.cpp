#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
using namespace Qt;

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	santehnik.setInterval(10);
	santehnik.start();
	connect(&santehnik, SIGNAL(timeout()),
		   this, SLOT(makeStep()));
}
void MainWindow::makeStep() {
	for (int i = 0; i < ballAmount; i++)
	{
		vasya[i].move();
		for (int j = 0; j < ballAmount; j++)
		{
            if ((((vasya[i].getX() <= vasya[j].getX()+vasya[i].getRadius() && vasya[i].getX() >= vasya[j].getX() - vasya[i].getRadius()) || (vasya[j].getX() <= vasya[i].getX()+vasya[j].getRadius() && vasya[j].getX() >= vasya[i].getX() - vasya[j].getRadius())) && ((vasya[i].getY() <= vasya[j].getY()+vasya[i].getRadius()) && (vasya[i].getY() >= vasya[j].getY() - vasya[i].getRadius()) || (vasya[j].getY() <= vasya[i].getY()+vasya[j].getRadius() && vasya[j].getY() >= vasya[i].getY() - vasya[j].getRadius()))))
			{
				vasya[i].reverseX();
				vasya[j].reverseX();
				vasya[i].reverseY();
				vasya[j].reverseY();
			}
		}
	}
	this->repaint();
}

MainWindow::~MainWindow()
{
	delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_W)
    {
        anton.up();
    }
    if (event->key() == Qt::Key_S)
    {
        anton.down();
    }
    if (event->key() == Qt::Key_A)
    {
        anton.left();
    }
    if (event->key() == Qt::Key_D)
    {
        anton.right();
    }


}

void MainWindow::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	for (int i = 0; i < ballAmount; i++)
	{
		vasya[i].draw(&painter);
	}
    anton.draw(&painter);
}
