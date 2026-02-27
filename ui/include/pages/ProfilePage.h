#ifndef PROFILEPAGE_CLASS_H
#define PROFILEPAGE_CLASS_H

#include <QWidget>
#include <QLayout>

class ProfilePage : public QWidget {
    Q_OBJECT
    
public:
    explicit ProfilePage(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();

    
};

#endif
