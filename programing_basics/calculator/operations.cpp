#include "./operations.h"
#include <cmath>

QString add(double operand1, double operand2)
{
    return QString::number(operand1 + operand2);
}

QString subtract(double operand1, double operand2)
{
    return QString::number(operand1 - operand2);
}

QString multiply(double operand1, double operand2)
{
    return QString::number(operand1 * operand2);
}

QString divide(double operand1, double operand2)
{
    QString result;
    if (operand2 == 0)
        result = "Error";
    else
        result = QString::number(operand1 / operand2);
    return result;
}

QString percent(double operand1, double operand2)
{
    return QString::number(operand1 / 100 * operand2);
}

QString power(double operand1, double operand2)
{
    return QString::number(pow(operand1, operand2));
}
