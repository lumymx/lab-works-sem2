#ifndef READER_H
#define READER_H

#include <cstddef>

typedef struct {
    int year;
    char region[50];
    double natural_population_growth;
    double birth_rate;
    double death_rate;
    double general_demographic_weight;
    double urbanization;
} DataItem;

typedef struct {
    DataItem* items;
    size_t count;
} Data;

int readDataFromFile(const char* filename, Data* data, char** errorMessage);

#endif // READER_H
