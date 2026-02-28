#ifndef TITLEBAR_CLASS_H
#define TITLEBAR_CLASS_H

#include <QFrame>
#include <QLayout>
#include <QPushButton>
#include <QLabel>

class Titlebar : public QFrame {
    Q_OBJECT

public:
    explicit Titlebar(QWidget* parent = nullptr);
private:
    void setupUI();
    void setupConnections();
    
    QHBoxLayout* layout;

    QPushButton* closeBtn;
    QPushButton* maximizeBtn;
    QPushButton* minimizeBtn;
    QLabel* title;
    QLabel* logo;
};

#endif
