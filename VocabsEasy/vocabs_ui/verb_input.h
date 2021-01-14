#pragma once
#include <QWidget>
#include <verb.h>

class QLabel;
class QTableWidget;
class QPushButton;
class QGroupBox;

class VerbInput : public QWidget
{
Q_OBJECT
public:
    VerbInput(QWidget* parent= nullptr,const std::shared_ptr<VerbProcess> verbProcess={});
    void setLevel(int label);

signals:

    void startPractice();

public slots:
    void onVerbUpdate(const Verb& verb);
    void onIndexMax();
    void onNextClicked();
    void onBackClicked();
    void onPracticeClicked();
    void onRepeatClicked();

private:
    void setDefaultConjugationTable(QTableWidget* verbConjugation);
    void setConjugationTable(QTableWidget* verbConjugation,const Verb& verb);

    std::shared_ptr<VerbProcess> m_verbProcess;

    QGroupBox* m_row1{nullptr};
    QLabel* m_picture{nullptr};
    QLabel* m_verbName{nullptr};
    QLabel* m_caseType{nullptr};
    QLabel* m_type{nullptr};
    QLabel* m_subtype{nullptr};
    QLabel* m_englishMining{nullptr};
    QLabel* m_hindiMining{nullptr};
    QLabel* m_englishSentence{nullptr};
    QLabel* m_germanSentence{nullptr};
    QTableWidget* m_verbConjugation{nullptr};
    QPushButton* m_next{nullptr};
    QPushButton* m_back{nullptr};
    QPushButton* m_practice{nullptr};
    QPushButton* m_repeat{nullptr};
};