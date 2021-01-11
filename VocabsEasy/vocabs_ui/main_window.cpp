#include <main_window.h>
#include <QPushButton>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>

const QStringList VocabNames{QStringLiteral("Verbs"), QStringLiteral("Nouns"), QStringLiteral("Preposition"),
                             QStringLiteral("Adverb"),QStringLiteral("Adjective"),QStringLiteral("Case System")};

const QStringList LabelNames{QStringLiteral("Label 1"), QStringLiteral("Label 2"), QStringLiteral("Label 3"),
                             QStringLiteral("Label 4"),QStringLiteral("Label 5"),QStringLiteral("Label 6")};

MainWindow::MainWindow(QWidget* parent):QWidget(parent),m_verbWindow{std::make_unique<VerbWindow>(parent)}
{
    auto layout = new  QHBoxLayout(this);

    m_play = new QPushButton("Play");
    m_vocabsTypes = new QComboBox(this);
    m_labelTypes = new QComboBox(this);
    m_vocabsTypes->addItems(VocabNames);
    m_labelTypes->addItems(LabelNames);
    layout->addWidget(m_vocabsTypes);
    layout->addWidget(m_labelTypes);
    layout->addWidget(m_play);

    m_verbWindow->hide();

    connect(m_play,&QPushButton::clicked,this, &MainWindow::handelPaly);
    resize(100,200);
}

void MainWindow::handelPaly()
{
    qDebug()<<"handelPaly";
    if(m_vocabsTypes->currentText() == QString("Verbs"))
    {
        if(!m_verbWindow->isVisible())
        {
            m_verbWindow->showInputWindow();
            m_verbWindow->setLevel(m_labelTypes->currentIndex()+1);
        }
    }
}