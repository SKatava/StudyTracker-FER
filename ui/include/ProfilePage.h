#ifndef PROFILEPAGE_CLASS_H
#define PROFILEPAGE_CLASS_H

#include <QWidget>
#include <QLabel>

class ProfilePage : public QWidget {
    Q_OBJECT
    
public:
    explicit ProfilePage(QWidget* parent = nullptr);

private:
    void setupUI();
    QLabel* titleLabel;
};

#endif
