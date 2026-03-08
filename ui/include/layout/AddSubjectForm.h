#ifndef ADDSUBJECTFORM_CLASS_H
#define ADDSUBJECTFORM_CLASS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>

#include <components/DatePickerEdit.h>

#include <core/domain/Subject.h>

class AddSubjectForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddSubjectForm(QWidget* parent = nullptr);

    Subject getSubject() const;

private:
    void setupUI();
    void setupConnections();

    QLabel* title;
    QLabel* description;
    QLabel* nameLabel;
    QLabel* ECTSLabel;
    QLabel* lectureHoursLabel;
    QLabel* dateLabel;
    QLineEdit* nameInput;
    QLineEdit* ECTSInput;
    QLineEdit* LectureHoursInput;
    DatePickerEdit* dateInput;
    QVBoxLayout* layout;
    QHBoxLayout* inputLayout;
    QHBoxLayout* labelLayout;
    QHBoxLayout* buttonLayout;
    QPushButton* addBtn;
    QPushButton* cancelBtn;
signals:
    void subjectCreated(QString name);

};

#endif
