#ifndef DASHBOARDPAGE_CLASS_H
#define DASHBOARDPAGE_CLASS_H

#include <QWidget>
#include <QLayout>

class DashboardPage : public QWidget {
    Q_OBJECT
    
public:
    explicit DashboardPage(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();

    
};

#endif
