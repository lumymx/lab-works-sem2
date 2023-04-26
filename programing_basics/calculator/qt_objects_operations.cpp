#include "./qt_objects_operations.h"
#include <QPushButton>

void blockButton(QPushButton* Button);
void unblockButton(QPushButton* Button);

void setButtonState(QPushButton* Button, std::string flag) {
    if (flag == "b")
        blockButton(Button);
    else if (flag == "u")
        unblockButton(Button);
}

void blockButton(QPushButton* Button) {
    Button->setStyleSheet("background-color: white;");
    Button->setEnabled(false);
    Button->setFocusPolicy(Qt::NoFocus);
}

void unblockButton(QPushButton* Button) {
    Button->setStyleSheet("../../stylesheets/Combinear.qss");
    Button->setEnabled(true);
    Button->setFocusPolicy(Qt::StrongFocus);
}
