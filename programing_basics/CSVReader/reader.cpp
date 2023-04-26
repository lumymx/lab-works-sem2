#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"

int readDataFromFile(const char* filename, Data* data, char** errorMessage) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        *errorMessage = strdup("Could not open file");
        return -1;
    }

    char line[1024];
    int lineNumber = 0;
    size_t maxItems = 100;
    data->items = (DataItem*)malloc(maxItems * sizeof(DataItem));
    data->count = 0;

    while (fgets(line, sizeof(line), file)) {
        lineNumber++;
        if (lineNumber == 1)
            continue;

        char* yearStr = strtok(line, ",");
        char* region = strtok(NULL, ",");
        char* naturalPopulationGrowthStr = strtok(NULL, ",");
        char* birthRateStr = strtok(NULL, ",");
        char* deathRateStr = strtok(NULL, ",");
        char* generalDemographicWeightStr = strtok(NULL, ",");
        char* urbanizationStr = strtok(NULL, ",");

        if (!yearStr || !region || !naturalPopulationGrowthStr || !birthRateStr ||
            !deathRateStr || !generalDemographicWeightStr || !urbanizationStr) {
            *errorMessage = strdup("Invalid data format in line");
            fclose(file);
            return -1;
        }

        int year = atoi(yearStr);
        double naturalPopulationGrowth = atof(naturalPopulationGrowthStr);
        double birthRate = atof(birthRateStr);
        double deathRate = atof(deathRateStr);
        double generalDemographicWeight = atof(generalDemographicWeightStr);
        double urbanization = atof(urbanizationStr);

        DataItem item = { year, "", naturalPopulationGrowth, birthRate, deathRate,
                          generalDemographicWeight, urbanization };
        strncpy(item.region, region, sizeof(item.region) - 1);

        if (data->count >= maxItems) {
            maxItems *= 2;
            data->items = (DataItem*)realloc(data->items, maxItems * sizeof(DataItem));
        }
        data->items[data->count] = item;
        data->count++;
    }

    fclose(file);
    return 0;
}
