#include <components/Separator.h>

Separator::Separator(QWidget* parent) : QFrame(parent) {
    this->setFrameShape(QFrame::NoFrame);
    this->setFixedHeight(1);
    this->setFixedWidth(250);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed); 
    this->setObjectName("seperator");
}
