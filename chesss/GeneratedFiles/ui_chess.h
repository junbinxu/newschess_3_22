/********************************************************************************
** Form generated from reading ui file 'chess.ui'
**
** Created: Wed Mar 31 14:47:10 2010
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CHESS_H
#define UI_CHESS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chessClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *chessClass)
    {
    if (chessClass->objectName().isEmpty())
        chessClass->setObjectName(QString::fromUtf8("chessClass"));
    chessClass->resize(203, 571);
    chessClass->setBaseSize(QSize(768, 1024));
    centralWidget = new QWidget(chessClass);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    pushButton_3 = new QPushButton(centralWidget);
    pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
    pushButton_3->setGeometry(QRect(30, 510, 141, 23));
    label_5 = new QLabel(centralWidget);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(30, 0, 101, 16));
    listWidget = new QListWidget(centralWidget);
    listWidget->setObjectName(QString::fromUtf8("listWidget"));
    listWidget->setGeometry(QRect(20, 20, 171, 471));
    chessClass->setCentralWidget(centralWidget);
    menuBar = new QMenuBar(chessClass);
    menuBar->setObjectName(QString::fromUtf8("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 203, 18));
    chessClass->setMenuBar(menuBar);
    statusBar = new QStatusBar(chessClass);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    chessClass->setStatusBar(statusBar);

    retranslateUi(chessClass);

    QMetaObject::connectSlotsByName(chessClass);
    } // setupUi

    void retranslateUi(QMainWindow *chessClass)
    {
    chessClass->setWindowTitle(QApplication::translate("chessClass", "chess", 0, QApplication::UnicodeUTF8));
    pushButton_3->setText(QApplication::translate("chessClass", "refurbish", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("chessClass", "player list:", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(chessClass);
    } // retranslateUi

};

namespace Ui {
    class chessClass: public Ui_chessClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESS_H
