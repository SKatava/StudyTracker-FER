#ifndef SIDEBARWIDGET_CLASS_H
#define SIDEBARWIDGET_CLASS_H

#include <QFrame>
#include <QPushButton>
#include <QBoxLayout>

class SidebarWidget : public QFrame {
    Q_OBJECT

public:
    explicit SidebarWidget(QWidget* parent = nullptr);

signals:
    void homeClicked();
    void profileClicked();
    void subjectsClicked();
    void analyticsClicked();
};

#endif
