#include <QtQuick>

int main(int argc, char** argv)
{
	QGuiApplication app(argc, argv);
	QQuickView view(QUrl("main.qml"));
	
	
	view.show();
	
	return app.exec();
}
