#include <layout/TaskList.h>

#include <QScrollBar>

#include <layout/AddTaskForm.h>

#include <core/services/AppContext.h>

TaskList::TaskList(QWidget* parent) : QWidget(parent) {
    setupUI();
    setupConnections();
}

void TaskList::setupUI() {
    this->setFixedWidth(600);

    menu = new TaskListMenu();

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

    auto tasks = AppContext::Instance().Tasks().GetTasks();
    
    for (auto& item : tasks) {
        TaskCard* card = new TaskCard(nullptr, item);
        containerLayout->addWidget(card);
        cards.push_back(card);  
    }

    containerLayout->addStretch();

    scroll->setWidget(container);

    layout->addWidget(menu);
    layout->addWidget(scroll, 1);
}

void TaskList::setupConnections() {
    connect(menu, &TaskListMenu::filterApplied, this, &TaskList::onFilterApplied);
    connect(menu, &TaskListMenu::openTaskForm, this, &TaskList::onOpenTaskForm);
}

void TaskList::onFilterApplied(QString name) {
    for (auto* card : cards) {
        if (name == "All" ||
            card->getSubjectName().compare(name, Qt::CaseInsensitive) == 0) {
            card->show();
        } else {
            card->hide();
        }
    }
}

void TaskList::onOpenTaskForm() {
    AddTaskForm* form = new AddTaskForm(this);

    form->move(
        (width() - form->width()) / 2,
        (height() - form->height()) / 2
    );

    form->show();
    form->raise();
}
