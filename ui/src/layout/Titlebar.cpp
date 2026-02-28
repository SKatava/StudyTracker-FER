#include <layout/Titlebar.h>
#include <Fonts.h>
#include <Icons.h>

Titlebar::Titlebar(QWidget* parent) : QFrame(parent) {
    setupUI(); 
}

void Titlebar::setupUI() {
    layout          = new QHBoxLayout(this);
    closeBtn        = new QPushButton(Icons::Close);
    maximizeBtn     = new QPushButton(Icons::Maximize);
    minimizeBtn     = new QPushButton(Icons::Minimize);
    
    QFont iconFont(Fonts::IconFamily);
    iconFont.setPixelSize(16);

    this->setObjectName("titlebar");
    this->setFixedHeight(40);

    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    closeBtn->setObjectName("titlebarBtn");
    closeBtn->setFont(iconFont);
    closeBtn->setFixedSize(40, 38);

    maximizeBtn->setObjectName("titlebarBtn");
    maximizeBtn->setFont(iconFont);
    maximizeBtn->setFixedSize(40, 38);

    minimizeBtn->setObjectName("titlebarBtn");
    minimizeBtn->setFont(iconFont);
    minimizeBtn->setFixedSize(40, 38);

    layout->addStretch();

    layout->addWidget(minimizeBtn);
    layout->addWidget(maximizeBtn);
    layout->addWidget(closeBtn);

}

void Titlebar::setupConnections() {}

