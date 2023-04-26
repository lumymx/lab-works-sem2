#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardItemModel>
#include "reader.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->BtnBrowse, SIGNAL(clicked()), this, SLOT(onBtnBrowseClicked()));
    connect(ui->BtnLoad, SIGNAL(clicked()), this, SLOT(onBtnLoadClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onBtnBrowseClicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("CSV Files (*.csv);;All Files (*.*)"));
    if (!fileName.isEmpty())
        ui->BrowserName->setText(fileName);
}

void MainWindow::onBtnLoadClicked()
{
    QString region = ui->LineEditRegion->text();
    QString filePath = ui->BrowserName->toPlainText();

    QByteArray regionData = region.toLocal8Bit();
    const char* regionStr = regionData.data();

    QByteArray fileData = filePath.toLocal8Bit();
    const char* filePathStr = fileData.data();

    Data data;
    char* errorMessage = NULL;
    int result = readDataFromFile(filePathStr, &data, &errorMessage);

    if (result == 0) {
        QStandardItemModel* model = new QStandardItemModel(this);

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

        ui->tableView->setModel(model);
    }
    else
        QMessageBox::critical(this, "Error", errorMessage);

    free(data.items);
    free(errorMessage);
}




