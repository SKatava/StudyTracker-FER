#ifndef HOMEPAGE_CLASS_H
#define HOMEPAGE_CLASS_H

#include <QWidget>
#include <QLabel>

class HomePage : public QWidget {
    Q_OBJECT
    
public:
    explicit HomePage(QWidget* parent = nullptr);

private:
    void setupUI();
    QLabel* titleLabel;
};

#endif
