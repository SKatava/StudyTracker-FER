#include <pages/DashboardPage.h>
#include <QLabel>

DashboardPage::DashboardPage(QWidget* parent) : QWidget(parent) {
    setupUI();
    setupConnections();
}

void DashboardPage::setupUI() {
    QHBoxLayout* ly = new QHBoxLayout(this);
    QLabel* lbl = new QLabel("dash");
    ly->addWidget(lbl);
}

void DashboardPage::setupConnections() {

}
