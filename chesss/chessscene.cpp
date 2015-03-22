#include "chessscene.h"
#include "gamewidgetbase.h"
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
//test
#include <QGraphicsRectItem>
#include <QPointF>
#include <QRectF>
#include <QMessageBox>
#include <QMainWindow>
#include <QString>

ChessScene::ChessScene(QObject *parent)
	: QGraphicsScene(parent)
{

	movingItem = 0;
	setBackground();	
}
void ChessScene::setBackground()
{//set background
	QBrush pixmapBrush((QPixmap(":/Resources/background.jpg").scaled(560, 625)));
    this->setBackgroundBrush(pixmapBrush);
    this->setSceneRect(QRect(0, 0, 560, 625));

}
ChessScene::~ChessScene()
{

}
//初始化黑棋方棋盘
void ChessScene::initialBlackChessman()
{
	QPixmap pixmap(":/Resources/BLACK_C.png");
	ChessmanC *chessmanC1 = new ChessmanC(pixmap ,0,9);
	ChessmanC *chessmanC2 = new ChessmanC(pixmap ,8,9);
	this->addItem(chessmanC1);	
	this->addItem(chessmanC2);
	
	QPixmap pixmapm(":/Resources/BLACK_M.png");
	ChessmanM * chessmanM1 = new ChessmanM(pixmapm,1,9);
	ChessmanM * chessmanM2 = new ChessmanM(pixmapm,7,9);
	this->addItem(chessmanM1);	
	this->addItem(chessmanM2);
	
	QPixmap pixmapx(":/Resources/BLACK_X.png");
	ChessmanX * chessmanX1 = new ChessmanX(pixmapx,2,9);
	ChessmanX * chessmanX2 = new ChessmanX(pixmapx,6,9);
	this->addItem(chessmanX1);	
	this->addItem(chessmanX2);
	
	QPixmap pixmaps(":/Resources/BLACK_S.png");
	ChessmanS * chessmanS1 = new ChessmanS(pixmaps,3,9);
	ChessmanS * chessmanS2 = new ChessmanS(pixmaps,5,9);
	this->addItem(chessmanS1);	
	this->addItem(chessmanS2); 
	
	QPixmap pixmapj(":/Resources/BLACK_J.png");
	ChessmanJ * chessmanJ1 = new ChessmanJ(pixmapj,4,9);	
	chessmanJ1->Jiang = 1 ;
	this->addItem(chessmanJ1);	
	

	QPixmap pixmapp(":/Resources/BLACK_P.png");
	ChessmanP * chessmanP1 = new ChessmanP(pixmapp,1,7);
	ChessmanP * chessmanP2 = new ChessmanP(pixmapp,7,7);
	this->addItem(chessmanP1);	
	this->addItem(chessmanP2);

	QPixmap pixmapb(":/Resources/BLACK_Z.png");
	ChessmanB * chessmanB1 = new ChessmanB(pixmapb,0,6);
	ChessmanB * chessmanB2 = new ChessmanB(pixmapb,2,6);
	ChessmanB * chessmanB3 = new ChessmanB(pixmapb,4,6);
	ChessmanB * chessmanB4 = new ChessmanB(pixmapb,6,6);
	ChessmanB * chessmanB5 = new ChessmanB(pixmapb,8,6);


	chessmanP1->setType(Chessman::BLACK);
	chessmanP2->setType(Chessman::BLACK);

	chessmanC1->setType(Chessman::BLACK);
	chessmanC2->setType(Chessman::BLACK);

	chessmanM1->setType(Chessman::BLACK);
	chessmanM2->setType(Chessman::BLACK);

	chessmanX1->setType(Chessman::BLACK);
	chessmanX2->setType(Chessman::BLACK);

	chessmanS1->setType(Chessman::BLACK);
	chessmanS2->setType(Chessman::BLACK);

	
	chessmanB1->setType(Chessman::BLACK);
	chessmanB2->setType(Chessman::BLACK);
	chessmanB3->setType(Chessman::BLACK);
	chessmanB4->setType(Chessman::BLACK);
	chessmanB5->setType(Chessman::BLACK);

	chessmanJ1->setType(Chessman::BLACK);
 
	this->addItem(chessmanB1);	
	this->addItem(chessmanB2);
	this->addItem(chessmanB3);
	this->addItem(chessmanB4);
	this->addItem(chessmanB5);


	
	QPixmap pixmapr(":/Resources/RED_C.png");
	ChessmanC *chessmanC1r = new ChessmanC(pixmapr ,0,0);
	ChessmanC *chessmanC2r = new ChessmanC(pixmapr ,8,0);
	this->addItem(chessmanC1r);	
	this->addItem(chessmanC2r);

	QPixmap pixmapmr(":/Resources/RED_M.png");
	ChessmanM * chessmanM1r = new ChessmanM(pixmapmr,1,0);
	ChessmanM * chessmanM2r = new ChessmanM(pixmapmr,7,0);
	this->addItem(chessmanM1r);	
	this->addItem(chessmanM2r);

	QPixmap pixmapxr(":/Resources/RED_X.png");
	ChessmanX * chessmanX1r = new ChessmanX(pixmapxr,2,0);
	ChessmanX * chessmanX2r = new ChessmanX(pixmapxr,6,0);
	this->addItem(chessmanX1r);	
	this->addItem(chessmanX2r);

	QPixmap pixmapsr(":/Resources/RED_S.png");
	ChessmanS * chessmanS1r = new ChessmanS(pixmapsr,3,0);
	ChessmanS * chessmanS2r = new ChessmanS(pixmapsr,5,0);
	this->addItem(chessmanS1r);	
	this->addItem(chessmanS2r);

	QPixmap pixmapjr(":/Resources/RED_J.png");
	ChessmanJ * chessmanJ1r = new ChessmanJ(pixmapjr,4,0);	
	chessmanJ1r->Jiang = 1 ;
	this->addItem(chessmanJ1r);	

	QPixmap pixmappr(":/Resources/RED_P.png");
	ChessmanP * chessmanP1r = new ChessmanP(pixmappr,1,2);
	ChessmanP * chessmanP2r = new ChessmanP(pixmappr,7,2);
	this->addItem(chessmanP1r);	
	this->addItem(chessmanP2r);

	QPixmap pixmapbr(":/Resources/RED_Z.png");
	ChessmanB * chessmanB1r = new ChessmanB(pixmapbr,0,3);
	ChessmanB * chessmanB2r = new ChessmanB(pixmapbr,2,3);
	ChessmanB * chessmanB3r = new ChessmanB(pixmapbr,4,3);
	ChessmanB * chessmanB4r = new ChessmanB(pixmapbr,6,3);
	ChessmanB * chessmanB5r = new ChessmanB(pixmapbr,8,3);
	
	this->addItem(chessmanB1r);	
	this->addItem(chessmanB2r);
	this->addItem(chessmanB3r);
	this->addItem(chessmanB4r);
	this->addItem(chessmanB5r);

	chessmanP1r->setType(Chessman::RED);
	chessmanP2r->setType(Chessman::RED);

	chessmanC1r->setType(Chessman::RED);
	chessmanC2r->setType(Chessman::RED);

	chessmanM1r->setType(Chessman::RED);
	chessmanM2r->setType(Chessman::RED);

	chessmanX1r->setType(Chessman::RED);
	chessmanX2r->setType(Chessman::RED);

	chessmanS1r->setType(Chessman::RED);
	chessmanS2r->setType(Chessman::RED);

	
	chessmanB1r->setType(Chessman::RED);
	chessmanB2r->setType(Chessman::RED);
	chessmanB3r->setType(Chessman::RED);
	chessmanB4r->setType(Chessman::RED);
	chessmanB5r->setType(Chessman::RED);

	chessmanJ1r->setType(Chessman::RED);	

}
//初始化红棋方棋盘
void ChessScene::initialRedChessman()
{
	QPixmap pixmapr(":/Resources/RED_C.png");
	ChessmanC *chessmanC1r = new ChessmanC(pixmapr ,0,9);
	ChessmanC *chessmanC2r = new ChessmanC(pixmapr ,8,9);
	this->addItem(chessmanC1r);	
	this->addItem(chessmanC2r);

	QPixmap pixmapmr(":/Resources/RED_M.png");
	ChessmanM * chessmanM1r = new ChessmanM(pixmapmr,1,9);
	ChessmanM * chessmanM2r = new ChessmanM(pixmapmr,7,9);
	this->addItem(chessmanM1r);	
	this->addItem(chessmanM2r);

	QPixmap pixmapxr(":/Resources/RED_X.png");
	ChessmanX * chessmanX1r = new ChessmanX(pixmapxr,2,9);
	ChessmanX * chessmanX2r = new ChessmanX(pixmapxr,6,9);
	this->addItem(chessmanX1r);	
	this->addItem(chessmanX2r);

	QPixmap pixmapsr(":/Resources/RED_S.png");
	ChessmanS * chessmanS1r = new ChessmanS(pixmapsr,3,9);
	ChessmanS * chessmanS2r = new ChessmanS(pixmapsr,5,9);
	this->addItem(chessmanS1r);	
	this->addItem(chessmanS2r);

	QPixmap pixmapjr(":/Resources/RED_J.png");
	ChessmanJ * chessmanJ1r = new ChessmanJ(pixmapjr,4,9);	
	this->addItem(chessmanJ1r);	
		chessmanJ1r->Jiang = 1 ;

	QPixmap pixmappr(":/Resources/RED_P.png");
	ChessmanP * chessmanP1r = new ChessmanP(pixmappr,1,7);
	ChessmanP * chessmanP2r = new ChessmanP(pixmappr,7,7);
	this->addItem(chessmanP1r);	
	this->addItem(chessmanP2r);

	QPixmap pixmapbr(":/Resources/RED_Z.png");
	ChessmanB * chessmanB1r = new ChessmanB(pixmapbr,0,6);
	ChessmanB * chessmanB2r = new ChessmanB(pixmapbr,2,6);
	ChessmanB * chessmanB3r = new ChessmanB(pixmapbr,4,6);
	ChessmanB * chessmanB4r = new ChessmanB(pixmapbr,6,6);
	ChessmanB * chessmanB5r = new ChessmanB(pixmapbr,8,6);
	
	this->addItem(chessmanB1r);	
	this->addItem(chessmanB2r);
	this->addItem(chessmanB3r);
	this->addItem(chessmanB4r);
	this->addItem(chessmanB5r);

	chessmanP1r->setType(Chessman::RED);
	chessmanP2r->setType(Chessman::RED);

	chessmanC1r->setType(Chessman::RED);
	chessmanC2r->setType(Chessman::RED);

	chessmanM1r->setType(Chessman::RED);
	chessmanM2r->setType(Chessman::RED);

	chessmanX1r->setType(Chessman::RED);
	chessmanX2r->setType(Chessman::RED);

	chessmanS1r->setType(Chessman::RED);
	chessmanS2r->setType(Chessman::RED);

	
	chessmanB1r->setType(Chessman::RED);
	chessmanB2r->setType(Chessman::RED);
	chessmanB3r->setType(Chessman::RED);
	chessmanB4r->setType(Chessman::RED);
	chessmanB5r->setType(Chessman::RED);

	chessmanJ1r->setType(Chessman::RED);
 



	QPixmap pixmap(":/Resources/BLACK_C.png");
	ChessmanC *chessmanC1 = new ChessmanC(pixmap ,0,0);
	ChessmanC *chessmanC2 = new ChessmanC(pixmap ,8,0);
	this->addItem(chessmanC1);	
	this->addItem(chessmanC2);
	
	QPixmap pixmapm(":/Resources/BLACK_M.png");
	ChessmanM * chessmanM1 = new ChessmanM(pixmapm,1,0);
	ChessmanM * chessmanM2 = new ChessmanM(pixmapm,7,0);
	this->addItem(chessmanM1);	
	this->addItem(chessmanM2);
	
	QPixmap pixmapx(":/Resources/BLACK_X.png");
	ChessmanX * chessmanX1 = new ChessmanX(pixmapx,2,0);
	ChessmanX * chessmanX2 = new ChessmanX(pixmapx,6,0);
	this->addItem(chessmanX1);	
	this->addItem(chessmanX2);
	
	QPixmap pixmaps(":/Resources/BLACK_S.png");
	ChessmanS * chessmanS1 = new ChessmanS(pixmaps,3,0);
	ChessmanS * chessmanS2 = new ChessmanS(pixmaps,5,0);
	this->addItem(chessmanS1);	
	this->addItem(chessmanS2); 
	
	QPixmap pixmapj(":/Resources/BLACK_J.png");
	ChessmanJ * chessmanJ1 = new ChessmanJ(pixmapj,4,0);	
	this->addItem(chessmanJ1);	
	chessmanJ1->Jiang = 1 ;
	

	QPixmap pixmapp(":/Resources/BLACK_P.png");
	ChessmanP * chessmanP1 = new ChessmanP(pixmapp,1,2);
	ChessmanP * chessmanP2 = new ChessmanP(pixmapp,7,2);
	this->addItem(chessmanP1);	
	this->addItem(chessmanP2);

	QPixmap pixmapb(":/Resources/BLACK_Z.png");
	ChessmanB * chessmanB1 = new ChessmanB(pixmapb,0,3);
	ChessmanB * chessmanB2 = new ChessmanB(pixmapb,2,3);
	ChessmanB * chessmanB3 = new ChessmanB(pixmapb,4,3);
	ChessmanB * chessmanB4 = new ChessmanB(pixmapb,6,3);
	ChessmanB * chessmanB5 = new ChessmanB(pixmapb,8,3);


	chessmanP1->setType(Chessman::BLACK);
	chessmanP2->setType(Chessman::BLACK);

	chessmanC1->setType(Chessman::BLACK);
	chessmanC2->setType(Chessman::BLACK);

	chessmanM1->setType(Chessman::BLACK);
	chessmanM2->setType(Chessman::BLACK);

	chessmanX1->setType(Chessman::BLACK);
	chessmanX2->setType(Chessman::BLACK);

	chessmanS1->setType(Chessman::BLACK);
	chessmanS2->setType(Chessman::BLACK);

	
	chessmanB1->setType(Chessman::BLACK);
	chessmanB2->setType(Chessman::BLACK);
	chessmanB3->setType(Chessman::BLACK);
	chessmanB4->setType(Chessman::BLACK);
	chessmanB5->setType(Chessman::BLACK);

	chessmanJ1->setType(Chessman::BLACK);
 
	this->addItem(chessmanB1);	
	this->addItem(chessmanB2);
	this->addItem(chessmanB3);
	this->addItem(chessmanB4);
	this->addItem(chessmanB5);
}

void ChessScene::initialChessmanState()
{  
	int i = 0 ;
	int j = 0 ;

	for( i = 0 ; i <= 9 ;i++)
	{
		for(j = 0 ; j <= 8 ; j++)
		{
			if(i == 0 || i == 9)
			{
			
				chessmanState[j][i] = true;
				continue;
			}
			if( i == 3 || i == 6)
			{
				if( (j+2) % 2 == 0)
				{
				
				chessmanState[j][i] = true;
				continue;
				}
				
			}
			if( i == 2 || i == 7)
			{
				if(j == 1 || j == 7)
				{
				
					chessmanState[j][i] = true;
					continue;
				}
			}
			chessmanState[j][i] = false;
			
		}
	}

	
}

void ChessScene::mousePressEvent ( QGraphicsSceneMouseEvent *event )
{
	
	if( ! event->button() == Qt::LeftButton )
	{

      //  QMessageBox::about(NULL, "About", "About this <font color='red'>application</font>");
      //  QMessageBox::information(this ,tr("error") ,tr("have a error!"));
		return ;

	}
	if(movingItem != 0)
	{
		return;
	}

	oldMousePos.setX(event->buttonDownScenePos(Qt::LeftButton).x());
	oldMousePos.setY(event->buttonDownScenePos(Qt::LeftButton).y());
	
	if( ! itemAt(oldMousePos))
	{
		return;
	}	
	movingItem = (Chessman*)(this->itemAt(oldMousePos));
	if(movingItem == 0)
	{
		return ;
	}
	if(movingItem->type != this->userType)
	{
		movingItem = 0;
		return ;
	}
	if(!userState)
	{
		movingItem = 0;
		return ;
	}
	movingItem->setZValue(1);
	movingItem->mousePressEvent(event);	
}

void ChessScene::mouseMoveEvent ( QGraphicsSceneMouseEvent* event)
{
	if(movingItem == 0)
	{
		return;
	}		
	movingItem->mouseMoveEvent(event);		
}


void ChessScene::mouseReleaseEvent ( QGraphicsSceneMouseEvent *event )
{
	if( ! event->button() == Qt::LeftButton )
	{
		return ;
	}
	if(movingItem == 0)
	{
		return;
	}		
	
	movingItem->mouseReleaseEventChess(event);
	movingItem->setPosXY();
	movingItem->setZValue(0);
	movingItem = 0;
}

void ChessScene::sendMessageToAnother(int x ,int y , int offsetX ,int offsetY)
{
	userState = false;
	emit sendMegToAnother(x ,y ,offsetX ,offsetY);
	
}


void ChessScene::handlerAnotherData(QString str)
{
	//处理对方所走的棋子
	QStringList list = str.split("=");
	int x = list.at(0).toInt();	
	if(x == -1)
	{
		userState = true;
		return ;
	}
	else if(x == -2)
	{
		//you win
		emit result(0);
	}
	int y  = list.at(1).toInt();

	y = 9-y;
	int offsetX = list.at(2).toInt();
	int offsetY = list.at(3).toInt();
	offsetY = offsetY*(-1);

	movingItem = (Chessman*)(this->itemAt((x+offsetX)*rectWidth+originX ,(y+offsetY)*rectHeight+originY));
	//movingItem = (Chessman*)(this->itemAt(405 ,409));
	
	if(movingItem != 0 )
	{	
		movingItem->setVisible(false);
		if(movingItem->Jiang == 1)
		{
		//you loss
			emit result(1);
		//send another win meg
			emit sendMegToAnother(-2 ,-2 ,0 ,0);
		
		}
	}	

	movingItem = 0;
	movingItem = (Chessman*)(this->itemAt(x*rectWidth+originX ,y*rectHeight+originY));
	
	if(movingItem == 0 )
	{
       // QMessageBox::information(this ,tr("error") ,tr("have a error!"));
		return;
	}
	
	movingItem->x = x + offsetX;
	movingItem->y = y + offsetY;
	movingItem->setPosXY();

	chessmanState[x][y] = false;

	userState = true;
	movingItem = 0;
}



