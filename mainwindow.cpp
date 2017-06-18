#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPlainTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    myNetworkManager(this),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialise();
}

void MainWindow::initialise()
{
    connect(&myNetworkManager, SIGNAL(transmission(QString)), this, SLOT(transmissionReceived(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
    myNetworkManager.transmitText(ui->plainTextEdit->toPlainText());
}

void MainWindow::transmissionReceived(QString transmission)
{
    ui->plainTextEdit->setPlainText(transmission);
}
