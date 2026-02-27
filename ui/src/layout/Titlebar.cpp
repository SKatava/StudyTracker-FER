#include <layout/Titlebar.h>
#include <Fonts.h>
#include <Icons.h>
#include <QLabel>

Titlebar::Titlebar(QWidget* parent) : QFrame(parent) {
    setupUI(); 
}

void Titlebar::setupUI() {
    this->setObjectName("titlebar");
    this->setFixedHeight(40);

    layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    QFont iconFont(Fonts::IconFamily);
    iconFont.setPixelSize(16);


    closeBtn = new QPushButton(Icons::Close);
    closeBtn->setObjectName("titlebarBtn");

    closeBtn->setFont(iconFont);
    closeBtn->setFixedSize(40, 38);

    maximizeBtn = new QPushButton(Icons::Maximize);
    maximizeBtn->setObjectName("titlebarBtn");

    maximizeBtn->setFont(iconFont);
    maximizeBtn->setFixedSize(40, 38);

    minimizeBtn = new QPushButton(Icons::Minimize);
    minimizeBtn->setObjectName("titlebarBtn");

    minimizeBtn->setFont(iconFont);
    minimizeBtn->setFixedSize(40, 38);


    QLabel* title = new QLabel("Study Tracker");

    QLabel* logo = new QLabel(this);
    QPixmap pixmap(":/images/logo.png");

    logo->setPixmap(pixmap.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    logo->setFixedSize(40, 40);

    layout->addWidget(logo);

    layout->addWidget(title);
    layout->addStretch();
    layout->addWidget(minimizeBtn);
    layout->addWidget(maximizeBtn);
    layout->addWidget(closeBtn);

}

void Titlebar::setupConnections() {}

