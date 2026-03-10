#ifndef STUDYTIMER_CLASS_H
#define STUDYTIMER_CLASS_H

#include <QFrame>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QTimer>
#include <QTextEdit>

class StudyTimer : public QFrame {
    Q_OBJECT
    
public:
    explicit StudyTimer(QWidget* parent = nullptr);
private:
    void setupUI();
    void setupConnections();

    QVBoxLayout* layout;
    QHBoxLayout* bottomLayout;
    QLabel* title;
    QLabel* time;
    QComboBox* subjectList;
    QTextEdit* descriptionInput;
    QPushButton* startBtn;
    QPushButton* confirmBtn;
    QPushButton* cancelBtn;
    QTimer* timer;
    int elapsedSeconds {0};
};

#endif
