#include "employee_data.h"

EmployeeData::EmployeeData(const QString& name, const uint32_t number , const uint32_t salary) :
    emp_name_{name},
    emp_num_{number},
    emp_salary_{salary}
{

}

QVariant EmployeeData::GetData(const uint32_t col_index)
{
    QVariant data;
    switch(static_cast<colomn_type>(col_index))
    {
    case colomn_type::emp_name:
        data = emp_name_;
    break;
    case colomn_type::emp_num:
        data = emp_num_;
        break;
    case colomn_type::emp_salary:
        data = emp_salary_;
        break;
    default:
        break;
    }
    return data;
}

uint32_t EmployeeData::GetColCount()
{
    return col_count_;
}
bool EmployeeData::GetEditable(const uint32_t col_index)
{
    bool data;
    switch(static_cast<colomn_type>(col_index))
    {
    case colomn_type::emp_name:
        data = false;
    break;
    case colomn_type::emp_num:
        data = false;
        break;
    case colomn_type::emp_salary:
        data = true;
        break;
    default:
        break;
    }
    return data;
}

QString EmployeeData::GetColName(const uint32_t col_index)
{
    QString data;
    switch(static_cast<colomn_type>(col_index))
    {
    case colomn_type::emp_name:
        data = QString("Emp Name");
    break;
    case colomn_type::emp_num:
        data = QString("Emp number");
        break;
    case colomn_type::emp_salary:
        data = QString("Emp Salary");
        break;
    default:
        break;
    }
    return data;
}

void EmployeeData::DataChanged(const uint32_t& col_index, const QVariant& value)
{
    switch(static_cast<colomn_type>(col_index))
    {
    case colomn_type::emp_name:
        emp_name_ = value.toString();
    break;
    case colomn_type::emp_num:
        emp_num_ = value.toUInt();
        break;
    case colomn_type::emp_salary:
        emp_salary_ = value.toUInt();
        break;
    default:
        break;
    }
}

void EmployeeData::SetEditorData(QWidget *editor, const int & column) const
{
    switch(static_cast<colomn_type>(column))
    {
        case colomn_type::emp_name:
    {
        QLineEdit * lineEdit = static_cast<QLineEdit *>(editor);

        lineEdit->setText(emp_name_);
    }
            break;
        case colomn_type::emp_num:
    {
            QSpinBox * spinBox = static_cast<QSpinBox *>(editor);
            spinBox->setValue(emp_num_);
    }
            break;
        case colomn_type::emp_salary:
    {
            QSpinBox * spinBox = static_cast<QSpinBox *>(editor);
            spinBox->setValue(emp_salary_);
    }
            break;
        default:
            break;
    }
}

void EmployeeData::SetDataFromEditor(QWidget * editor, const int column)
{
    switch(static_cast<colomn_type>(column))
    {
        case colomn_type::emp_name:
            {
            QLineEdit * lineEdit = static_cast<QLineEdit *>(editor);
            lineEdit->setText(emp_name_);
            DataChanged(column, lineEdit->text());
            break;
            }
        case colomn_type::emp_num:
            {
            QSpinBox * spinBox = static_cast<QSpinBox *>(editor);
            spinBox->setValue(emp_num_);
            DataChanged(column, spinBox->value());
            break;
            }
        case colomn_type::emp_salary:
            {
            QSpinBox * spinBox = static_cast<QSpinBox *>(editor);
            spinBox->setValue(emp_salary_);
            DataChanged(column, spinBox->value());
            break;
            }
        default:
            {
            break;
            }
    }
}
