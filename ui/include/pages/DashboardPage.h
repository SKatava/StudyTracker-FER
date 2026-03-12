#ifndef DASHBOARDPAGE_CLASS_H
#define DASHBOARDPAGE_CLASS_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>

#include <components/SubjectCard.h>
#include <components/Header.h>
#include <layout/FlowLayout.h>



class DashboardPage : public QWidget {
    Q_OBJECT
    
public:
    explicit DashboardPage(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();
    void refreshSubjects();

    QVBoxLayout* rootLayout;
    FlowLayout* activeSubjectsLayout;

    QWidget* activeSubjects;

    Header* activeSubjectsHeader;
    Header* statsHeader;

    QPushButton* addSubjectBtn;
    
private slots:
    void onAddButtonClicked();
    void onSubjectCreated(const Subject& subject);
};

#endif
