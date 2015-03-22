#ifndef CHESSSCENE_H
#define CHESSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include "chessman.h"
class Chessman;

class ChessScene : public QGraphicsScene
{
	Q_OBJECT		
public:
	ChessScene(QObject *parent = 0);
	~ChessScene();

protected:
	void mouseMoveEvent ( QGraphicsSceneMouseEvent * );
	void mousePressEvent ( QGraphicsSceneMouseEvent * );
	void mouseReleaseEvent ( QGraphicsSceneMouseEvent * );

public :
	void initialBlackChessman();

	void initialRedChessman();

	void initialChessmanState();

	void sendMessageToAnother(int x ,int y , int offsetX ,int offsetY);

	void setBackground();
	
	
private:
	QList<Chessman> listChessman;
	
	Chessman* movingItem ;
	QPointF oldMousePos;

public:
	int  userType ;//red black
	bool userState;//true go ---false not go
	bool chessmanState[9][10];

signals:
	void sendMegToAnother(int x ,int y , int offsetX ,int offsetY);
	void result(int i);


public slots:
	void handlerAnotherData(QString str);	
	
};


#endif // CHESSSCENE_H

