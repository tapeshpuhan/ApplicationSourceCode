#ifndef STYLE_DELEGATE_H
#define STYLE_DELEGATE_H
#include <QWidget>
#include <QStyledItemDelegate>

class StyleDelegate : public QStyledItemDelegate
{
public:
    explicit StyleDelegate(QObject* parent = 0);
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;
};

#endif // STYLE_DELEGATE_H
