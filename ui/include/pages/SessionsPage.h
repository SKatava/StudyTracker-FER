#ifndef SESSIONSPAGE_CLASS_H
#define SESSIONSPAGE_CLASS_H

#include <QWidget>
#include <QLayout>
#include <QStackedWidget>

#include <components/StudyTimer.h>
#include <components/SessionPageMenu.h>
#include <components/SessionCard.h>
#include <layout/SessionHistory.h>

class SessionsPage : public QWidget {
    Q_OBJECT
    
public:
    explicit SessionsPage(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();
       
    QVBoxLayout* layout;
    StudyTimer* timer;
    SessionHistory* history;
    QWidget* lectureCheckIn;
    SessionPageMenu* menu;
    
    SessionCard* card;

    QStackedWidget* pages;
    QMap<QString, QWidget*> pageMap;

private slots:
    void navigateToPage(const QString& page);
};

#endif
