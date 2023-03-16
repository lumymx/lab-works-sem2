#include "calculator.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile styleSheetFile("../../stylesheets/Combinear.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);

    Calculator w;
    w.setWindowTitle("Calculator");

    w.show();
    return a.exec();
}
