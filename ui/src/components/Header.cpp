#include <components/Header.h>

Header::Header(QWidget* parent, const QString& title) : QWidget(parent) {
    setupUI(title); 
}

void Header::setupUI(const QString& title) {
    layout          = new QHBoxLayout(this);
    this->title     = new QLabel(title);
    separator       = new Separator();

    this->title->setObjectName("headerTitle");
    layout->setContentsMargins(0, 0, 0, 0);

    layout->addWidget(this->title);
    layout->addWidget(separator);
    
}

void Header::setupConnections() {
    
}
