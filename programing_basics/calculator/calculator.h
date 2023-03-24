#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextBrowser>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void numberClicked();
    void operatorClicked();
    void functionClicked();
    void memoryClicked();
    void clearClicked();
    void deleteClicked();
    void negateClicked();
    void pointClicked();
    void equalsClicked();

private:
    void commitOperation();
    Ui::Calculator *ui;
    double operand1 = 0;
    double operand2 = 0;
    double memory = 0;
    int maxLength = 21;
    enum Operation {
        NONE,
        ADD,
        SUBTRACT,
        MULTIPLY,
        DIVIDE,
        PERCENT,
        POWER
    } operation;
};

#endif // CALCULATOR_H
