#include "mainwindow.h"
#include <QPushButton>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QApplication>
#include <QMenu>
#include <QToolBar>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // add central widget
    QPushButton *push_button = new QPushButton("Play");
    setCentralWidget(push_button);

    //add Qt action
    QAction * quit_action = new QAction("Quit");

    connect(quit_action,&QAction::triggered,[this](){
        QApplication::quit();
    });

    // add menubar
    QMenu * file_menu = menuBar()->addMenu("File");
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("View");
    menuBar()->addMenu("Insert");

    // add tool bar
    auto fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(quit_action);

    file_menu->addAction(quit_action);
    // add status bar
    statusBar()->showMessage("Uplode file",100000);

    // add dock Widget
    QDockWidget *dockWidget = new QDockWidget(tr("Dock Widget"), this);
    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea |
                                Qt::RightDockWidgetArea);
    dockWidget->setWidget(push_button);
    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
    resize(500,600);
}

MainWindow::~MainWindow()
{

}
