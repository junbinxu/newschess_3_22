/********************************************************************************
** Form generated from reading ui file 'gamewidgetbase.ui'
**
** Created: Wed Mar 31 14:47:10 2010
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GAMEWIDGETBASE_H
#define UI_GAMEWIDGETBASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWidgetBaseClass
{
public:
    QLabel *label;
    QLineEdit *lineEditSendmesage;
    QTextEdit *textEditReciveMessge;
    QLabel *label_2;
    QLCDNumber *lcdNumber_step;
    QWidget *widgetChessboard;
    QLCDNumber *lcdNumber_alltime;
    QLabel *label_4;
    QLabel *label_3;
    QLCDNumber *lcdNumber_current;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *GameWidgetBaseClass)
    {
    if (GameWidgetBaseClass->objectName().isEmpty())
        GameWidgetBaseClass->setObjectName(QString::fromUtf8("GameWidgetBaseClass"));
    GameWidgetBaseClass->resize(1024, 768);
    label = new QLabel(GameWidgetBaseClass);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(640, 660, 81, 31));
    lineEditSendmesage = new QLineEdit(GameWidgetBaseClass);
    lineEditSendmesage->setObjectName(QString::fromUtf8("lineEditSendmesage"));
    lineEditSendmesage->setGeometry(QRect(730, 660, 271, 31));
    textEditReciveMessge = new QTextEdit(GameWidgetBaseClass);
    textEditReciveMessge->setObjectName(QString::fromUtf8("textEditReciveMessge"));
    textEditReciveMessge->setGeometry(QRect(660, 230, 351, 411));
    label_2 = new QLabel(GameWidgetBaseClass);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(690, 50, 61, 21));
    lcdNumber_step = new QLCDNumber(GameWidgetBaseClass);
    lcdNumber_step->setObjectName(QString::fromUtf8("lcdNumber_step"));
    lcdNumber_step->setGeometry(QRect(790, 50, 91, 21));
    widgetChessboard = new QWidget(GameWidgetBaseClass);
    widgetChessboard->setObjectName(QString::fromUtf8("widgetChessboard"));
    widgetChessboard->setGeometry(QRect(30, 60, 594, 648));
    lcdNumber_alltime = new QLCDNumber(GameWidgetBaseClass);
    lcdNumber_alltime->setObjectName(QString::fromUtf8("lcdNumber_alltime"));
    lcdNumber_alltime->setGeometry(QRect(790, 110, 111, 20));
    label_4 = new QLabel(GameWidgetBaseClass);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(670, 110, 101, 21));
    label_3 = new QLabel(GameWidgetBaseClass);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(660, 170, 161, 31));
    lcdNumber_current = new QLCDNumber(GameWidgetBaseClass);
    lcdNumber_current->setObjectName(QString::fromUtf8("lcdNumber_current"));
    lcdNumber_current->setGeometry(QRect(800, 170, 111, 31));
    lcdNumber_current->setProperty("value", QVariant(30));
    pushButton = new QPushButton(GameWidgetBaseClass);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(920, 50, 75, 21));
    pushButton_2 = new QPushButton(GameWidgetBaseClass);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setGeometry(QRect(940, 110, 75, 21));

    retranslateUi(GameWidgetBaseClass);

    QMetaObject::connectSlotsByName(GameWidgetBaseClass);
    } // setupUi

    void retranslateUi(QWidget *GameWidgetBaseClass)
    {
    GameWidgetBaseClass->setWindowTitle(QApplication::translate("GameWidgetBaseClass", "GameWidgetBase", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("GameWidgetBaseClass", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600;\">message:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("GameWidgetBaseClass", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:13pt; font-weight:600;\">STEP:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("GameWidgetBaseClass", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:13pt; font-weight:600; color:#000000;\">ALL TIME:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("GameWidgetBaseClass", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; font-weight:600;\">CURRENT:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("GameWidgetBaseClass", "back", 0, QApplication::UnicodeUTF8));
    pushButton_2->setText(QApplication::translate("GameWidgetBaseClass", "ENW GAME", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(GameWidgetBaseClass);
    } // retranslateUi

};

namespace Ui {
    class GameWidgetBaseClass: public Ui_GameWidgetBaseClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGETBASE_H
