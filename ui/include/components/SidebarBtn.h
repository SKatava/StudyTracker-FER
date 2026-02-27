#ifndef SIDEBARBTN_CLASS_H
#define SIDEBARBTN_CLASS_H

#include <QPushButton>
#include <QString>
#include <QLayout>
#include <QLabel>

class SidebarBtn : public QPushButton {
    Q_OBJECT

public:
    explicit SidebarBtn(const QString& icon, const QString& content);

private:
    QHBoxLayout* layout;
    QLabel* icon;
    QLabel* content;
};

#endif
