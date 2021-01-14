#include <verb_practice.h>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>
#include <QLineEdit>
#include <QComboBox>


VerbPractice::VerbPractice(QWidget* parent, const std::shared_ptr<VerbProcess> verbProcess):QWidget(parent),m_verbProcess(verbProcess)
{
    m_group = new QGroupBox(this);

    auto mainLayout = new QVBoxLayout(m_group);
    auto imageLayout = new QHBoxLayout(m_group);
    m_image = new QLabel(this);
    auto exampleLayout = new QVBoxLayout(m_group);
    m_sentence = new QLabel(this);
    m_germanSentence = new QLabel(this);
    m_english = new QLabel(this);
    m_hindi = new QLabel(this);
    exampleLayout->addWidget(m_sentence);
    exampleLayout->addWidget(m_germanSentence);
    exampleLayout->addWidget(m_english);
    exampleLayout->addWidget(m_hindi);

    imageLayout->addWidget(m_image);
    imageLayout->addLayout(exampleLayout);
    mainLayout->addLayout(imageLayout);
    m_enterAnswer = new QLineEdit(this);
    m_next = new QPushButton("Next",this);
    m_answer = new QPushButton("Answer",this);
    m_options = new QPushButton("Options",this);
    m_answerList = new QComboBox(this);

    auto infoLayout = new QHBoxLayout;
    infoLayout->addWidget(new QLabel("Answer:"));
    infoLayout->addWidget(m_enterAnswer);
    infoLayout->addWidget(m_answer);
    infoLayout->addWidget(m_next);
    infoLayout->addWidget(m_options);
    infoLayout->addWidget(m_answerList);

    mainLayout->addLayout(infoLayout);

    auto backLayout = new QHBoxLayout;
    m_back = new QPushButton("Back",this);
    m_repeat = new QPushButton("Repeat",this);
    backLayout->addWidget(m_back);
    backLayout->addWidget(m_repeat);
    mainLayout->addLayout(backLayout);
    m_progress = new QLabel( this);
    mainLayout->addWidget(m_progress);

    setLayout(mainLayout);



    connect(m_back,&QPushButton::clicked,this,&VerbPractice::onBackClicked);
    connect(m_repeat,&QPushButton::clicked,this,&VerbPractice::onRepeatClicked);
    connect(m_next,&QPushButton::clicked,this,&VerbPractice::onNextClicked);
    connect(m_answer,&QPushButton::clicked,this,&VerbPractice::onAnswerClicked);
    connect(m_options,&QPushButton::clicked,this,&VerbPractice::onOptionsClicked);

    connect(m_verbProcess.get(),&VerbProcess::updateVerb, this, &VerbPractice::onVerbUpdate);
    connect(m_verbProcess.get(),&VerbProcess::maxPracticeIndex, this, &VerbPractice::onIndexMax);
}

void VerbPractice::onBackClicked()
{
    emit goBack();
}

void VerbPractice::onAnswerClicked()
{
    if(m_enterAnswer->text().isEmpty())
    {
        m_enterAnswer->setText(m_verbProcess->getName());
    }
    else if(m_verbProcess->checkName(m_enterAnswer->text()))
    {
        m_germanSentence->setText(m_verbProcess->getGermanSentence());
        if(QMessageBox::information(this, QStringLiteral("Result "),QStringLiteral("Success")))
        {
            m_answerList->clear();
            m_enterAnswer->clear();
        }
    } else{
        QMessageBox::information(this, QStringLiteral("Result "),QStringLiteral("Failed : Try again"));
    }
}

void VerbPractice::onOptionsClicked()
{
    m_answerList->clear();
    m_answerList->addItems(m_verbProcess->getOptions());
}

void VerbPractice::onNextClicked()
{
    m_germanSentence->clear();
    m_progress->setText("Wait");
    m_verbProcess->nextPractice();
}

void VerbPractice::reset()
{
    m_enterAnswer->clear();
    m_image->clear();
    m_answerList->addItems(QStringList{});
}

void VerbPractice::onVerbUpdate(const Verb& verb)
{
    m_progress->setText("");
    m_image->clear();
    m_enterAnswer->clear();
    m_answerList->clear();

    m_image->updatesEnabled();
    m_image->setPixmap(QPixmap(verb.m_outputPath).scaled(300,300));
    m_image->update();

    m_sentence->clear();
    m_sentence->setText(verb.m_englishSentence);

    m_english->clear();
    m_english->setText(verb.m_englishMeaning);

    m_hindi->clear();
    m_hindi->setText(verb.m_hindiMeaning);
}

void VerbPractice::onIndexMax()
{
    m_progress->setText("");
    QMessageBox::information(this, QStringLiteral("Result "),QStringLiteral("Finished Practice, Repeat or Back"));
}

void VerbPractice::onRepeatClicked()
{
    m_verbProcess->repeatPractice();
    m_verbProcess->nextPractice();
}