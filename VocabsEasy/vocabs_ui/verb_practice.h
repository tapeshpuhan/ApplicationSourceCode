#pragma once
#include <QWidget>
#include <verb.h>
class QLabel;
class QGroupBox;
class QLineEdit;
class QComboBox;
class QPushButton;

class VerbPractice : public QWidget
{
Q_OBJECT
public:
    VerbPractice(QWidget* parent= nullptr,const std::shared_ptr<VerbProcess> verbProcess={});
    void reset();

signals:

    void goBack();

public slots:
    void onBackClicked();
    void onRepeatClicked();
    void onAnswerClicked();
    void onOptionsClicked();
    void onNextClicked();

    void onVerbUpdate(const Verb& verb);
    void onIndexMax();

private:

    std::shared_ptr<VerbProcess> m_verbProcess;

    QGroupBox* m_group;
    QLabel* m_image;
    QLineEdit* m_enterAnswer;
    QComboBox* m_answerList;
    QPushButton* m_next;
    QPushButton* m_answer;
    QPushButton* m_options;
    QPushButton* m_back;
    QPushButton* m_repeat;
    QLabel* m_progress;
};