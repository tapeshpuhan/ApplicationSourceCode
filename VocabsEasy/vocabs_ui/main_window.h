#pragma once
#include <QWidget>
#include <verb_window.h>
class QPushButton;
class QComboBox;


class MainWindow : public QWidget
{
Q_OBJECT
public:
    MainWindow(QWidget* parent= nullptr);

public slots:

    void handelPaly();

private:
    QPushButton* m_play;
    QComboBox* m_vocabsTypes;
    QComboBox* m_labelTypes;
    std::unique_ptr<VerbWindow> m_verbWindow;
};