#ifndef SESSIONSPAGE_CLASS_H
#define SESSIONSPAGE_CLASS_H

#include <QWidget>
#include <QLayout>

class SessionsPage : public QWidget {
    Q_OBJECT
    
public:
    explicit SessionsPage(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();

    
};

#endif
