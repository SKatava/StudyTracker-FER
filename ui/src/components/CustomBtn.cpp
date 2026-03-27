#include <components/CustomBtn.h>

#include <QFont>
#include <QStyle>

#include <Fonts.h>

CustomBtn::CustomBtn(const QString& icon, const QString& content) : QPushButton() {
    QFont iconFont(Fonts::IconFamily);
    iconFont.setPixelSize(18);

    layout = new QHBoxLayout(this);
    layout->setContentsMargins(10, 0, 0, 0);

    this->icon = new QLabel(icon);
    this->content = new QLabel(content);

    this->icon->setFont(iconFont);

    layout->addStretch();
    layout->addWidget(this->icon);
    layout->addWidget(this->content);
    layout->addStretch();
}

void CustomBtn::SetActive(bool active) {
    setProperty("active", active);

    style()->unpolish(this);
    style()->polish(this);
    icon->style()->unpolish(icon);
    icon->style()->polish(icon);
    content->style()->unpolish(content);
    content->style()->polish(content);

    update();
}
