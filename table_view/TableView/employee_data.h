#ifndef EMPLOYEE_DATA_H
#define EMPLOYEE_DATA_H

#include "data_types.h"
#include <QString>
#include <QLineEdit>
#include <QSpinBox>

enum class colomn_type
{
  emp_name,
  emp_num,
  emp_salary
};

class EmployeeData : public DataTypes
{

public:
    explicit EmployeeData(const QString& name,
                          const uint32_t number , const uint32_t salary);
    QVariant GetData(const uint32_t col_index)override;
    uint32_t GetColCount()override;
    bool GetEditable(const uint32_t col_index)override;
    QString GetColName(const uint32_t col_index)override;
    void DataChanged(const uint32_t& col_index, const QVariant& value)override;

    void SetEditorData(QWidget *editor, const int & column) const override;

    void SetDataFromEditor(QWidget * editor, const int column) override;

private:

    const uint8_t col_count_ = 3;
    QString emp_name_;
    uint32_t emp_num_;
    uint32_t emp_salary_;
};

#endif // EMPLOYEE_DATA_H
