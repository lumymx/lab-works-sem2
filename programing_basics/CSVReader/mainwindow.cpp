#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupConnections();
}

void MainWindow::setupConnections() {
    connect(ui->btnFile, &QPushButton::clicked, this, &MainWindow::onBtnFileClicked);
    connect(ui->btnLoad, &QPushButton::clicked, this, &MainWindow::onBtnLoadClicked);
    connect(ui->btnMetrics, &QPushButton::clicked, this, &MainWindow::onBtnMetricsClicked);
    ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
}

void MainWindow::onBtnFileClicked() {
    resetData();
    filename = QFileDialog::getOpenFileName(this, "Choose the file", "../", "Image Files (*.csv)");
    ui->labelFilePath->setText(filename);
    if (!filename.isEmpty())
        onBtnLoadClicked();
}

void MainWindow::resetData() {
    posRegion = -1;
    posYear = -1;
    clearTable();
    clearMetrics();
}

void MainWindow::onBtnLoadClicked() {
    if (validYearsInput())
        loadData();
    else
        handleError();
}

bool MainWindow::validYearsInput() {
    return !(ui->lineEditYear1->text().isEmpty() && !ui->lineEditYear2->text().isEmpty()
             || !ui->lineEditYear1->text().isEmpty() && ui->lineEditYear2->text().isEmpty());
}

void MainWindow::loadData() {
    clearMetrics();
    rowsCount = 0;
    ui->btnMetrics->setEnabled(true);
    ui->lineEditCol->setEnabled(true);
    funcArg data = createFuncArg();
    int i = 0;
    returnValue tableData;
    do {
        tableData = entryPoint(data);
        if (tableData.size == 0) {
            clearTable();
            error(region);
            break;
        }
        data.placed = tableData.placed;
        rowsCount += tableData.size;
        initTable(tableData);
        fillTable(i, tableData);
        i++;
    } while (tableData.size == 100);
}

funcArg MainWindow::createFuncArg() {
    return {ui->lineEditRegion->text().toStdString(),
            ui->lineEditYear1->text().toStdString(),
            ui->lineEditYear2->text().toStdString(),
            posRegion, posYear,
            0, filename.toStdString()};
}

void MainWindow::handleError() {
    if (filename.isEmpty())
        error(file);
    else if (!validYearsInput())
        error(year);
}

void MainWindow::onBtnMetricsClicked()
{
    if (validMetricsInput()) {
        funcArg tmp = getMetrics();
        if (tmp.metricsCount != 0) {
            tmp.funcType = FuncType::CalculateMetrics;
            returnValue a = entryPoint(tmp);
            setLabelText(a);
        }

        int col = ui->lineEditCol->text().toInt() - 1;
        if (col >= 0 && col < ui->tableWidget->columnCount()) {

            QString metricName = ui->tableWidget->horizontalHeaderItem(col)->text();

            int size = ui->tableWidget->rowCount();

            double *values = (double*)malloc(sizeof(double) * size);
            double *years = (double*)malloc(sizeof(double) * size);
            if (values == nullptr || years == nullptr) {
                qFatal("Failed to allocate memory");
                return;
            }

            for (int row = 0; row < size; row++) {
                QTableWidgetItem *item = ui->tableWidget->item(row, col);
                if (item != nullptr) {
                    bool ok;
                    double value = item->text().toDouble(&ok);
                    if (ok) {
                        values[row] = value;
                    }
                }
                QTableWidgetItem *yearItem = ui->tableWidget->item(row, 0);
                if (yearItem != nullptr) {
                    bool ok;
                    double yearValue = yearItem->text().toDouble(&ok);
                    if (ok) {
                        years[row] = yearValue;
                    }
                }
            }

            GraphItem *graphItem = new GraphItem(years, values, size, "Year", metricName);
            QGraphicsScene *scene = new QGraphicsScene(this);
            scene->addItem(graphItem);
            ui->graphicsView->setScene(scene);
        }
        else {
            error(columnValue);
        }
    }
    else {
        error(columnData);
    }
}

bool MainWindow::validMetricsInput() {
    int colValue = ui->lineEditCol->text().toInt();
    return !ui->lineEditCol->text().isEmpty() && !filename.isEmpty() && colValue > 0 && colValue <= colsCount;
}

MainWindow::~MainWindow() {
    delete ui;
}
