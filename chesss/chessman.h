#ifndef CHESSMAN_H
#define CHESSMAN_H

#include <QGraphicsPixmapItem>
#include <QPoint>
#include <QPointF>
#include "chessscene.h"
class ChessScene;

static const int originX = 43;
static const int originY = 38;
static const int rectWidth = 60;
static const int rectHeight = 61;

//chessman base object
class Chessman : public QGraphicsPixmapItem
{
	//Q_OBJECT
public:
        enum Type{BLACK,RED};//Chessman::BLACK黑棋type为0 Chessman::RED 红棋type为1
public:
	Chessman(const QPixmap & pixmap,int x = 0,int y = 0);
	~Chessman();

public:
	int x;
	int y;
	int pixmapWidth;
	int pixmapHeight;
	Type type;
	int Jiang ;//is 0 or 1 if 1 delegate jiang 
	QPointF oldMousePos;	

	int tempX ;
	int tempY ;	

public:		
	 bool setPosXY();
	 void moveBaseCondition(); 
	
	 void setType(Type t){ type = t; }
	 Type getType(){return type;}

public:
	void mousePressEvent( QGraphicsSceneMouseEvent * event );	
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

public:
	//virtual void mouseReleaseEventChess(QGraphicsSceneMouseEvent *event) = 0;

	void mouseReleaseEventChess(QGraphicsSceneMouseEvent *event) ;

	virtual bool moveSecCondition(){return false;}

	virtual bool moveConditionFormChessman( ){ return true; }
	
	bool handlerChessmanArrivePlace();


};


//车
class ChessmanC : public Chessman
{
public:
	ChessmanC(const QPixmap & pixmap,int x = 0 ,int y = 0);
	//void mouseReleaseEventChess(QGraphicsSceneMouseEvent* event);	
	 bool moveSecCondition();
	 bool moveConditionFormChessman();
};



//马
class ChessmanM : public Chessman
{
public:
	ChessmanM(const QPixmap & pixmap,int x = 0 ,int y = 0);
	bool moveSecCondition();
	bool moveConditionFormChessman( );
};



//相 象
class ChessmanX : public Chessman
{
public:
	ChessmanX(const QPixmap & pixmap,int x = 0 ,int y = 0);
	 bool moveSecCondition();
	 bool moveConditionFormChessman();
};



//士，仕
class ChessmanS : public Chessman
{
public:
	ChessmanS(const QPixmap & pixmap,int x = 0 ,int y = 0);
	 bool moveSecCondition();
	 bool moveConditionFormChessman();
};



//将，帅
class ChessmanJ : public Chessman
{
public:
	ChessmanJ(const QPixmap & pixmap,int x = 0 ,int y = 0);
	 bool moveSecCondition();
	 bool moveConditionFormChessman();
};



//炮
class ChessmanP : public Chessman
{
public:
	ChessmanP(const QPixmap & pixmap,int x = 0 ,int y = 0);
	 bool moveSecCondition();
	 bool moveConditionFormChessman( );
};



//兵 卒
class ChessmanB : public Chessman
{
public:
	ChessmanB(const QPixmap & pixmap,int x = 0 ,int y = 0);
	bool moveSecCondition();
	bool moveConditionFormChessman( );

	void setInitY(int ty){ initY = ty; }
	int getInitY(){ return initY ;}
private:
	int initY;
};

#endif // CHESSMAN_H
