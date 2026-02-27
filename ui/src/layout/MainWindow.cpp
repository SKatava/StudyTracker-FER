#include <layout/MainWindow.h>

//QT headers
#include <QHBoxLayout>
#include <QFrame>
#include <QLabel>

//Personal headers

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent)  {
    setWindowFlags(Qt::FramelessWindowHint | Qt::Window);

    setupUI();
    setupConnections();
}

void MainWindow::setupUI() {
    central         = new QWidget(this);
    rootLayout      = new QVBoxLayout(central);
    titlebar        = new Titlebar();
    body            = new QWidget();
    bodyLayout      = new QHBoxLayout(body);
    sidebar         = new Sidebar();
    pages           = new QStackedWidget();
    
    setCentralWidget(central);

    rootLayout->setContentsMargins(0, 0, 0, 0);
    rootLayout->setSpacing(0);

    rootLayout->addWidget(titlebar);
    rootLayout->addWidget(body);

    bodyLayout->setContentsMargins(10, 10, 10, 10);

    bodyLayout->addWidget(sidebar);
    bodyLayout->addWidget(pages);
     

}

void MainWindow::setupConnections() {

}
