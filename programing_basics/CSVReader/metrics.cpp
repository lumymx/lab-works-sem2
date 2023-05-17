#include "metrics.h"

static int compare_double(const void* a, const void* b);

static int compare_double(const void* a, const void* b) {
    double arg1 = *static_cast<const double*>(a);
    double arg2 = *static_cast<const double*>(b);
    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

Metrics computeMetrics(const double* values, int count) {
    Metrics stats;

    double* sorted_values = static_cast<double*>(malloc(count * sizeof(double)));
    if (sorted_values == nullptr) {
        return stats;
    }
    memcpy(sorted_values, values, count * sizeof(double));

    qsort(sorted_values, count, sizeof(double), compare_double);

    stats.min = sorted_values[0];
    stats.max = sorted_values[count - 1];

    if (count % 2 == 0) {
        int middle = count / 2;
        stats.median = (sorted_values[middle - 1] + sorted_values[middle]) / 2;
    } else {
        int middle = count / 2;
        stats.median = sorted_values[middle];
    }

    free(sorted_values);
    return stats;
}
