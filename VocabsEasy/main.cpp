#include <iostream>
#include <get_resource_information.h>
#include <memory>
#include <QApplication>
#include <main_window.h>
int main(int argc, char* argv[]) {
    QApplication app(argc,argv);
    auto mainWindow = new MainWindow();
    mainWindow->show();

    app.exec();
    return 0;
}
