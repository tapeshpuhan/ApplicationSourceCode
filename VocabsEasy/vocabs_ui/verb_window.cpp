#include <verb_window.h>
#include <verb_practice.h>

VerbWindow::VerbWindow(QWidget *parent):QWidget(parent),
m_verbProcess{std::make_shared<VerbProcess>(this)}
{
    m_verbInput = std::make_shared<VerbInput>(parent,m_verbProcess);
    m_verbPractice = std::make_shared<VerbPractice>(parent,m_verbProcess);
    m_verbInput->hide();
    m_verbPractice->hide();

    connect(m_verbInput.get(),&VerbInput::startPractice,this,&VerbWindow::onPractice);
    connect(m_verbPractice.get(),&VerbPractice::goBack,this,&VerbWindow::onPracticeBack);
}

void VerbWindow::showInputWindow()
{
    m_verbInput->show();
}

void VerbWindow::onPractice()
{
    m_verbInput->hide();
    m_verbPractice->reset();
    m_verbPractice->show();
    m_verbProcess->random();
    m_verbProcess->nextPractice();
}

void VerbWindow::setLevel(int label)
{
    m_verbProcess->setLevel(label);
    m_verbProcess->next();
}

void VerbWindow::onPracticeBack()
{
    m_verbPractice->hide();
    m_verbProcess->repeat();
    m_verbInput->show();
}

