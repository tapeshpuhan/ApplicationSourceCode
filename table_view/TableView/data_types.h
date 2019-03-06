#ifndef DATA_TYPES_H
#define DATA_TYPES_H

#include <QVariant>
#include <QString>
#include <cstdint>

struct DataTypes
{
  virtual QVariant GetData(const uint32_t col_index) = 0;
  virtual uint32_t GetColCount() = 0;
  virtual bool GetEditable(const uint32_t col_index)=0;
  virtual QString GetColName(const uint32_t col_index) = 0;
  virtual void DataChanged(const uint32_t& col_index, const QVariant& value) = 0;
  virtual void SetEditorData(QWidget *editor, const int & column) const = 0;
  virtual void SetDataFromEditor(QWidget * editor, int column) = 0;

};


#endif // DATA_TYPES_H
