#include"error.h"
#include <QMessageBox>

void error(errorType i)
{
    switch (i) {
    case columnValue:
        QMessageBox::critical(0, "Error message", "Column has not correct data");
        break;
    case columnData:
        QMessageBox::critical(0, "Error message", "Wrong column");
        break;
    case region:
        QMessageBox::critical(0, "Error message", "Wrong region");
        break;
    case file:
        QMessageBox::critical(0, "Error message", "Select file");
        break;
    case year:
        QMessageBox::critical(0, "Error message", "Wrong year");
    }
}
