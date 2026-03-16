#include <layout/SessionHistory.h>
#include <components/SessionCard.h>
#include <QScrollBar>

#include <core/services/AppContext.h>
#include <components/SessionHistoryMenu.h>


SessionHistory::SessionHistory(QWidget* parent) : QWidget(parent) {
    setupUI();
    setupConnections();
}

void SessionHistory::setupUI() {
    SessionHistoryMenu* menu = new SessionHistoryMenu();
    layout = new QVBoxLayout(this);
    layout->setSpacing(10);
    layout->setContentsMargins(0,0,0,0);

    scroll = new QScrollArea();
    scroll->setContentsMargins(0,0,0,0);
    scroll->setWidgetResizable(true);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->viewport()->setFixedWidth(620);

    QWidget* container = new QWidget();
    QVBoxLayout* containerLayout = new QVBoxLayout(container);
    container->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    container->setMinimumWidth(scroll->viewport()->width());
    containerLayout->setSpacing(10);
    containerLayout->setContentsMargins(0,0,0,0);

    auto sessions = AppContext::Instance().Sessions().GetSessionsSortedByDate();

    for(auto& item : sessions) {
        SessionCard* card = new SessionCard(nullptr, item);
        containerLayout->addWidget(card);
    }

    containerLayout->addStretch(); 

    scroll->setWidget(container);

    layout->addWidget(menu);
    layout->addWidget(scroll, 1);
}

void SessionHistory::setupConnections() {
    
}
