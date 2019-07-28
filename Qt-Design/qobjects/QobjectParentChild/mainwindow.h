#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QDebug>
#include <QString>

class MainWindow : public QObject
{

public:
    MainWindow(QObject *parent = 0, QString name="");
    virtual ~MainWindow()
    {
        qDebug()<<"Call the Destroction "<<objectName();
    }

};
MainWindow::MainWindow(QObject *parent , QString name):QObject(parent)
{
    setObjectName(name);
    qDebug()<<"Call Constructor of the Qobject is "<<name;
}

#endif // MAINWINDOW_H
