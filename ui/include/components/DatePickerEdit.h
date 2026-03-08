#ifndef DATEPICKEREDIT_CLASS_H
#define DATEPICKEREDIT_CLASS_H

#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDate>

#include <components/CustomCalendar.h>

class DatePickerEdit : public QWidget {
    Q_OBJECT
public:
    DatePickerEdit(QWidget* parent=nullptr);    
    QDate date() const;

private:
    QHBoxLayout* layout;
    QLineEdit* edit;
    CustomCalendar* calendar;
    QPushButton* openCalendarBtn;

    void setupUI();
    void setupConnections();
};

#endif
