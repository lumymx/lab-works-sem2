#ifndef ERROR_H
#define ERROR_H

enum errorType
{
    year,
    region,
    columnValue,
    columnData,
    file
};

void error(errorType i);

#endif // ERROR_H
