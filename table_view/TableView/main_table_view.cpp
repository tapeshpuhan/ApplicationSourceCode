#include<QApplication>
#include<QTableView>
#include "data_table_model.h"
#include "employee_data.h"
#include "style_delegate.h"
#include <vector>
#include <iostream>
#include <QVBoxLayout>
#include <QWidget>
#include <QItemEditorFactory>
#include <QHeaderView>
#include <QLineEdit>
#include <QSpinBox>
#include <QStandardItemEditorCreator>
#include <QtWidgets/QApplication>

void ChangeQItemEditorFactory()
{
    QItemEditorFactory * factory = new QItemEditorFactory;

    QItemEditorCreatorBase * stringEditor = new QStandardItemEditorCreator<QLineEdit>();
    factory->registerEditor(QVariant::String, stringEditor);

    QItemEditorCreatorBase * intEditor = new QStandardItemEditorCreator<QSpinBox>();
    factory->registerEditor(QVariant::Int, intEditor);

    QItemEditorFactory::setDefaultFactory(factory);
}

int main(int argc, char** argv)
{
    QApplication app(argc,argv);

    std::vector<std::unique_ptr<DataTypes>> collect_data;


    collect_data.push_back(std::make_unique<EmployeeData>("shiva", 1,200));
    collect_data.push_back(std::make_unique<EmployeeData>("Sam", 1,200));
    collect_data.push_back(std::make_unique<EmployeeData>("ram", 1,200));
    collect_data.push_back(std::make_unique<EmployeeData>("dadu ", 1,200));
    collect_data.push_back(std::make_unique<EmployeeData>("madhu", 1,200));

    DataTableModel model(collect_data);

    QTableView table;
    QVBoxLayout layout;

    table.setModel(&model);
    layout.addWidget(&table);

    StyleDelegate delegate(&table);
    table.setItemDelegate(&delegate);
ChangeQItemEditorFactory();
    table.show();
    return app.exec();
}


