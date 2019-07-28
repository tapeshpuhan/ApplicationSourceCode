#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    MainWindow w(0,"w");
    MainWindow w_n(0,"w_n");

    MainWindow *w1 = new MainWindow(&w,"w1");
    MainWindow *w_n1 = new MainWindow(&w,"w_n1");

    new MainWindow(w1,"a");
    new MainWindow(w1,"b");
   MainWindow *x = new MainWindow(w_n1,"c");
    //new MainWindow(0,"c");
    w.dumpObjectTree();

    //return a.exec();
}
