#include <pages/SessionsPage.h>
#include <QLayout>
#include <QFrame>

#include <components/StudyTimer.h>
#include <components/SessionPageMenu.h>

SessionsPage::SessionsPage(QWidget* parent) : QWidget(parent) {
    setupUI();
    setupConnections();
}

void SessionsPage::setupUI() {
    QVBoxLayout* layout = new QVBoxLayout(this);
    StudyTimer* timer = new StudyTimer();
    SessionPageMenu* menu = new SessionPageMenu();
    


    layout->addStretch();
    layout->addWidget(menu, 0, Qt::AlignCenter);
    layout->addSpacing(50);
    layout->addWidget(timer, 0, Qt::AlignHCenter);
    layout->addStretch();
}

void SessionsPage::setupConnections() {
    
}
