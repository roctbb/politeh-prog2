#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "ball.h"

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
    Ball vasya;
    QTimer santehnik;
protected:
    void paintEvent(QPaintEvent *event);
public slots:
    void makeStep();
};

#endif // MAINWINDOW_H
