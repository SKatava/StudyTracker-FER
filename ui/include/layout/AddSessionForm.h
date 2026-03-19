#ifndef ADDSESSIONFORM_CLASS_H
#define ADDSESSIONFORM_CLASS_H

#include <QFrame>
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>

#include <components/DatePickerEdit.h>

#include <core/services/AppContext.h>

class AddSessionForm : public QFrame {
    Q_OBJECT

public:
    explicit AddSessionForm(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();
    Session getSession() const;

    QVBoxLayout* layout;
    QHBoxLayout* buttonLayout;
    QHBoxLayout* inputLayout;
    QHBoxLayout* labelLayout;

    QPushButton* cancelBtn;
    QPushButton* confirmBtn;
    
    QComboBox* subjectList;
    
    DatePickerEdit* dateInput;

    QTextEdit* descInput;

    QLineEdit* minutesInput;
    
};

#endif
