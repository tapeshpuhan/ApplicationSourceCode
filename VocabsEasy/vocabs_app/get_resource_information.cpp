#include <get_resource_information.h>
#include <QDebug>

static  QString VerbJsonPath{"resource/verbs/verbs.json"};
static  QString VerbInputPath{"resource/verbs/input/"};
static  QString VerbPracticePath{"resource/verbs/practice/"};

QVector<Verb> GetResourceInformation::getVerbInformation()
{
    QVector<Verb> verbs;
    std::optional<QJsonObject> object = loadPath(VerbJsonPath);

    if(object.has_value())
    {
        QJsonObject values = object.value();
        verbs.reserve(values.size());

        for(const auto& value : values)
        {
            Verb verb;

            verb.m_name = value.toObject().value("name").toString();
            verb.m_type = value.toObject().value("type").toString();
            verb.m_subType = value.toObject().value("sub_type").toString();
            verb.m_caseType = value.toObject().value("case_type").toString();
            verb.m_level = value.toObject().value("level").toString().toInt();
            verb.m_baseName = value.toObject().value("base").toString();

            if(verb.m_type == QStringLiteral("irregular"))
            {
                verb.m_ichName = value.toObject().value("ich").toString();
                verb.m_duName = value.toObject().value("du").toString();
                verb.m_erName = value.toObject().value("er").toString();
            } else{
                verb.m_ichName = verb.m_baseName+QStringLiteral("e");
                verb.m_duName = verb.m_baseName+QStringLiteral("st");
                verb.m_erName = verb.m_baseName+QStringLiteral("t");
            }
            verb.m_wirName = verb.m_name;
            verb.m_ihrName = verb.m_baseName+QStringLiteral("t");
            verb.m_sieName = verb.m_name;
            verb.m_englishMeaning = value.toObject().value("english").toString();
            verb.m_hindiMeaning = value.toObject().value("hindi").toString();
            verb.m_odiaMeaning = value.toObject().value("Odia").toString();
            verb.m_englishSentence = value.toObject().value("sentence").toString();
            verb.m_germanSentence = value.toObject().value("satz").toString();
            verb.m_inputPath = VerbInputPath+verb.m_name+".jpg";
            verb.m_outputPath = VerbPracticePath+verb.m_name+".jpg";

            verbs.push_back(verb);
        }
    }

    return verbs;
}

std::optional<QJsonObject> GetResourceInformation::loadPath(const QString& path)
{
    QFile loadFile(path);

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
    } else{
        auto readAll = loadFile.readAll();
        return QJsonDocument::fromJson(readAll).object();
    }
    return {};
}


