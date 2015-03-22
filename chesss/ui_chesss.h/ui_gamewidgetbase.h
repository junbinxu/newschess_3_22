/********************************************************************************
** Form generated from reading UI file 'gamewidgetbase.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGETBASE_H
#define UI_GAMEWIDGETBASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
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
        label->setGeometry(QRect(650, 660, 71, 31));
        lineEditSendmesage = new QLineEdit(GameWidgetBaseClass);
        lineEditSendmesage->setObjectName(QString::fromUtf8("lineEditSendmesage"));
        lineEditSendmesage->setGeometry(QRect(730, 660, 281, 31));
        textEditReciveMessge = new QTextEdit(GameWidgetBaseClass);
        textEditReciveMessge->setObjectName(QString::fromUtf8("textEditReciveMessge"));
        textEditReciveMessge->setGeometry(QRect(660, 230, 351, 411));
        label_2 = new QLabel(GameWidgetBaseClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(710, 50, 81, 21));
        lcdNumber_step = new QLCDNumber(GameWidgetBaseClass);
        lcdNumber_step->setObjectName(QString::fromUtf8("lcdNumber_step"));
        lcdNumber_step->setGeometry(QRect(810, 50, 101, 21));
        widgetChessboard = new QWidget(GameWidgetBaseClass);
        widgetChessboard->setObjectName(QString::fromUtf8("widgetChessboard"));
        widgetChessboard->setGeometry(QRect(30, 60, 594, 648));
        lcdNumber_alltime = new QLCDNumber(GameWidgetBaseClass);
        lcdNumber_alltime->setObjectName(QString::fromUtf8("lcdNumber_alltime"));
        lcdNumber_alltime->setGeometry(QRect(810, 110, 101, 20));
        label_4 = new QLabel(GameWidgetBaseClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(730, 110, 71, 21));
        label_3 = new QLabel(GameWidgetBaseClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(680, 170, 111, 31));
        lcdNumber_current = new QLCDNumber(GameWidgetBaseClass);
        lcdNumber_current->setObjectName(QString::fromUtf8("lcdNumber_current"));
        lcdNumber_current->setGeometry(QRect(810, 170, 101, 31));
        lcdNumber_current->setProperty("value", QVariant(30));
        pushButton = new QPushButton(GameWidgetBaseClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(940, 50, 75, 21));
        pushButton_2 = new QPushButton(GameWidgetBaseClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(940, 110, 75, 21));

        retranslateUi(GameWidgetBaseClass);

        QMetaObject::connectSlotsByName(GameWidgetBaseClass);
    } // setupUi

    void retranslateUi(QWidget *GameWidgetBaseClass)
    {
        GameWidgetBaseClass->setWindowTitle(QApplication::translate("GameWidgetBaseClass", "GameWidgetBase", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GameWidgetBaseClass", "<html><head/><body><p><span style=\" font-family:'\345\256\213\344\275\223'; font-size:11pt; font-weight:600;\">\345\217\221\351\200\201\346\266\210\346\201\257:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("GameWidgetBaseClass", "<html><head/><body><p><span style=\" font-family:'\345\256\213\344\275\223'; font-size:12pt; font-weight:600;\">\345\275\223\345\211\215\346\255\245\346\225\260:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("GameWidgetBaseClass", "<html><head/><body><p><span style=\" font-family:'\345\256\213\344\275\223'; font-size:12pt; font-weight:600; color:#000000;\">\346\200\273\350\256\241\346\227\266:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("GameWidgetBaseClass", "<html><head/><body><p><span style=\" font-family:'\345\256\213\344\275\223'; font-size:12pt; font-weight:600;\">\346\200\235\350\200\203\345\211\251\344\275\231\346\227\266\351\227\264:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("GameWidgetBaseClass", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("GameWidgetBaseClass", "ENW GAME", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GameWidgetBaseClass: public Ui_GameWidgetBaseClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGETBASE_H
