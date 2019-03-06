#include "style_delegate.h"
#include "data_table_model.h"

void StyleDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    const DataTableModel* model = static_cast<const DataTableModel*>(index.model());

    model->SetEditorData(editor, index);
}

void StyleDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    DataTableModel* myModel = static_cast<DataTableModel*>(model);

    myModel->SetDataFromEditor(editor, index);
}
StyleDelegate::StyleDelegate(QObject* parent):QStyledItemDelegate(parent)
{

}
