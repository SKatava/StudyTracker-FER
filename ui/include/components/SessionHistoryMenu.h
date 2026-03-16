#ifndef SESSIONHISTORYMENU_CLASS_H
#define SESSIONHISTORYMENU_CLASS_H

#include <QWidget>
#include <QLayout>
#include <QComboBox>

#include <components/CustomBtn.h>

class SessionHistoryMenu : public QWidget {
    Q_OBJECT

public:
    explicit SessionHistoryMenu(QWidget* parent = nullptr); 

private:
    void setupUI();
    void setupConnections();

    QHBoxLayout* layout;
    CustomBtn* newLogBtn;
    QComboBox* subjectFilter;

};

#endif
