#include "create_button.h"
#include <QHBoxLayout>

CreateButton::CreateButton(QWidget* parent):QWidget(parent)
{
    setFixedSize(125,125);
}

void CreateButton::RegisterForSelectionType(UpdateButtonSelectionType&& handler)
{
    buttom_selection_ = std::move(handler);
}

void CreateButton::CreatePushButton()
{
    ref_push_button_ = new QPushButton("reference",this);
    rpu_push_button_ = new QPushButton("rpu",this);

    if( ref_push_button_ && rpu_push_button_)
    {
        QHBoxLayout *layout = new QHBoxLayout;
        ref_push_button_->setGeometry(10,10,80,30);
        rpu_push_button_->setGeometry(10,10,80,30);
        layout->addWidget(ref_push_button_);
        layout->addWidget(rpu_push_button_);
        setLayout(layout);
        connect(ref_push_button_, SIGNAL(released()),this,SLOT(ButtonReleasedForRef()));
        connect(rpu_push_button_, SIGNAL(released()),this,SLOT(ButtonReleasedForRpu()));
    }
}

void CreateButton::CreateRedioButton()
{
    ref_radio_button_ = new QRadioButton("ref", this);
    rpu_radio_button_ = new QRadioButton("rpu", this);

    if( ref_radio_button_ && rpu_radio_button_)
    {
        QHBoxLayout *layout = new QHBoxLayout;
        ref_radio_button_->setGeometry(10,10,80,30);
        rpu_radio_button_->setGeometry(10,10,80,30);
        layout->addWidget(ref_radio_button_);
        layout->addWidget(rpu_radio_button_);
        setLayout(layout);
        connect(ref_radio_button_, SIGNAL(clicked()),this,SLOT(ButtonReleasedForRef()));
        connect(rpu_radio_button_, SIGNAL(clicked()),this,SLOT(ButtonReleasedForRpu()));
    }
}

void CreateButton::ButtonReleasedForRef()
{
   qDebug()<<"ButtonReleasedForRef";
   if(nullptr != buttom_selection_)
   {
    buttom_selection_(ButtonSelectionType::kReference);
   }
}

void CreateButton::ButtonReleasedForRpu()
{
   qDebug()<<"ButtonReleasedForRpu";
   if(nullptr != buttom_selection_)
   {
    buttom_selection_(ButtonSelectionType::kRpu);
   }
}
