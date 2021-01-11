#include <verb.h>
#include <algorithm>
#include <get_resource_information.h>
#include <QDebug>

static int generateIndex(int start, int end)
{
    /* initialize random seed: */
    srand (time(NULL));

    /* generate secret number between 1 and 10: */
    return rand() % end + start;
}

VerbProcess::VerbProcess(QObject* parent):QObject(parent)
{
    auto resourceObject = std::make_unique<GetResourceInformation>();
    m_verbList = resourceObject->getVerbInformation();
    qDebug()<<"m_verbList size "<<m_verbList.size();
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

void VerbProcess::repeat()
{
    m_index = 0;
    next();
}

void VerbProcess::nextPractice()
{
    if(m_index && (indexRecord.size() < m_index))
    {
        while(1)
        {
            auto index = generateIndex(0,m_index);
            auto insertResult = indexRecord.insert(index);

            if(insertResult.second)
            {
                m_randomIndex = index;
                emit updateVerb(m_verbTestList.at(m_randomIndex));
                break;
            }
            if(indexRecord.size() >= m_index)
                break;
        }
    } else{
        emit maxPracticeIndex();
    }
}

bool VerbProcess::checkName(const QString& verbName)
{
    return verbName == m_verbTestList.at(m_randomIndex).m_name;
}

QStringList VerbProcess::getOptions()const
{
    return m_verbOptions;
}

void VerbProcess::repeatPractice()
{
    m_randomIndex = 0;
    indexRecord.clear();
}