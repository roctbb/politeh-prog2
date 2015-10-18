#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTimer timer;

private:
    Ui::MainWindow *ui;
public slots:
    void changeProgress();
    void pushButton();
};

#endif // MAINWINDOW_H
