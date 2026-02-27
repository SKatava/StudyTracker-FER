#include <pages/SubjectsPage.h>
#include <QLabel>

SubjectsPage::SubjectsPage(QWidget* parent) : QWidget(parent) {
    setupUI();
    setupConnections();
}

void SubjectsPage::setupUI() {
    QHBoxLayout* ly = new QHBoxLayout(this);
    QLabel* lbl = new QLabel("subjects");
    ly->addWidget(lbl);
}

void SubjectsPage::setupConnections() {

}
