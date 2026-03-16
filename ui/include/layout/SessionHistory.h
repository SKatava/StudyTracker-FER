#ifndef SESSIONHISTORY_CLASS_H
#define SESSIONHISTORY_CLASS_H

#include <QWidget>
#include <QLayout>
#include <QScrollArea>


class SessionHistory : public QWidget {
    Q_OBJECT

public:
    explicit SessionHistory(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();
    
    QVBoxLayout* layout;
    QScrollArea* scroll;
};

#endif
