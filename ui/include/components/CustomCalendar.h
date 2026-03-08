#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QDate>

class CustomCalendar : public QWidget {
    Q_OBJECT
public:
    CustomCalendar(QWidget* parent = nullptr);
    QDate selectedDate() const { return currentDate; }

signals:
    void dateSelected(QDate);

private:
    QGridLayout* grid;
    QPushButton *prevMonth, *nextMonth;
    QLabel* currentMonthLabel;
    QDate currentDate;

    void setupUI();
    void setupConnections();

    void displayMonth(QDate date);
    void prevMonthClicked();
    void nextMonthClicked();
};
