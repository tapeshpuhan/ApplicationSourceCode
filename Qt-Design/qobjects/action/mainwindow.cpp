#include "mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    action = new QAction(tr("New"),this);
    action->setShortcuts(QKeySequence::AddTab);
    action->setStatusTip(tr("new file creation"));
    connect(action, &QAction::triggered, this, &MainWindow::newFile);

    file = new QMenu("&Questions", this);
    QMainWindow::menuBar()->addMenu(file);
    file->addAction(action);
    setMinimumSize(160, 160);
    resize(480, 320);
}

MainWindow::~MainWindow()
{

}
 void MainWindow::newFile()
 {
     qDebug()<<"newFileCaled";
 }
