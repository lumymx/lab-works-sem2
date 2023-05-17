#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "reader.h"

int readDataFromFile(const std::string& filename, Data* data, std::string* errorMessage) {
    std::ifstream file(filename.c_str());
    if (!file) {
        *errorMessage = "Could not open file";
        return -1;
    }

    size_t maxItems = 100;
    data->items = (DataItem*) malloc(maxItems * sizeof(DataItem));
    if (data->items == NULL) {
        *errorMessage = "Memory allocation error";
        return -1;
    }
    data->count = 0;

    std::string line;
    std::getline(file, line);
    int lineNumber = 1;
    while (std::getline(file, line)) {
        lineNumber++;

        std::istringstream lineStream(line);
        std::string yearStr, region, naturalPopulationGrowthStr, birthRateStr, deathRateStr, generalDemographicWeightStr, urbanizationStr;

        std::getline(lineStream, yearStr, ',');
        std::getline(lineStream, region, ',');
        std::getline(lineStream, naturalPopulationGrowthStr, ',');
        std::getline(lineStream, birthRateStr, ',');
        std::getline(lineStream, deathRateStr, ',');
        std::getline(lineStream, generalDemographicWeightStr, ',');
        std::getline(lineStream, urbanizationStr, '\n');

        if (yearStr.empty() || region.empty() || naturalPopulationGrowthStr.empty()
            || birthRateStr.empty() || deathRateStr.empty() || generalDemographicWeightStr.empty()
            || urbanizationStr.empty()) {
            *errorMessage = "Invalid data format in line";
            return -1;
        }

        int year = std::atoi(yearStr.c_str());
        double naturalPopulationGrowth = std::atof(naturalPopulationGrowthStr.c_str());
        double birthRate = std::atof(birthRateStr.c_str());
        double deathRate = std::atof(deathRateStr.c_str());
        double generalDemographicWeight = std::atof(generalDemographicWeightStr.c_str());
        double urbanization = std::atof(urbanizationStr.c_str());

        DataItem item = { year, region, naturalPopulationGrowth, birthRate, deathRate,
                          generalDemographicWeight, urbanization};

        if (data->count >= maxItems) {
            maxItems *= 2;
            DataItem* newItems = (DataItem*) realloc(data->items, maxItems * sizeof(DataItem));
            if (newItems == NULL) {
                *errorMessage = "Memory reallocation error";
                free(data->items);
                return -1;
            }
            data->items = newItems;
        }
        data->items[data->count] = item;
        data->count++;
    }

    return 0;
}
