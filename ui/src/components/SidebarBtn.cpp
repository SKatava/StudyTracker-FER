#include <components/SidebarBtn.h>

#include <QFont>
#include <QStyle>

#include <Fonts.h>

SidebarBtn::SidebarBtn(const QString& icon, const QString& content) : QPushButton() {
    QFont iconFont(Fonts::IconFamily);
    iconFont.setPixelSize(18);

    this->setObjectName("sidebarBtn");
    this->setFixedSize(248, 40);

    layout = new QHBoxLayout(this);
    layout->setContentsMargins(10, 0, 0, 0);

    this->icon = new QLabel(icon);
    this->content = new QLabel(content);

    this->icon->setFont(iconFont);

    layout->addWidget(this->icon);
    layout->addWidget(this->content);
    layout->addStretch();
}

void SidebarBtn::SetActive(bool active) {
    setProperty("active", active);
    style()->unpolish(this);
    style()->polish(this);
    update();
}
