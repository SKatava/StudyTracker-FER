#ifndef SUBJECTCARD_CLASS_H
#define SUBJECTCARD_CLASS_H

#include <QFrame>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>

class SubjectCard : public QFrame {
    Q_OBJECT

public:
    explicit SubjectCard(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();

    QVBoxLayout* layout;
    QLabel* subjectTitle;
    QLabel* ECTS;
    QLabel* percentage;
    QPushButton* startSessionBtn;


};

#endif
