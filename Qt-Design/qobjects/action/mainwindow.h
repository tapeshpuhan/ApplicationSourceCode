#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include<QMenu>
#include <QMenuBar>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    private slots:
    void newFile();
private:
    QMenu *file;
    QAction *action;
};

#endif // MAINWINDOW_H
