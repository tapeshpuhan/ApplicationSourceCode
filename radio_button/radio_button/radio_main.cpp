#include <QApplication>
#include <QWindow>
#include "create_button.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWindow window;

    window.resize(400,400);

    CreateButton button;
    button.RegisterForSelectionType([&](ButtonSelectionType value)
    {
        qDebug()<<"Selection type "<<static_cast<uint32_t>(value);
    });
    button.CreateRedioButton();
    button.show();
   // window.show();
    return app.exec();
}
