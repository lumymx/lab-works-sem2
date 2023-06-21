#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "logic.h"
#include <QMainWindow>
#include <iostream>
#include <string.h>
#include <QFile>
#include <QFileDialog>
#include <cstdlib>
#include "./ui_mainwindow.h"
#include "table.h"
#include "error.h"
#include "graphic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString filename;
    int rowsCount = 0;
    int colsCount = 0;
    int posRegion = -1;
    int posYear = -1;

private slots:
    void onBtnFileClicked();
    void onBtnLoadClicked();
    void onBtnMetricsClicked();

    void on_lineEditRegion_textEdited(const QString &arg1);

private:
    void setupConnections();
    void resetData();
    bool validYearsInput();
    void loadData();
    funcArg createFuncArg();
    funcArg getMetrics();
    void handleError();
    bool validMetricsInput();
    void fillTable(int iterator, returnValue tmp);
    void clearTable();
    void clearMetrics();
    void setLabelText(returnValue data);
    void initTable(data_region a);

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

