#ifndef DATA_TABLE_MODEL_H
#define DATA_TABLE_MODEL_H

#include <QAbstractTableModel>
#include <memory>
#include <vector>
#include <QVariant>
#include "data_types.h"
#include <algorithm>
#include <QObject>

class DataTableModel : public QAbstractTableModel
{
  public:
    explicit DataTableModel(std::vector<std::unique_ptr<DataTypes>>& data);
    int columnCount(const QModelIndex &parent=QModelIndex()) const override;
    int rowCount(const QModelIndex &parent=QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role=Qt::DisplayRole) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    //editable flag
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole)override;

    void SetEditorData(QWidget *editor, const QModelIndex &index) const;
    void SetDataFromEditor(QWidget * editor, const QModelIndex & index);

private:
    bool IndexIsValid(const QModelIndex & index)const;
    std::vector<std::unique_ptr<DataTypes>> data_type_list_;
};


#endif // DATA_TABLE_MODEL_H
