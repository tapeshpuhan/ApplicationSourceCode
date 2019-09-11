#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_select_file_first_clicked();

    void on_select_file_first_2_clicked();

    void on_load_clicked();

private:
    Ui::MainWindow *ui;
    QString file1;
    QString file2;
};

#endif // MAINWINDOW_H
