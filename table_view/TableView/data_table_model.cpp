#include "data_table_model.h"
#include <QDebug>

DataTableModel::DataTableModel(std::vector<std::unique_ptr<DataTypes>>& data)
{
    data_type_list_ = std::move(data);
}
int DataTableModel::columnCount(const QModelIndex &parent) const
{
    if(data_type_list_.size() > 0)
        return data_type_list_[0]->GetColCount();
    return 0;
}

int DataTableModel::rowCount(const QModelIndex &parent) const
{
    return data_type_list_.size();
}

QVariant DataTableModel::headerData(int section, Qt::Orientation orientation,
                    int role) const
{
    QVariant data;

    qDebug()<<" colom header " <<data_type_list_[0]->GetColName(section);
    qDebug()<<"section "<<section;
    if(data_type_list_.size() != 0 && role == Qt::DisplayRole)
    {
        qDebug()<<" colom header " <<data_type_list_[0]->GetColName(section);
        qDebug()<<"section "<<section;
        data = data_type_list_[0]->GetColName(section);
    }
}

QVariant DataTableModel::data(const QModelIndex &index, int role ) const
{
    if(role == Qt::DisplayRole)
    {
        return data_type_list_[index.row()]->GetData(index.column());
    }
    return QVariant();
}

//editable flag
Qt::ItemFlags DataTableModel::flags(const QModelIndex &index) const
{
    if (!IndexIsValid(index))
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

bool DataTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (IndexIsValid(index) && role == Qt::EditRole)
    {
          data_type_list_[index.row()]->DataChanged(index.column(),value);
          emit dataChanged(index,index);
          return true;
    }
    return false;
}

bool DataTableModel::IndexIsValid(const QModelIndex & index) const
{
    return index.isValid() && index.row() < rowCount();
}

void DataTableModel::SetEditorData(QWidget *editor, const QModelIndex &index) const
{
    if (IndexIsValid(index))
        data_type_list_[index.row()]->SetEditorData(editor, index.column());
}

void DataTableModel::SetDataFromEditor(QWidget * editor, const QModelIndex & index)
{
    if (IndexIsValid(index))
        data_type_list_[index.row()]->SetDataFromEditor(editor, index.column());
}
