#ifndef SESSIONSPAGE_CLASS_H
#define SESSIONSPAGE_CLASS_H

#include <QWidget>
#include <QLayout>
#include <QStackedWidget>

#include <components/StudyTimer.h>
#include <components/SessionPageMenu.h>

class SessionsPage : public QWidget {
    Q_OBJECT
    
public:
    explicit SessionsPage(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();
       
    QVBoxLayout* layout;
    StudyTimer* timer;
    QWidget* history;
    QWidget* lectureCheckIn;
    SessionPageMenu* menu;
    

    QStackedWidget* pages;
    QMap<QString, QWidget*> pageMap;

private slots:
    void navigateToPage(const QString& page);
};

#endif
