#ifndef SESSIONCARD_CLASS_H
#define SESSIONCARD_CLASS_H

#include <QFrame>
#include <QWidget>
#include <QLayout>

#include <QLabel>

#include <core/domain/Session.h>

class SessionCard : public QFrame {
    Q_OBJECT

public:
    SessionCard(QWidget* parent, const Session& session);

private:
    void setupUI(const Session& session);
    void setupConnections();

    QHBoxLayout* layout;
    QVBoxLayout* infoLayout;

    QLabel* subjectName;
    QLabel* description;
    QLabel* date;
    QLabel* duration;

    QLabel* icon;
};

#endif
