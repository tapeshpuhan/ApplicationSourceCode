#pragma once
#include <QWidget>
#include <verb_input.h>
class VerbInput;
class VerbPractice;

class VerbWindow : public QWidget
{
    Q_OBJECT
public:
    VerbWindow(QWidget* parent= nullptr);
    void showInputWindow();
    void setLevel(int label);

public slots:
    void onPractice();
    void onPracticeBack();

private:

    std::shared_ptr<VerbProcess> m_verbProcess;
    std::shared_ptr<VerbInput> m_verbInput;
    std::shared_ptr<VerbPractice> m_verbPractice;
};