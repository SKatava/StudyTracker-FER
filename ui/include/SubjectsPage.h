#ifndef SUBJECTSPAGE_CLASS_H
#define SUBJECTSPAGE_CLASS_H

#include <QWidget>
#include <QLabel>

class SubjectsPage : public QWidget {
    Q_OBJECT
    
public:
    explicit SubjectsPage(QWidget* parent = nullptr);

private:
    void setupUI();
    QLabel* titleLabel;
};

#endif
