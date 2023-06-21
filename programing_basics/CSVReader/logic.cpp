#include "logic.h"

returnValue getData(funcArg data)
{
    fstream file;
    string lastReadRegion;
    string inputData;
    returnValue selectedRegions;

    file.open(data.fileName);

    if(file.is_open()) {
        getline(file, selectedRegions.year);

        while(getline(file, lastReadRegion) && selectedRegions.size < 100) {
            if(selectedRegions.placed >= data.placed) {
                stringstream streamLastReadRegion(lastReadRegion);

                for(int i = 0; i <= data.posYear; i++)
                    getline(streamLastReadRegion, inputData, ',');

                if(data.year == "" || (stoi(inputData) >= stoi(data.year) && stoi(inputData) <= stoi(data.year2))) {
                    stringstream veryTemp(lastReadRegion);

                    for(int i = 0; i <= data.posRegion; i++)
                        getline(veryTemp, inputData, ',');

                    if(inputData == data.region || data.region == "") {
                        selectedRegions.year += "\n" + lastReadRegion;
                        selectedRegions.size += 1;
                    }
                }
            }
            selectedRegions.placed++;
        }

        file.close();
    }

    return selectedRegions;
}

returnValue calculateMetrics(funcArg data)
{
    sortArray(data.metrics, data.metricsCount);
    returnValue result;
    if(data.metricsCount % 2 == 1)
        result.metrics[0] = data.metrics[(int)(data.metricsCount / 2)];
    else
        result.metrics[0] = (data.metrics[(int)(data.metricsCount / 2) - 1] + data.metrics[(data.metricsCount / 2)]) / 2;

    result.metrics[1] = data.metrics[0];
    result.metrics[2] = data.metrics[data.metricsCount - 1];
    free(data.metrics);

    return result;
}

returnValue entryPoint(funcArg data)
{
    returnValue result;
    switch (data.funcType) {
    case FuncType::GetData:
        result = getData(data);
        break;

    case FuncType::CalculateMetrics:
        result = calculateMetrics(data);
        break;
    default:
        result.error = 1;
    }
    return result;
}

