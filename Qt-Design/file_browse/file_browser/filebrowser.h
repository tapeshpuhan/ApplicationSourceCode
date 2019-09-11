#ifndef FILEBROWSER_H
#define FILEBROWSER_H

#include <QMainWindow>
#include <QFileSystemModel>
namespace Ui {
class FileBrowser;
}

class FileBrowser : public QMainWindow
{
    Q_OBJECT

public:
    explicit FileBrowser(QWidget *parent = 0);
    ~FileBrowser();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::FileBrowser *ui;
    QFileSystemModel *file_model;
    QFileSystemModel *dir_model;
};

#endif // FILEBROWSER_H
