#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->select_file_first,&QPushButton::clicked,[this](){on_select_file_first_clicked();});
    connect(ui->select_file_second,&QPushButton::clicked,[this](){on_select_file_first_2_clicked();});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_select_file_first_clicked()
{
    qDebug()<<"on_select_file_first_clicked";
    file1 = QFileDialog::getOpenFileName(this,"ref file","/home",tr("Image Files (*.bag *.png *.jpg *.bmp)"));
    ui->lineEdit->setText(file1);
}

void MainWindow::on_select_file_first_2_clicked()
{
    qDebug()<<"on_select_file_first_2_clicked";
    file2 = QFileDialog::getOpenFileName(this,"ref file","/home",tr("Image Files (*.bag *.png *.jpg *.bmp)"));
    ui->lineEdit_2->setText(file2);
}

void MainWindow::on_load_clicked()
{
    QPixmap image1(file1);
    QPixmap image2(file2);
    ui->image1->setPixmap(image1);
    ui->image2->setPixmap(image2);
}
