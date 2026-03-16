#include <components/DatePickerEdit.h>

DatePickerEdit::DatePickerEdit(QWidget* parent) : QWidget(parent) {
    setupUI();
    setupConnections();
}

void DatePickerEdit::setupUI() {
    layout = new QHBoxLayout(this);
    edit = new QLineEdit(this);
    calendar = new CustomCalendar(this);
    openCalendarBtn = new QPushButton("▼");
    
    edit->setReadOnly(true);
    edit->setFixedHeight(40);
    edit->setPlaceholderText("YYYY-MM-DD");

    openCalendarBtn->setFixedSize(24,24);

    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(edit);
    layout->addWidget(openCalendarBtn);


}

void DatePickerEdit::setupConnections() {
    connect(openCalendarBtn, &QPushButton::clicked, [this](){
        calendar->move(mapToGlobal(QPoint(0,height()))); 
        calendar->show();
    });

    connect(calendar, &CustomCalendar::dateSelected, [this](QDate d){
        edit->setText(d.toString("yyyy-MM-dd"));
    });

}

QDate DatePickerEdit::date() const { 
    return QDate::fromString(edit->text(),"yyyy-MM-dd"); 
}

