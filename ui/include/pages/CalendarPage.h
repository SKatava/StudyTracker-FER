#ifndef CALENDARPAGE_CLASS_H
#define CALENDARPAGE_CLASS_H

#include <QWidget>
#include <QLayout>

class CalendarPage : public QWidget {
    Q_OBJECT
    
public:
    explicit CalendarPage(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();

    
};

#endif
