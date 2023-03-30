#include "./qt_objects_operations.h"
#include <QPushButton>

void blockButton(QPushButton* Button)
{
    Button->setStyleSheet("background-color: white;");
    Button->setEnabled(false);
    Button->setFocusPolicy(Qt::NoFocus);
}

void unblockButton(QPushButton* Button)
{
    Button->setStyleSheet("../../stylesheets/Combinear.qss");
    Button->setEnabled(true);
    Button->setFocusPolicy(Qt::ClickFocus);
}
