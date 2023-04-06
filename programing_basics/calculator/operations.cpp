#include "./operations.h"
#include "./strings.h"
#include <cmath>
#include <string>

bool checkErrors(double operand1, double operand2, std::string operation);

double add(double operand1, double operand2);
double subtract(double operand1, double operand2);
double multiply(double operand1, double operand2);
double divide(double operand1, double operand2);
double percent(double operand1, double operand2);
double power(double operand1, double operand2);
double function(double operand, std::string functionName);

std::string calculateOperationResult(double operand1, double operand2, std::string operation, int limit) {
    std::string result;
    if(checkErrors(operand1, operand2, operation))
        result = "Error";
    else {
        double doubleResult;
        if(operation == "add")
            doubleResult = add(operand1, operand2);
        else if(operation == "sub")
            doubleResult = subtract(operand1, operand2);
        else if(operation == "mult")
            doubleResult = multiply(operand1, operand2);
        else if(operation == "div")
            doubleResult = divide(operand1, operand2);
        else if(operation == "percent")
            doubleResult = percent(operand1, operand2);
        else if(operation == "pow")
            doubleResult = pow(operand1, operand2);
        else
            doubleResult = function(operand1, operation);
        result = doubleToString(doubleResult, limit);
    }
    return result;
}

bool checkErrors(double operand1, double operand2, std::string operation) {
    bool result = false;
    if ((operation == "sqrt" && operand1 < 0) || (operation == "div" && operand2 == 0))
        result = true;
    return result;
}

double add(double operand1, double operand2) {
    return operand1 + operand2;
}

double subtract(double operand1, double operand2) {
    return operand1 - operand2;
}

double multiply(double operand1, double operand2) {
    return operand1 * operand2;
}

double divide(double operand1, double operand2) {
    return operand1 / operand2;
}

double percent(double operand1, double operand2) {
    return operand1 / 100 * operand2;
}

double function(double operand, std::string functionName) {
    double result = operand;
    if (functionName == "sin")
        result = sin(operand);
    else if (functionName == "cos")
        result = cos(operand);
    else if (functionName == "tan")
        result = tan(operand);
    else if (functionName == "cot")
        result = 1.0 / operand;
    else if (functionName == "sqrt")
        result = sqrt(operand);
    return result;
}
