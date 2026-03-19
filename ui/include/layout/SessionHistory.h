#ifndef SESSIONHISTORY_CLASS_H
#define SESSIONHISTORY_CLASS_H

#include <vector>

#include <QWidget>
#include <QLayout>
#include <QScrollArea>

#include <components/SessionCard.h>
#include <components/SessionHistoryMenu.h>
#include <layout/AddSessionForm.h>


class SessionHistory : public QWidget {
    Q_OBJECT

public:
    SessionHistory(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();

private slots:
    void onFilterApplied(QString name);
    void onOpenSessionForm();

private:
    SessionHistoryMenu* menu;

    QVBoxLayout* layout;
    QScrollArea* scroll;

    QWidget* container;
    QVBoxLayout* containerLayout;

    AddSessionForm* sessionForm;

    std::vector<SessionCard*> cards;  
};

#endif
