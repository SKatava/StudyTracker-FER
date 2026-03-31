#include <pages/TasksPage.h>

#include <components/TaskCard.h>

#include <core/domain/Task.h>

TasksPage::TasksPage(QWidget* parent) : QWidget(parent) {
    setupUI();
    setupConnections();
}

void TasksPage::setupUI() {
    layout = new QVBoxLayout(this);
    menu = new TaskPageMenu();

    Task task {1, 36, 0};
    TaskCard* card = new TaskCard(nullptr, task);

    layout->addSpacing(50);
    layout->addWidget(menu, 0, Qt::AlignCenter);
    layout->addWidget(card);
    layout->addStretch();



}

void TasksPage::setupConnections() {

}
