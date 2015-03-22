#ifndef CHESS_H
#define CHESS_H

#include <QtGui/QMainWindow>
#include "ui_chess.h"
#include "gamewidgetbase.h"
#include "communicate.h"
#include <QString>

class chess : public QMainWindow
{
	Q_OBJECT

public:
	chess(QWidget *parent = 0, Qt::WFlags flags = 0);
	~chess();

private:
	Ui::chessClass ui;
	GameWidgetBase *gameWidgetBase;

	Communicate *communicate;

private slots:
	void on_listWidget_itemDoubleClicked(QListWidgetItem*);
	void on_pushButton_3_clicked();
	
	void dataShow(QString str);
	void invite(QString str);
	void isInvite(QString str);

	void errorMeg(QString str);

	void result(int);

};

#endif // CHESS_H
