#include <iostream>
#include <get_resource_information.h>
#include <memory>
#include <QApplication>
#include <main_window.h>
int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;
//    auto resourceObject = std::make_unique<GetResourceInformation>();
//
//    auto verbs = resourceObject->getVerbInformation();
//
//    for(const auto& v : verbs)
//    {
//      qDebug()<<v.m_name;
//      qDebug()<<v.m_outputPath;
//      qDebug()<<v.m_inputPath;
//      qDebug()<<v.m_ichName;
//      qDebug()<<v.m_duName;
//      qDebug()<<v.m_erName;
//      qDebug()<<v.m_wirName;
//      qDebug()<<v.m_ihrName;
//      qDebug()<<v.m_sieName;
//      qDebug()<<v.m_englishMeaning;
//      qDebug()<<v.m_hindiMeaning;
//      qDebug()<<v.m_germanSentence;
//      qDebug()<<v.m_englishSentence;
//      qDebug()<<"";
//    }

    QApplication app(argc,argv);
    auto mainWindow = new MainWindow();
    mainWindow->show();

    app.exec();
    return 0;
}
