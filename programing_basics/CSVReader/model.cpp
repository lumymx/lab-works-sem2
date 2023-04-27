#include "model.h"
#include "strings.h"

std::string getHeaderForColumn(int column);

QStandardItemModel* generateModel(QMainWindow* w, Data data, std::string region, int column) {
    QStandardItemModel* model = new QStandardItemModel(w);
    QStringList headers;
    if (column == -1) {
        headers = {
            "Year",
            "Region",
            "Natural Population Growth",
            "Birth Rate",
            "Death Rate",
            "General Demographic Weight",
            "Urbanization"
        };
    } else {
        headers.append(QString::fromStdString(getHeaderForColumn(column)));
    }

    model->setHorizontalHeaderLabels(headers);
    for (size_t i = 0; i < data.count; i++) {
        if (stringToLower(data.items[i].region) == stringToLower(region) || region == "") {
            QList<QStandardItem*> row;
            QStandardItem* item = nullptr;
            switch(column) {
                case 0:
                    item = new QStandardItem(QString::number(data.items[i].year));
                    break;
                case 1:
                    item = new QStandardItem(data.items[i].region);
                    break;
                case 2:
                    item = new QStandardItem(QString::number(data.items[i].natural_population_growth));
                    break;
                case 3:
                    item = new QStandardItem(QString::number(data.items[i].birth_rate));
                    break;
                case 4:
                    item = new QStandardItem(QString::number(data.items[i].death_rate));
                    break;
                case 5:
                    item = new QStandardItem(QString::number(data.items[i].general_demographic_weight));
                    break;
                case 6:
                    item = new QStandardItem(QString::number(data.items[i].urbanization));
                    break;
                default:
                    row << new QStandardItem(QString::number(data.items[i].year));
                    row << new QStandardItem(data.items[i].region);
                    row << new QStandardItem(QString::number(data.items[i].natural_population_growth));
                    row << new QStandardItem(QString::number(data.items[i].birth_rate));
                    row << new QStandardItem(QString::number(data.items[i].death_rate));
                    row << new QStandardItem(QString::number(data.items[i].general_demographic_weight));
                    row << new QStandardItem(QString::number(data.items[i].urbanization));
                    break;
            }
            if(item) {
                row << item;
            }
            model->appendRow(row);
        }
    }

    return model;
}

std::string getHeaderForColumn(int column) {
    switch(column) {
        case 0:
            return "Year";
        case 1:
            return "Region";
        case 2:
            return "Natural Population Growth";
        case 3:
            return "Birth Rate";
        case 4:
            return "Death Rate";
        case 5:
            return "General Demographic Weight";
        case 6:
            return "Urbanization";
        default:
            return "";
    }
}
