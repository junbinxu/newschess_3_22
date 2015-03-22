#ifndef GAMEWIDGETBASE_H
#define GAMEWIDGETBASE_H

#include <QWidget>
#include "ui_gamewidgetbase.h"
#include <QGraphicsView>
#include "ChessScene.h"
#include <QKeyEvent>
#include <QTimer>

class GameWidgetBase : public QWidget
{
	Q_OBJECT

public:
	GameWidgetBase(QWidget *parent = 0);
	~GameWidgetBase();

public:
	Ui::GameWidgetBaseClass GameWidgetUi;
	QGraphicsView *view;
	ChessScene *scene;
	QTimer *timer;
protected:
	void keyPressEvent ( QKeyEvent * event ) ;//  [virtual protected]

private slots:
	void on_pushButton_2_clicked();
	void on_pushButton_clicked();
	void on_lineEditSendmesage_returnPressed();

	void showMessage(QString);

	void updateLCD();
	
	void stepLCDNumber(int , int ,int ,int );

	void handlerAnotherData(QString );

	void result(int i);

signals:
	void sendChatMessage(QString str);

public:
	void initLCDNumber();
	
};

#endif // GAMEWIDGETBASE_H
