#ifndef CREATE_BUTTON_H
#define CREATE_BUTTON_H
#include <QWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QDebug>
#include <functional>

enum class ButtonSelectionType : uint32_t
{
    kReference,
    kRpu
};

using UpdateButtonSelectionType = std::function<void(ButtonSelectionType)>;

class CreateButton : public QWidget
{
  Q_OBJECT
public:
    explicit CreateButton(QWidget *parent= 0);
    void CreatePushButton();
    void CreateRedioButton();
    void RegisterForSelectionType(UpdateButtonSelectionType&& handler);

public slots:
    void ButtonReleasedForRef();
    void ButtonReleasedForRpu();
private:

    QPushButton *ref_push_button_;
    QPushButton *rpu_push_button_;
    QRadioButton *ref_radio_button_;
    QRadioButton *rpu_radio_button_;
    UpdateButtonSelectionType buttom_selection_=nullptr;
};



#endif // CREATE_BUTTON_H
