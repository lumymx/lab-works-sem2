/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QWidget *centralwidget;
    QPushButton *BtnMemRead;
    QLineEdit *EditInput;
    QPushButton *BtnMemClear;
    QPushButton *BtnMemPlus;
    QPushButton *BtnMemMinus;
    QPushButton *BtnDel;
    QPushButton *Btn7;
    QPushButton *Btn8;
    QPushButton *Btn9;
    QPushButton *BtnRoot;
    QPushButton *BtnClear;
    QPushButton *Btn4;
    QPushButton *Btn5;
    QPushButton *Btn6;
    QPushButton *Btn1;
    QPushButton *Btn2;
    QPushButton *Btn3;
    QPushButton *Btn0;
    QPushButton *BtnPercent;
    QPushButton *BtnMinus;
    QPushButton *BtnPlus;
    QPushButton *BtnPlusMinus;
    QPushButton *BtnPoint;
    QPushButton *BtnEquals;
    QPushButton *BtnDiv;
    QPushButton *BtnMult;
    QPushButton *BtnSin;
    QPushButton *BtnCos;
    QPushButton *BtnTan;
    QPushButton *BtnCot;
    QTextBrowser *BrowserResult;
    QPushButton *BtnPower;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName("Calculator");
        Calculator->resize(300, 350);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Calculator->sizePolicy().hasHeightForWidth());
        Calculator->setSizePolicy(sizePolicy);
        Calculator->setMinimumSize(QSize(300, 350));
        Calculator->setMaximumSize(QSize(300, 350));
        centralwidget = new QWidget(Calculator);
        centralwidget->setObjectName("centralwidget");
        BtnMemRead = new QPushButton(centralwidget);
        BtnMemRead->setObjectName("BtnMemRead");
        BtnMemRead->setGeometry(QRect(0, 100, 50, 50));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        BtnMemRead->setFont(font);
        EditInput = new QLineEdit(centralwidget);
        EditInput->setObjectName("EditInput");
        EditInput->setGeometry(QRect(0, 0, 300, 50));
        QFont font1;
        font1.setPointSize(18);
        EditInput->setFont(font1);
        BtnMemClear = new QPushButton(centralwidget);
        BtnMemClear->setObjectName("BtnMemClear");
        BtnMemClear->setGeometry(QRect(50, 100, 50, 50));
        BtnMemClear->setFont(font);
        BtnMemPlus = new QPushButton(centralwidget);
        BtnMemPlus->setObjectName("BtnMemPlus");
        BtnMemPlus->setGeometry(QRect(100, 100, 50, 50));
        BtnMemPlus->setFont(font);
        BtnMemMinus = new QPushButton(centralwidget);
        BtnMemMinus->setObjectName("BtnMemMinus");
        BtnMemMinus->setGeometry(QRect(150, 100, 50, 50));
        BtnMemMinus->setFont(font);
        BtnDel = new QPushButton(centralwidget);
        BtnDel->setObjectName("BtnDel");
        BtnDel->setGeometry(QRect(200, 100, 50, 50));
        BtnDel->setFont(font);
        Btn7 = new QPushButton(centralwidget);
        Btn7->setObjectName("Btn7");
        Btn7->setGeometry(QRect(0, 150, 50, 50));
        Btn7->setFont(font);
        Btn8 = new QPushButton(centralwidget);
        Btn8->setObjectName("Btn8");
        Btn8->setGeometry(QRect(50, 150, 50, 50));
        Btn8->setFont(font);
        Btn9 = new QPushButton(centralwidget);
        Btn9->setObjectName("Btn9");
        Btn9->setGeometry(QRect(100, 150, 50, 50));
        Btn9->setFont(font);
        BtnRoot = new QPushButton(centralwidget);
        BtnRoot->setObjectName("BtnRoot");
        BtnRoot->setGeometry(QRect(150, 150, 50, 50));
        BtnRoot->setFont(font);
        BtnClear = new QPushButton(centralwidget);
        BtnClear->setObjectName("BtnClear");
        BtnClear->setGeometry(QRect(200, 150, 50, 50));
        BtnClear->setFont(font);
        Btn4 = new QPushButton(centralwidget);
        Btn4->setObjectName("Btn4");
        Btn4->setGeometry(QRect(0, 200, 50, 50));
        Btn4->setFont(font);
        Btn5 = new QPushButton(centralwidget);
        Btn5->setObjectName("Btn5");
        Btn5->setGeometry(QRect(50, 200, 50, 50));
        Btn5->setFont(font);
        Btn6 = new QPushButton(centralwidget);
        Btn6->setObjectName("Btn6");
        Btn6->setGeometry(QRect(100, 200, 50, 50));
        Btn6->setFont(font);
        Btn1 = new QPushButton(centralwidget);
        Btn1->setObjectName("Btn1");
        Btn1->setGeometry(QRect(0, 250, 50, 50));
        Btn1->setFont(font);
        Btn2 = new QPushButton(centralwidget);
        Btn2->setObjectName("Btn2");
        Btn2->setGeometry(QRect(50, 250, 50, 50));
        Btn2->setFont(font);
        Btn3 = new QPushButton(centralwidget);
        Btn3->setObjectName("Btn3");
        Btn3->setGeometry(QRect(100, 250, 50, 50));
        Btn3->setFont(font);
        Btn0 = new QPushButton(centralwidget);
        Btn0->setObjectName("Btn0");
        Btn0->setGeometry(QRect(0, 300, 50, 50));
        Btn0->setFont(font);
        BtnPercent = new QPushButton(centralwidget);
        BtnPercent->setObjectName("BtnPercent");
        BtnPercent->setGeometry(QRect(150, 200, 50, 50));
        BtnPercent->setFont(font);
        BtnMinus = new QPushButton(centralwidget);
        BtnMinus->setObjectName("BtnMinus");
        BtnMinus->setGeometry(QRect(200, 300, 50, 50));
        BtnMinus->setFont(font);
        BtnPlus = new QPushButton(centralwidget);
        BtnPlus->setObjectName("BtnPlus");
        BtnPlus->setGeometry(QRect(150, 300, 50, 50));
        BtnPlus->setFont(font);
        BtnPlusMinus = new QPushButton(centralwidget);
        BtnPlusMinus->setObjectName("BtnPlusMinus");
        BtnPlusMinus->setGeometry(QRect(100, 300, 50, 50));
        BtnPlusMinus->setFont(font);
        BtnPoint = new QPushButton(centralwidget);
        BtnPoint->setObjectName("BtnPoint");
        BtnPoint->setGeometry(QRect(50, 300, 50, 50));
        BtnPoint->setFont(font);
        BtnEquals = new QPushButton(centralwidget);
        BtnEquals->setObjectName("BtnEquals");
        BtnEquals->setGeometry(QRect(250, 300, 51, 50));
        BtnEquals->setFont(font);
        BtnEquals->setStyleSheet(QString::fromUtf8("background-color: orange;"));
        BtnDiv = new QPushButton(centralwidget);
        BtnDiv->setObjectName("BtnDiv");
        BtnDiv->setGeometry(QRect(200, 250, 50, 50));
        BtnDiv->setFont(font);
        BtnMult = new QPushButton(centralwidget);
        BtnMult->setObjectName("BtnMult");
        BtnMult->setGeometry(QRect(150, 250, 50, 50));
        BtnMult->setFont(font);
        BtnSin = new QPushButton(centralwidget);
        BtnSin->setObjectName("BtnSin");
        BtnSin->setGeometry(QRect(250, 100, 50, 50));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        BtnSin->setFont(font2);
        BtnCos = new QPushButton(centralwidget);
        BtnCos->setObjectName("BtnCos");
        BtnCos->setGeometry(QRect(250, 150, 50, 50));
        BtnCos->setFont(font2);
        BtnTan = new QPushButton(centralwidget);
        BtnTan->setObjectName("BtnTan");
        BtnTan->setGeometry(QRect(250, 200, 50, 50));
        BtnTan->setFont(font2);
        BtnCot = new QPushButton(centralwidget);
        BtnCot->setObjectName("BtnCot");
        BtnCot->setGeometry(QRect(250, 250, 50, 50));
        BtnCot->setFont(font2);
        BrowserResult = new QTextBrowser(centralwidget);
        BrowserResult->setObjectName("BrowserResult");
        BrowserResult->setGeometry(QRect(0, 50, 300, 50));
        BrowserResult->setFont(font1);
        BtnPower = new QPushButton(centralwidget);
        BtnPower->setObjectName("BtnPower");
        BtnPower->setGeometry(QRect(200, 200, 50, 50));
        BtnPower->setFont(font);
        Calculator->setCentralWidget(centralwidget);

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QCoreApplication::translate("Calculator", "MainWindow", nullptr));
        BtnMemRead->setText(QCoreApplication::translate("Calculator", "MR", nullptr));
        EditInput->setText(QString());
        BtnMemClear->setText(QCoreApplication::translate("Calculator", "MC", nullptr));
        BtnMemPlus->setText(QCoreApplication::translate("Calculator", "M+", nullptr));
        BtnMemMinus->setText(QCoreApplication::translate("Calculator", "M-", nullptr));
        BtnDel->setText(QCoreApplication::translate("Calculator", "DEL", nullptr));
        Btn7->setText(QCoreApplication::translate("Calculator", "7", nullptr));
        Btn8->setText(QCoreApplication::translate("Calculator", "8", nullptr));
        Btn9->setText(QCoreApplication::translate("Calculator", "9", nullptr));
        BtnRoot->setText(QCoreApplication::translate("Calculator", "\342\210\232", nullptr));
        BtnClear->setText(QCoreApplication::translate("Calculator", "CE", nullptr));
        Btn4->setText(QCoreApplication::translate("Calculator", "4", nullptr));
        Btn5->setText(QCoreApplication::translate("Calculator", "5", nullptr));
        Btn6->setText(QCoreApplication::translate("Calculator", "6", nullptr));
        Btn1->setText(QCoreApplication::translate("Calculator", "1", nullptr));
        Btn2->setText(QCoreApplication::translate("Calculator", "2", nullptr));
        Btn3->setText(QCoreApplication::translate("Calculator", "3", nullptr));
        Btn0->setText(QCoreApplication::translate("Calculator", "0", nullptr));
        BtnPercent->setText(QCoreApplication::translate("Calculator", "%", nullptr));
        BtnMinus->setText(QCoreApplication::translate("Calculator", "-", nullptr));
        BtnPlus->setText(QCoreApplication::translate("Calculator", "+", nullptr));
        BtnPlusMinus->setText(QCoreApplication::translate("Calculator", "+/-", nullptr));
        BtnPoint->setText(QCoreApplication::translate("Calculator", ".", nullptr));
        BtnEquals->setText(QCoreApplication::translate("Calculator", "=", nullptr));
        BtnDiv->setText(QCoreApplication::translate("Calculator", "\303\267", nullptr));
        BtnMult->setText(QCoreApplication::translate("Calculator", "\303\227", nullptr));
        BtnSin->setText(QCoreApplication::translate("Calculator", "SIN", nullptr));
        BtnCos->setText(QCoreApplication::translate("Calculator", "COS", nullptr));
        BtnTan->setText(QCoreApplication::translate("Calculator", "TAN", nullptr));
        BtnCot->setText(QCoreApplication::translate("Calculator", "COT", nullptr));
        BrowserResult->setHtml(QCoreApplication::translate("Calculator", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:18pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        BtnPower->setText(QCoreApplication::translate("Calculator", "^", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
