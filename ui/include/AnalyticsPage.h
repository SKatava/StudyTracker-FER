#ifndef ANALYTICSPAGE_CLASS_H
#define ANALYTICSPAGE_CLASS_H

#include <QWidget>
#include <QLabel>

class AnalyticsPage : public QWidget {
    Q_OBJECT
    
public:
    explicit AnalyticsPage(QWidget* parent = nullptr);

private:
    void setupUI();
    QLabel* titleLabel;
};

#endif
