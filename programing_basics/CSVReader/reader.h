#ifndef READER_H
#define READER_H

#include <cstddef>
#include <string>

typedef struct {
    int year;
    std::string region;
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

int readDataFromFile(const std::string& filename, Data* data, std::string* errorMessage);

#endif // READER_H
