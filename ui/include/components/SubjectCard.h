#ifndef SUBJECTCARD_CLASS_H
#define SUBJECTCARD_CLASS_H

#include <QFrame>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>

#include <core/domain/Subject.h>
#include <QLineEdit>

class SubjectCard : public QFrame {
    Q_OBJECT

public:
    explicit SubjectCard(QWidget* parent = nullptr, const Subject& subject = Subject());

private:
    void setupUI(const Subject& subject);
    void setupConnections();

    QVBoxLayout* layout;
    QHBoxLayout* bottomLayout;
    QLabel* subjectTitle;
    QLabel* ECTS;
    QLabel* percentage;
    QLabel* lecture;
    QPushButton* startSessionBtn;
    QPushButton* checkInBtn;
    QLineEdit* hoursInput;

    int subjectId;


};

#endif
