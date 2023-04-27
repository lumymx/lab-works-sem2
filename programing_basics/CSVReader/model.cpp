#include "model.h"
#include "strings.h"

QStandardItemModel* generateModel(QMainWindow* w, Data data, std::string region) {
    QStandardItemModel* model = new QStandardItemModel(w);

    model->setHorizontalHeaderLabels({
        "Year",
        "Region",
        "Natural Population Growth",
        "Birth Rate",
        "Death Rate",
        "General Demographic Weight",
        "Urbanization"
    });

    for (size_t i = 0; i < data.count; i++) {
        if (stringToLower(data.items[i].region) == stringToLower(region) || region == "") {
            QStandardItem* itemYear = new QStandardItem(QString::number(data.items[i].year));
            QStandardItem* itemRegion = new QStandardItem(data.items[i].region);
            QStandardItem* itemGrowth = new QStandardItem(QString::number(data.items[i].natural_population_growth));
            QStandardItem* itemBirth = new QStandardItem(QString::number(data.items[i].birth_rate));
            QStandardItem* itemDeath = new QStandardItem(QString::number(data.items[i].death_rate));
            QStandardItem* itemWeight = new QStandardItem(QString::number(data.items[i].general_demographic_weight));
            QStandardItem* itemUrban = new QStandardItem(QString::number(data.items[i].urbanization));
            QList<QStandardItem*> row;
            row << itemYear << itemRegion << itemGrowth << itemBirth << itemDeath << itemWeight << itemUrban;
            model->appendRow(row);
        }
    }

    return model;
}
