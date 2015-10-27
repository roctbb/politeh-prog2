#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include "ball.h"
#include "hikkaball.h"
const int ballAmount = 10;

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

	private:
		Ui::MainWindow *ui;
		Ball vasya[ballAmount];
        HikkaBall anton;
		QTimer santehnik;
	protected:
		void paintEvent(QPaintEvent *event);
        void keyPressEvent(QKeyEvent *event);
	public slots:
		void makeStep();
};

#endif // MAINWINDOW_H
