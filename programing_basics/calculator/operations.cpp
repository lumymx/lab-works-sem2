#include "./operations.h"
#include <cmath>

QString add(double operand1, double operand2)
{
    return QString::number(operand1 + operand2, 'g', 20);
}

QString subtract(double operand1, double operand2)
{
    return QString::number(operand1 - operand2, 'g', 20);
}

QString multiply(double operand1, double operand2)
{
    return QString::number(operand1 * operand2, 'g', 20);
}

QString divide(double operand1, double operand2)
{
    QString result;
    if (operand2 == 0)
        result = "Error";
    else
        result = QString::number(operand1 / operand2, 'g', 20);
    return result;
}

QString percent(double operand1, double operand2)
{
    return QString::number(operand1 / 100 * operand2, 'g', 20);
}

QString power(double operand1, double operand2)
{
    return QString::number(pow(operand1, operand2), 'g', 20);
}

QString function(QString functionName, double operand)
{
    QString result;
    if (functionName == "SIN")
        result = QString::number(sin(operand), 'g', 20);
    else if (functionName == "COS")
        result = QString::number(cos(operand), 'g', 20);
    else if (functionName == "TAN")
        result = QString::number(tan(operand), 'g', 20);
    else if (functionName == "COT")
        result = QString::number(1.0 / (operand), 'g', 20);
    else if (functionName == "√") {
        if(operand < 0.0)
            result = "Error";
        else
            result = result = QString::number(sqrt(operand), 'g', 20);
    }
    return result;
}
