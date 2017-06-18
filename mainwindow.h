#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "networkmanager.h"

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
    void initialise();

private slots:
    void on_pushButton_pressed();
    void transmissionReceived(QString transmission);

private:
    NetworkManager myNetworkManager;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
