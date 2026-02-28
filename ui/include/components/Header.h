#ifndef HEADER_CLASS_H
#define HEADER_CLASS_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QString>

#include <components/Separator.h>


class Header : public QWidget {
    Q_OBJECT

public:
    explicit Header(QWidget* parent = nullptr, const QString& title = "");

private:
    void setupUI(const QString& title);
    void setupConnections();

    QHBoxLayout* layout;
    QLabel* title;
    Separator* separator;
};

#endif
