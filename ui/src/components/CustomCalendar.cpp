#include <components/CustomCalendar.h>

CustomCalendar::CustomCalendar(QWidget* parent) : QWidget(parent) {
    setupUI();
    setupConnections();
}

void CustomCalendar::setupUI() {
    this->setObjectName("calendar");
    setWindowFlags(Qt::Popup);   
    grid = new QGridLayout(this);
    grid->setSpacing(2);
    grid->setContentsMargins(4,4,4,4);

    QStringList weekdays = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
    for (int i=0;i<7;i++) {
        QLabel* label = new QLabel(weekdays[i]);
        label->setAlignment(Qt::AlignCenter);
        grid->addWidget(label, 1, i);
    }

    prevMonth = new QPushButton("<");
    nextMonth = new QPushButton(">");
    prevMonth->setObjectName("calendarBtn");
    nextMonth->setObjectName("calendarBtn");
    prevMonth->setFlat(false);
    prevMonth->setFixedSize(30, 30);
    nextMonth->setFixedSize(30, 30);

    QLabel* monthLabel = new QLabel();
    monthLabel->setAlignment(Qt::AlignCenter);
    currentMonthLabel = monthLabel;

    grid->addWidget(prevMonth, 0, 0, 1, 1);
    grid->addWidget(monthLabel, 0, 1, 1, 5);
    grid->addWidget(nextMonth, 0, 6, 1, 1);

    currentDate = QDate::currentDate();
    displayMonth(currentDate);
}

void CustomCalendar::setupConnections() {
    connect(prevMonth, &QPushButton::clicked, this, &CustomCalendar::prevMonthClicked);
    connect(nextMonth, &QPushButton::clicked, this, &CustomCalendar::nextMonthClicked);
}

void CustomCalendar::displayMonth(QDate date) {

    // Remove old day widgets
    for(int i = grid->count() - 1; i >= 10; --i) {
        QLayoutItem* item = grid->takeAt(i);
        if(item) {
            delete item->widget();
            delete item;
        }
    }

    currentMonthLabel->setText(date.toString("MMMM yyyy"));

    QDate first(date.year(), date.month(), 1);
    int startCol = first.dayOfWeek() - 1;
    int daysInMonth = first.daysInMonth();

    int day = 1;

    for(int row = 2; row < 8; row++) {
        for(int col = 0; col < 7; col++) {

            QWidget* cell = nullptr;

            if(row == 2 && col < startCol) {
                cell = new QWidget(); 
                cell->setFixedSize(36,36);
            }
            else if(day > daysInMonth) {
                cell = new QWidget(); 
                cell->setFixedSize(36,36);
            }
            else {
                QPushButton* btn = new QPushButton(QString::number(day));
                btn->setObjectName("calendarBtn");
                btn->setFixedSize(36,36);

                connect(btn, &QPushButton::clicked, [this, date, day]() {
                        currentDate = QDate(date.year(), date.month(), day);
                        emit dateSelected(currentDate);
                        hide();
                        });

                cell = btn;
                day++;
            }

            grid->addWidget(cell, row, col);
        }
    }
}

void CustomCalendar::prevMonthClicked() {
    currentDate = currentDate.addMonths(-1);
    displayMonth(currentDate);
}

void CustomCalendar::nextMonthClicked() {
    currentDate = currentDate.addMonths(1);
    displayMonth(currentDate);
}

