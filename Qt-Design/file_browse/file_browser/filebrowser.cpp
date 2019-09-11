#include "filebrowser.h"
#include "ui_filebrowser.h"
#include<QDebug>
FileBrowser::FileBrowser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FileBrowser)
{
    ui->setupUi(this);
    file_model = new QFileSystemModel(this);
    file_model->setFilter(QDir::NoDotAndDotDot|QDir::Files);
    file_model->setRootPath("/home");
    ui->listView->setModel(file_model);

    dir_model = new QFileSystemModel(this);
    dir_model->setFilter(QDir::NoDotAndDotDot|QDir::Dirs);
    dir_model->setRootPath("/home");
    ui->treeView->setModel(dir_model);
    connect(ui->treeView,&QTreeView::clicked,this,&FileBrowser::on_treeView_clicked);
}

FileBrowser::~FileBrowser()
{
    delete ui;
}

void FileBrowser::on_treeView_clicked(const QModelIndex &index)
{
    qDebug()<<"Qtree view is clicked "<<index.data(Qt::DisplayRole)<<" : "<<index.row()<<index.column()<<index.parent();
    QString path = dir_model->fileInfo(index).absoluteFilePath();
    qDebug()<<path;
    ui->listView->setRootIndex(file_model->setRootPath(path));
}

void FileBrowser::on_listView_clicked(const QModelIndex &index)
{

}
