#include "calculator.h"
#include "./ui_calculator.h"
#include "./operations.h"
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

    ui->EditInput->setMaxLength(maxLength);
    ui->EditInput->setText("0");
    ui->BrowserResult->setText("0");
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::numberClicked()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    QString digitValue = clickedButton->text();
    QString inputValue = ui->EditInput->text();
    if (!(inputValue == "0" && digitValue == "0.0")) {
        if (inputValue == "0")
            inputValue = "";
        if(ui->EditInput->text().length() <= maxLength)
            ui->EditInput->setText(inputValue + digitValue);
    }
}

void Calculator::operatorClicked()
{
    QPushButton* button = (QPushButton*)sender();
    QString buttonText = button->text();
    operand1 = ui->EditInput->text().toDouble();
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
}


void Calculator::functionClicked()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    QString functionName = clickedButton->text();
    double inputValue = ui->EditInput->text().toDouble();
    QString result = function(functionName, inputValue);
    ui->BrowserResult->setText(result);
    ui->EditInput->setText("0");
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
}

void Calculator::deleteClicked()
{
    QString text = ui->EditInput->text();
    if (!text.isEmpty() && text != "0")
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
    if (!text.contains('.'))
    {
        text.append('.');
        ui->EditInput->setText(text);
    }
}


void Calculator::equalsClicked()
{
    operand2 = ui->EditInput->text().toDouble();
    QString result;
    switch (operation) {
    case ADD:
        result = add(operand1, operand2);
        break;
    case SUBTRACT:
        result = subtract(operand1, operand2);
        break;
    case MULTIPLY:
        result = multiply(operand1, operand2);
        break;
    case DIVIDE:
        result = divide(operand1, operand2);
        break;
    case PERCENT:
        result = percent(operand1, operand2);
        break;
    case POWER:
        result = power(operand1, operand2);
        break;
    default:
        break;
    }

    ui->BrowserResult->setText(result);
    ui->EditInput->setText("0");
    operation = NONE;
    operand1 = 0;
    operand2 = 0;
}

