#ifndef CUSTOMBTN_CLASS_H
#define CUSTOMBTN_CLASS_H

#include <QPushButton>
#include <QString>
#include <QLayout>
#include <QLabel>

class CustomBtn : public QPushButton {
    Q_OBJECT

public:
    explicit CustomBtn(const QString& icon, const QString& content);
    void SetActive(bool active);

private:
    QHBoxLayout* layout;
    QLabel* icon;
    QLabel* content;
};

#endif
