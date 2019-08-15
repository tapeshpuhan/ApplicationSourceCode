#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->ButtonToChangeText,SIGNAL(clicked(bool)),this,SLOT(GetText(bool)));
    //connect(ui->ButtonToChangeText,&QPushButton::clicked,this,&MainWindow::GetText);
//    connect(ui->ButtonToChangeText,&QPushButton::clicked,[&](bool text){
//        GetText(text);
//    });
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::GetText(bool clicked)
{
    qDebug()<<" lambda name changed "<<clicked;

}
