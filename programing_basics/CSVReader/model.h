#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <QStandardItemModel>
#include <QMainWindow>
#include <string>
#include "reader.h"

QStandardItemModel* generateModel(QMainWindow* w, Data data, std::string region, int column);


#endif // MODEL_H
