#include <layout/SessionHistory.h>
#include <components/SessionCard.h>
#include <QScrollBar>

#include <core/services/AppContext.h>

SessionHistory::SessionHistory(QWidget* parent) : QWidget(parent) {
    setupUI();
    setupConnections();
}

void SessionHistory::setupUI() {
    menu = new SessionHistoryMenu();
    sessionForm = new AddSessionForm();

    layout = new QVBoxLayout(this);
    layout->setSpacing(10);
    layout->setContentsMargins(0,0,0,0);

    scroll = new QScrollArea();
    scroll->setWidgetResizable(true);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->viewport()->setFixedWidth(620);

    container = new QWidget();
    containerLayout = new QVBoxLayout(container);
    containerLayout->setSpacing(10);
    containerLayout->setContentsMargins(0,0,0,0);

    auto sessions = AppContext::Instance().Sessions().GetSessionsSortedByDate();

    for (auto& item : sessions) {
        SessionCard* card = new SessionCard(nullptr, item);
        containerLayout->addWidget(card);
        cards.push_back(card);  
    }

    containerLayout->addStretch();

    scroll->setWidget(container);

    layout->addWidget(menu);
    layout->addWidget(scroll, 1);
}

void SessionHistory::setupConnections() {
    connect(menu, &SessionHistoryMenu::filterApplied, this, &SessionHistory::onFilterApplied);
    connect(menu, &SessionHistoryMenu::openSessionForm, this, &SessionHistory::onOpenSessionForm);

}

void SessionHistory::onFilterApplied(QString name) {
    for (auto* card : cards) {
        if (name == "All" ||
            card->getSubjectName().compare(name, Qt::CaseInsensitive) == 0) {
            card->show();
        } else {
            card->hide();
        }
    }
}

void SessionHistory::onOpenSessionForm() {
    AddSessionForm* form = new AddSessionForm(this);

    form->move(
        (width() - form->width()) / 2,
        (height() - form->height()) / 2
    );

    form->show();
    form->raise();
}
