#ifndef logic_H
#define logic_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "sort.h"
#include <string.h>

using namespace std;

enum FuncType
{
    GetData,
    CalculateMetrics
};

typedef struct data_region
{
    string year;
    int size = 0;
    int placed = 0;
    double metrics[3];
    int error = 0;
} returnValue;


typedef struct entrypointInput {
    string region;
    string year;
    string year2;
    int posRegion;
    int posYear;
    int placed;
    string fileName;
    int metricsCount;
    double* metrics;
    FuncType funcType;
} funcArg;

data_region entryPoint(funcArg data);

#endif // logic_H
