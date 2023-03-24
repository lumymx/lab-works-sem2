#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <string>

std::string calculateOperationResult(double operand1, double operand2, std::string operation, int limit);
bool checkErrors(double operand1, double operand2, std::string operation);

double add(double operand1, double operand2);
double subtract(double operand1, double operand2);
double multiply(double operand1, double operand2);
double divide(double operand1, double operand2);
double percent(double operand1, double operand2);
double power(double operand1, double operand2);
double function(double operand, std::string functionName);

#endif // OPERATIONS_H
