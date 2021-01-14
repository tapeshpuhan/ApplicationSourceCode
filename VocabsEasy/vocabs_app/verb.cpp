#include <verb.h>
#include <algorithm>
#include <get_resource_information.h>
#include <QDebug>

VerbProcess::VerbProcess(QObject* parent):QObject(parent)
{
    auto resourceObject = std::make_unique<GetResourceInformation>();
    m_verbList = resourceObject->getVerbInformation();
}

void VerbProcess::setLevel(quint8 level)
{
    m_verbTestList.clear();
    m_verbTestList.reserve(m_verbList.size());

    std::copy_if(m_verbList.begin(),m_verbList.end(),std::back_inserter(m_verbTestList),
                [this,level](const auto& verb) {
        return verb.m_level == level;});

    m_verbTestList.reserve(m_verbTestList.size());
    for(const auto& options : m_verbTestList)
    {
        m_verbOptions.push_back(options.m_name);
    }
}

void VerbProcess::next()
{
    if(m_index < m_verbTestList.size())
    {
        emit updateVerb(m_verbTestList.at(m_index));
        m_index++;
    } else
    {
        emit maxIndex();
    }
}

void VerbProcess::back()
{
    if(m_index > 0)
    {
        emit updateVerb(m_verbTestList.at(m_index-1));
        m_index--;
    } else
    {
        emit updateVerb(m_verbTestList.at(0));
    }
}

void VerbProcess::repeat()
{
    m_index = 0;
    next();
}

void VerbProcess::nextPractice()
{
    if(m_randomIndex < indexRecord.size())
    {
        emit updateVerb(m_verbTestList.at(indexRecord.at(m_randomIndex)));
        m_randomIndex++;
    } else{
        emit maxPracticeIndex();
    }
}

bool VerbProcess::checkName(const QString& verbName)
{
    return verbName == m_verbTestList.at(indexRecord.at(m_randomIndex-1)).m_name;
}

QString VerbProcess::getName()const
{
    return m_verbTestList.at(indexRecord.at(m_randomIndex-1)).m_name;
}

QString VerbProcess::getGermanSentence()const
{
    return m_verbTestList.at(indexRecord.at(m_randomIndex-1)).m_germanSentence;
}
QStringList VerbProcess::getOptions()const
{
    return m_verbOptions;
}

void VerbProcess::repeatPractice()
{
    m_randomIndex = 0;
    random();
}

void VerbProcess::random()
{
    if(indexRecord.size() < m_index)
    {
        indexRecord.reserve(m_index);
        for(size_t index = 0; index < m_index; index++)
        {
            indexRecord.push_back(index);
        }
    }
    std::random_shuffle(indexRecord.begin(),indexRecord.end());
}