#ifndef ADDTASKFORM_CLASS_H
#define ADDTASKFORM_CLASS_H

#include <QWidget>
#include <QFrame>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>

#include <components/DatePickerEdit.h>

#include <core/services/AppContext.h>

class AddTaskForm : public QFrame {
    Q_OBJECT

public:
    explicit AddTaskForm(QWidget* parent);
private:
    void setupUI();
    void setupConnections();
    Task getTask() const;

    QVBoxLayout* layout;
    QHBoxLayout* buttonLayout;
    QHBoxLayout* inputLayout;
    QHBoxLayout* labelLayout;

    QPushButton* cancelBtn;
    QPushButton* confirmBtn;
    
    QComboBox* subjectList;
    
    DatePickerEdit* startDateInput;
    DatePickerEdit* endDateInput;

    QTextEdit* descInput;

};

#endif
