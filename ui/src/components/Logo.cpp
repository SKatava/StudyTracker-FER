#include <components/Logo.h>

Logo::Logo(QWidget* parent) : QWidget(parent) {
    setupUI();    
}

void Logo::setupUI() {
    layout  = new QHBoxLayout(this);
    name    = new QLabel("Study Tracker");
    logo    = new QLabel(this);
    
    this->setObjectName("logo");

    QPixmap pixmap(":/images/logo.png");
    logo->setPixmap(pixmap.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    logo->setFixedSize(40, 40);
    
    layout->addWidget(logo);
    layout->addWidget(name);
}
