#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardItemModel>
#include "model.h"
#include "metrics.h"
#include "reader.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->BtnBrowse, SIGNAL(clicked()), this, SLOT(onBtnBrowseClicked()));
    connect(ui->BtnLoad, SIGNAL(clicked()), this, SLOT(onBtnLoadClicked()));
    connect(ui->BtnMetrics, SIGNAL(clicked()), this, SLOT(onBtnMetricsClicked()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onBtnBrowseClicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("CSV Files (*.csv);;All Files (*.*)"));
    if (!fileName.isEmpty())
        ui->BrowserName->setText(fileName);
    QAbstractItemModel* model = ui->tableView->model();
    if (model)
        model->removeRows(0, model->rowCount());
}

void MainWindow::onBtnLoadClicked() {
    std::string region = ui->LineEditRegion->text().toStdString();
    int column = ui->LineEditColumn->text().toInt();
    if(ui->LineEditColumn->text() == "")
        column = -1;
    QString filePath = ui->BrowserName->toPlainText();
    if (filePath == "") {
        QMessageBox::warning(this, "Warning", "Please, select a file");
    } else {
        if (column < -1 || column > 6) {
            QMessageBox::critical(this, "Error", "Wrong column value");
        } else {
            QByteArray fileData = filePath.toLocal8Bit();
            const char* filePathStr = fileData.data();

            Data data;
            char* errorMessage = NULL;
            int result = readDataFromFile(filePathStr, &data, &errorMessage);

            if (result == 0) {
                QStandardItemModel* model = generateModel(this, data, region);
                ui->tableView->setModel(model);
            }
            else
                QMessageBox::critical(this, "Error", errorMessage);

            free(data.items);
            free(errorMessage);
        }
    }
}

void MainWindow::onBtnMetricsClicked() {
    QString region = ui->LineEditRegion->text();
    QString columnText = ui->LineEditColumn->text();
    int column = columnText.toInt();
    int rowCnt = ui->tableView->model()->rowCount();
    if (region.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Incorrect region value");
        return;
    }

    if (column <= 0 || column > ui->tableView->model()->columnCount() || rowCnt == 0) {
        QMessageBox::warning(this, "Warning", "Incorrect column value");
        return;
    }
    double* values = (double*) malloc(rowCnt * sizeof(double));
    if (values == nullptr) {
        QMessageBox::critical(this, "Ошибка", "Не удалось выделить память");
        return;
    }
    for (int i = 0; i < rowCnt; i++) {
        QModelIndex index = ui->tableView->model()->index(i, column - 1);
        QVariant value = ui->tableView->model()->data(index);
        values[i] = value.toDouble();
    }
    Metrics stats = computeMetrics(values, rowCnt);

    ui->TextBrowserMax->clear();
    ui->TextBrowserMax->insertPlainText(QString::number(stats.max));
    ui->TextBrowserMin->clear();
    ui->TextBrowserMin->insertPlainText(QString::number(stats.min));
    ui->TextBrowserMedian->clear();
    ui->TextBrowserMedian->insertPlainText(QString::number(stats.median));

    free(values);
}
