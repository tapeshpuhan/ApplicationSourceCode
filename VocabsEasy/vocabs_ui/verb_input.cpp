#include <verb_input.h>
#include <QGroupBox>
#include <QLabel>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>

VerbInput::VerbInput(QWidget* parents,const std::shared_ptr<VerbProcess> verbProcess):QWidget{parents},m_verbProcess{verbProcess}
{
    m_row1 = new QGroupBox(this);

    m_verbName = new QLabel(this);
    m_caseType = new QLabel(this);
    m_type = new QLabel(this);
    m_subtype = new QLabel(this);
    auto infoLayout = new QHBoxLayout;
    infoLayout->addWidget(new QLabel("Name:"));
    infoLayout->addWidget(m_verbName);
    infoLayout->addWidget(new QLabel("Case:"));
    infoLayout->addWidget(m_caseType);
    infoLayout->addWidget(new QLabel("Type:"));
    infoLayout->addWidget(m_type);
    infoLayout->addWidget(new QLabel("Sub type:"));
    infoLayout->addWidget(m_subtype);

    m_picture = new QLabel;
    auto picLayout = new QHBoxLayout;
    picLayout->addWidget(m_picture);

    m_verbConjugation = new QTableWidget(this);
    m_verbConjugation->setColumnCount(4);
    m_verbConjugation->setRowCount(3);
    setDefaultConjugationTable(m_verbConjugation);

    auto row1Layout = new QVBoxLayout();
    row1Layout->addLayout(infoLayout);
    row1Layout->addLayout(picLayout);
    row1Layout->addWidget(m_verbConjugation);

    auto row2Layout = new QVBoxLayout();
    m_englishMining = new QLabel(this);
    m_hindiMining = new QLabel(this);
    m_englishSentence = new QLabel(this);
    m_germanSentence =new QLabel(this);

    auto layout1 = new QHBoxLayout;
    layout1->addWidget(new QLabel("English: "));
    layout1->addWidget(m_englishMining);
    row2Layout ->addLayout(layout1);

    auto layout2 = new QHBoxLayout;
    layout2->addWidget(new QLabel("Hindi: "));
    layout2->addWidget(m_hindiMining);
    row2Layout ->addLayout(layout2);

    auto layout3 = new QHBoxLayout;
    layout3->addWidget(new QLabel("Sentence: "));
    layout3->addWidget(m_englishSentence);
    row2Layout ->addLayout(layout3);

    auto layout4 = new QHBoxLayout;
    layout4->addWidget(new QLabel("satz: "));
    layout4->addWidget(m_germanSentence);
    row2Layout ->addLayout(layout4);

    auto bottomLayout = new QHBoxLayout;
    m_next = new QPushButton("Next",this);
    m_back = new QPushButton("Back",this);
    m_practice = new QPushButton("Practice",this);
    m_repeat = new QPushButton("repeat",this);
    bottomLayout->addWidget(m_next);
    bottomLayout->addWidget(m_back);
    bottomLayout->addWidget(m_practice);
    bottomLayout->addWidget(m_repeat);
    row2Layout->addLayout(bottomLayout);

    auto rootLayout = new QVBoxLayout(m_row1);
    rootLayout->addLayout(row1Layout);
    rootLayout->addLayout(row2Layout);

    connect(m_verbProcess.get(),&VerbProcess::updateVerb, this, &VerbInput::onVerbUpdate);
    connect(m_verbProcess.get(),&VerbProcess::maxIndex, this, &VerbInput::onIndexMax);
    connect(m_next,&QPushButton::clicked, this, &VerbInput::onNextClicked);
    connect(m_back,&QPushButton::clicked, this, &VerbInput::onBackClicked);
    connect(m_practice,&QPushButton::clicked, this, &VerbInput::onPracticeClicked);
    connect(m_repeat,&QPushButton::clicked, this, &VerbInput::onRepeatClicked);

    setLayout(rootLayout);
}

void VerbInput::setDefaultConjugationTable(QTableWidget* verbConjugation)
{
    verbConjugation->setItem(0,0,new QTableWidgetItem("Ich"));
    verbConjugation->setItem(1,0,new QTableWidgetItem("Du"));
    verbConjugation->setItem(2,0,new QTableWidgetItem("Es/Er/sie"));

    verbConjugation->setItem(0,2,new QTableWidgetItem("Wir"));
    verbConjugation->setItem(1,2,new QTableWidgetItem("Ihr"));
    verbConjugation->setItem(2,2,new QTableWidgetItem("sie/Sie"));
}

void VerbInput::setConjugationTable(QTableWidget* verbConjugation,const Verb& verb)
{
    verbConjugation->setItem(0,1,new QTableWidgetItem(verb.m_ichName));
    verbConjugation->setItem(1,1,new QTableWidgetItem(verb.m_duName));
    verbConjugation->setItem(2,1,new QTableWidgetItem(verb.m_erName));

    verbConjugation->setItem(0,3,new QTableWidgetItem(verb.m_wirName));
    verbConjugation->setItem(1,3,new QTableWidgetItem(verb.m_ihrName));
    verbConjugation->setItem(2,3,new QTableWidgetItem(verb.m_sieName));
}


void VerbInput::onVerbUpdate(const Verb& verb)
{
    m_picture->clear();
    m_picture->updatesEnabled();
    m_picture->setPixmap(QPixmap(verb.m_inputPath).scaled(300,300));
    m_picture->update();

    m_verbName->clear();
    m_verbName->setText(verb.m_name);

    m_caseType->clear();
    m_caseType->setText(verb.m_caseType);

    m_type->clear();
    m_type->setText(verb.m_type);

    m_subtype->clear();
    m_subtype->setText(verb.m_subType);

    m_englishMining->clear();
    m_englishMining->setText(verb.m_englishMeaning);

    m_hindiMining->clear();
    m_hindiMining->setText(verb.m_hindiMeaning);

    m_englishSentence->clear();
    m_englishSentence->setText(verb.m_englishSentence);

    m_germanSentence->clear();
    m_germanSentence->setText(verb.m_germanSentence);

    setConjugationTable(m_verbConjugation,verb);
}

void VerbInput::onNextClicked()
{
    m_verbProcess->next();
}

void VerbInput::onBackClicked()
{
    m_verbProcess->back();
}

void VerbInput::onPracticeClicked()
{
    emit startPractice();
}

void VerbInput::onRepeatClicked()
{
    m_verbProcess->repeat();
}

void VerbInput::onIndexMax()
{
    QMessageBox::information(this, QStringLiteral("Next Step"),QStringLiteral("Finished , Please Repeat or Practice"));
}