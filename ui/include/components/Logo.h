#ifndef LOGO_CLASS_H
#define LOGO_CLASS_H

#include <QWidget>
#include <QLayout>
#include <QLabel>


class Logo : public QWidget{
    Q_OBJECT

public:
    explicit Logo(QWidget* parent = nullptr);

private:
    void setupUI();

    QHBoxLayout* layout;
    QLabel* logo;
    QLabel* name;

};

#endif
