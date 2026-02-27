#ifndef SUBJECTSPAGE_CLASS_H
#define SUBJECTSPAGE_CLASS_H

#include <QWidget>
#include <QLayout>

class SubjectsPage : public QWidget {
    Q_OBJECT
    
public:
    explicit SubjectsPage(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();

    
};

#endif
