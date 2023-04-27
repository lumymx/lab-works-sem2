#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardItemModel>
#include "reader.h"
#include "model.h"

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
    std::string region = ui->LineEditRegion->text().toStdString();
    int column = ui->LineEditColumn->text().toInt();
    if(ui->LineEditColumn->text() == "")
        column = -1;
    QString filePath = ui->BrowserName->toPlainText();
    if (filePath == "") {
        QMessageBox::critical(this, "Error", "Please, select a file");
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
                QStandardItemModel* model = generateModel(this, data, region, column);
                ui->tableView->setModel(model);
            }
            else
                QMessageBox::critical(this, "Error", errorMessage);

            free(data.items);
            free(errorMessage);
        }
    }
}




