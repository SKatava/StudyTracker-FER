#include <pages/SessionsPage.h>
#include <QLayout>

#include <components/StudyTimer.h>

SessionsPage::SessionsPage(QWidget* parent) : QWidget(parent) {
    setupUI();
    setupConnections();
}

void SessionsPage::setupUI() {
    QHBoxLayout* layout = new QHBoxLayout(this);
    StudyTimer* timer = new StudyTimer();

    layout->addWidget(timer);
}

void SessionsPage::setupConnections() {

}
