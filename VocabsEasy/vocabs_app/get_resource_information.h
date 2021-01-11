#pragma once
#include "vocabs_data.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <optional>

class GetResourceInformation
{
public:
    GetResourceInformation()=default;
    ~GetResourceInformation()=default;

    QVector<Verb> getVerbInformation();

private:
    std::optional<QJsonObject> loadPath(const QString& path);
};