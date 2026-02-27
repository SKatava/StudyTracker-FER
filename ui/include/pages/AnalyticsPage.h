#ifndef ANALYTICSPAGE_CLASS_H
#define ANALYTICSPAGE_CLASS_H

#include <QWidget>
#include <QLayout>

class AnalyticsPage : public QWidget {
    Q_OBJECT
    
public:
    explicit AnalyticsPage(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();

    
};

#endif
