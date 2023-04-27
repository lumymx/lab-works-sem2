#ifndef METRICS_H
#define METRICS_H

#include <cstdlib>
#include <cstring>
#include <cmath>

struct Metrics {
    double min;
    double max;
    double median;
};

Metrics computeMetrics(const double* values, int count);


#endif // METRICS_H
