#include "calculator.h"
#include "./ui_calculator.h"
#include "./operations.h"
#include "./utility.h"
#include "qpushbutton.h"
#include <cmath>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    connect(ui->Btn0, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ui->Btn1, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ui->Btn2, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ui->Btn3, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ui->Btn4, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ui->Btn5, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ui->Btn6, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ui->Btn7, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ui->Btn8, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ui->Btn9, SIGNAL(clicked()), this, SLOT(numberClicked()));

    connect(ui->BtnPlus, SIGNAL(clicked()), this, SLOT(operatorClicked()));
    connect(ui->BtnMinus, SIGNAL(clicked()), this, SLOT(operatorClicked()));
    connect(ui->BtnMult, SIGNAL(clicked()), this, SLOT(operatorClicked()));
    connect(ui->BtnDiv, SIGNAL(clicked()), this, SLOT(operatorClicked()));
    connect(ui->BtnPercent, SIGNAL(clicked()), this, SLOT(operatorClicked()));
    connect(ui->BtnPower, SIGNAL(clicked()), this, SLOT(operatorClicked()));

    connect(ui->BtnSin, SIGNAL(clicked()), this, SLOT(functionClicked()));
    connect(ui->BtnCos, SIGNAL(clicked()), this, SLOT(functionClicked()));
    connect(ui->BtnTan, SIGNAL(clicked()), this, SLOT(functionClicked()));
    connect(ui->BtnCot, SIGNAL(clicked()), this, SLOT(functionClicked()));
    connect(ui->BtnRoot, SIGNAL(clicked()), this, SLOT(functionClicked()));

    connect(ui->BtnMemRead, SIGNAL(clicked()), this, SLOT(memoryClicked()));
    connect(ui->BtnMemClear, SIGNAL(clicked()), this, SLOT(memoryClicked()));
    connect(ui->BtnMemPlus, SIGNAL(clicked()), this, SLOT(memoryClicked()));
    connect(ui->BtnMemMinus, SIGNAL(clicked()), this, SLOT(memoryClicked()));

    connect(ui->BtnClear, SIGNAL(clicked()), this, SLOT(clearClicked()));
    connect(ui->BtnDel, SIGNAL(clicked()), this, SLOT(deleteClicked()));
    connect(ui->BtnPlusMinus, SIGNAL(clicked()), this, SLOT(negateClicked()));
    connect(ui->BtnPoint, SIGNAL(clicked()), this, SLOT(pointClicked()));
    connect(ui->BtnEquals, SIGNAL(clicked()), this, SLOT(equalsClicked()));

    ui->EditInput->setText("0");
    ui->BrowserResult->setText("0");
    ui->EditInput->setFocusPolicy(Qt::TabFocus);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::numberClicked()
{
    if (ui->BrowserResult->toPlainText() != "Error" && !ui->EditInput->text().contains("e")) {
        QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
        QString digitValue = clickedButton->text();
        QString inputValue = ui->EditInput->text();
        if (!(inputValue == "0" && digitValue == "0.0")) {
            if (inputValue == "0")
                inputValue = "";
            if(ui->EditInput->text().length() <= maxLength)
                ui->EditInput->setText(inputValue + digitValue);
        }
        unblockOperations();
    }
}

void Calculator::operatorClicked()
{
    if (operation != NONE) {
        operand2 = ui->EditInput->text().toDouble();
        commitOperation();
    }
    if(ui->BrowserResult->toPlainText() == "0")
        operand1 = ui->EditInput->text().toDouble();
    else
        operand1 = ui->BrowserResult->toPlainText().toDouble();
    QPushButton* button = (QPushButton*)sender();
    QString buttonText = button->text();
    if (buttonText == "+")
        operation = ADD;
    else if (buttonText == "-")
        operation = SUBTRACT;
    else if (buttonText == "×")
        operation = MULTIPLY;
    else if (buttonText == "÷")
        operation = DIVIDE;
    else if (buttonText == "%")
        operation = PERCENT;
    else if (buttonText == "^")
        operation = POWER;
    ui->EditInput->setText("");
    blockOperations();
}


void Calculator::functionClicked()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    std::string functionName = labelToFunction(clickedButton->text().toStdString());
    double inputValue = ui->EditInput->text().toDouble();
    QString result = QString::fromStdString(calculateOperationResult(inputValue, 0, functionName, maxLength));
    ui->BrowserResult->setText(result);
    ui->EditInput->setText(ui->BrowserResult->toPlainText());
    operand1 = 0;
}

void Calculator::memoryClicked()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    QString buttonText = clickedButton->text();
    if (buttonText == "MR")
        ui->EditInput->setText(QString::number(memory));
    else if (buttonText == "MC")
        memory = 0;
    else if (buttonText == "M+")
        memory += ui->EditInput->text().toDouble();
    else if (buttonText == "M-")
        memory -= ui->EditInput->text().toDouble();
}

void Calculator::clearClicked()
{
    ui->EditInput->setText("0");
    ui->BrowserResult->setText("0");
    ui->BtnClear->setStyleSheet("../../stylesheets/Combinear.qss");
}

void Calculator::deleteClicked()
{
    QString text = ui->EditInput->text();
    if (!text.isEmpty() && text != "0" && !text.contains("e"))
    {
        text.remove(text.length() - 1, 1);
        ui->EditInput->setText(text);
    }
}


void Calculator::negateClicked()
{
    double inputValue = ui->EditInput->text().toDouble();
    ui->EditInput->setText(QString::number(inputValue * -1));
}

void Calculator::pointClicked()
{
    QString text = ui->EditInput->text();
    if (!text.contains('.') && text != "-")
    {
        text.append('.');
        ui->EditInput->setText(text);
    }
}


void Calculator::equalsClicked()
{
    operand2 = ui->EditInput->text().toDouble();
    commitOperation();
    if (ui->BrowserResult->toPlainText() != "Error")
        ui->EditInput->setText(ui->BrowserResult->toPlainText());
    else
        ui->EditInput->setText("");
    operation = NONE;
    operand2 = 0;
}

void Calculator::commitOperation()
{
    if (ui->BrowserResult->toPlainText() != "Error") {
        std::string result = ui->EditInput->text().toStdString();
        switch (operation) {
        case ADD:
            result = calculateOperationResult(operand1, operand2, "add", maxLength);
            break;
        case SUBTRACT:
            result = calculateOperationResult(operand1, operand2, "sub", maxLength);
            break;
        case MULTIPLY:
            result = calculateOperationResult(operand1, operand2, "mult", maxLength);
            break;
        case DIVIDE:
            result = calculateOperationResult(operand1, operand2, "div", maxLength);
            break;
        case PERCENT:
            result = calculateOperationResult(operand1, operand2, "percent", maxLength);
            break;
        case POWER:
            result = calculateOperationResult(operand1, operand2, "pow", maxLength);
            break;
        default:
            break;
        }
        ui->BrowserResult->setText(QString::fromStdString(result));
        operand1 = QString::fromStdString(result).toDouble();
        if (result == "Error")
            ui->BtnClear->setStyleSheet("background-color: red;");
    }
}

void Calculator::blockOperations()
{
    blockButton(ui->BtnPlus);
    blockButton(ui->BtnMinus);
    blockButton(ui->BtnMult);
    blockButton(ui->BtnDiv);
    blockButton(ui->BtnPercent);
    blockButton(ui->BtnPower);

    blockButton(ui->BtnSin);
    blockButton(ui->BtnCos);
    blockButton(ui->BtnTan);
    blockButton(ui->BtnCot);
    blockButton(ui->BtnRoot);
}

void Calculator::unblockOperations()
{
    unblockButton(ui->BtnPlus);
    unblockButton(ui->BtnMinus);
    unblockButton(ui->BtnMult);
    unblockButton(ui->BtnDiv);
    unblockButton(ui->BtnPercent);
    unblockButton(ui->BtnPower);

    unblockButton(ui->BtnSin);
    unblockButton(ui->BtnCos);
    unblockButton(ui->BtnTan);
    unblockButton(ui->BtnCot);
    unblockButton(ui->BtnRoot);
}

void Calculator::blockButton(QPushButton* Button)
{
    Button->setStyleSheet("background-color: white;");
    Button->setEnabled(false);
    Button->setFocusPolicy(Qt::NoFocus);
}

void Calculator::unblockButton(QPushButton* Button)
{
    Button->setStyleSheet("../../stylesheets/Combinear.qss");
    Button->setEnabled(true);
    Button->setFocusPolicy(Qt::ClickFocus);
}
