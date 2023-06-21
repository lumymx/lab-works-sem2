#include "mainwindow.h"

void MainWindow::initTable(data_region a) {
    std::string temp;
    std::stringstream stream(a.year);
    getline(stream, temp);
    QString* qstr = new QString(QString::fromStdString(temp));
    QStringList header = qstr->split(',');
    colsCount = header.size();
    for (int i = 0; i < colsCount; i++) {
        if (posRegion != -1 && posYear != -1)
            break;
        if (header[i].contains("region"))
            posRegion = i;
        if (header[i].contains("year"))
            posYear = i;
    }

    for (int i = 0; i < colsCount; i++)
        header[i] = (QString::number(i + 1, 'g', 15) + ". " + header[i]);
    ui->tableWidget->setColumnCount(colsCount);
    ui->tableWidget->setRowCount(rowsCount);
    ui->tableWidget->setHorizontalHeaderLabels(header);
    delete qstr;
}

void MainWindow::fillTable(int iterator, returnValue data) {
    std::stringstream stream(data.year);
    std::string line;
    std::string stream2;
    getline(stream, line, '\n');
    for (int j= iterator * 100; j < (rowsCount); j++) {
        getline(stream, line, '\n');
        std::stringstream stream3(line);
        for (int i = 0; i < colsCount; i++) {
            getline(stream3, stream2, ',');
            QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(stream2));
            ui->tableWidget->setItem(j, i, item);
        }
    }
}

void MainWindow::setLabelText(returnValue data) {
    ui->LabelResultMin->setText(QString::number(data.metrics[1], 'g', 15));
    ui->labelResultMed->setText(QString::number(data.metrics[0], 'g', 15));
    ui->labelResultMax->setText(QString::number(data.metrics[2], 'g', 15));
}

void MainWindow::clearTable() {
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);
    ui->lineEditRegion->setText("");
    ui->lineEditYear1->setText("");
    ui->lineEditYear2->setText("");
}

void MainWindow::clearMetrics() {
    ui->LabelResultMin->setText("");
    ui->labelResultMed->setText("");
    ui->labelResultMax->setText("");
    ui->lineEditCol->setText("");
}

void MainWindow::on_lineEditRegion_textEdited(const QString& arg1) {
    ui->lineEditCol->setEnabled(false);
    ui->btnMetrics->setEnabled(false);
}

funcArg MainWindow::getMetrics() {
    funcArg result;
    result.metricsCount = 0;
    result.metrics = (double*)malloc(sizeof(double));
    if (result.metrics != NULL) {
        int column = ui->lineEditCol->text().toInt() - 1;
        for (int i = 0; i < rowsCount; i++) {
            QString temp = ui->tableWidget->item(i, column)->text();
            if (temp != "" && temp.toDouble()) {
                result.metrics[result.metricsCount] = temp.toDouble();
                result.metricsCount++;
                result.metrics = (double*)realloc(result.metrics, sizeof(double) * (result.metricsCount + 1));
                if (result.metrics == NULL) {
                    result.metricsCount = 0;
                    break;
                }
            }
        }
    }
    return result;
}
