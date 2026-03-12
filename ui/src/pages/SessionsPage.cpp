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
    layout          = new QVBoxLayout(this);
    timer           = new StudyTimer();
    menu            = new SessionPageMenu();
    pages           = new QStackedWidget(); 
    history         = new QWidget();
    lectureCheckIn  = new QWidget();

    pages->addWidget(timer);
    pages->addWidget(history);
    pages->addWidget(lectureCheckIn);

    layout->addStretch();
    layout->addWidget(menu, 0, Qt::AlignCenter);
    layout->addSpacing(50);
    layout->addWidget(pages, 0, Qt::AlignHCenter);
    layout->addStretch();
}

void SessionsPage::setupConnections() {
    pageMap["Timer"] = timer;
    pageMap["History"] = history;
    pageMap["Lecture Check In"] = lectureCheckIn;
    
    connect(menu, &SessionPageMenu::navigateTo, this, &SessionsPage::navigateToPage);
}

void SessionsPage::navigateToPage(const QString& page) {
    if(pageMap.contains(page)) {
        pages->setCurrentWidget(pageMap[page]);
    }
}
