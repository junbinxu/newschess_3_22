#include "chessman.h"
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QMessageBox>
#include <QObject>
#include <QGraphicsItem>

//test
#include <QMainWindow>
#include <QString>
Chessman::Chessman(const QPixmap & pixmap,int x,int y):QGraphicsPixmapItem(pixmap)
{
	this->x = x;
	this->y = y;

	tempX = 0 ;
	tempY = 0 ;

	Jiang = 0 ;

	pixmapWidth = pixmap.width();
	pixmapHeight = pixmap.height();

	this->setFlag(QGraphicsItem::ItemIsMovable);
	//this->setFlag(QGraphicsItem::ItemIsSelectable);
	this->setZValue(0);
	
	setPosXY();
	
}
Chessman::~Chessman()
{
}


bool Chessman::setPosXY()
{
	
	QGraphicsPixmapItem::setPos(originX-pixmapWidth/2 + rectWidth*x,originY-pixmapHeight/2+rectHeight*y);

	return true;
}

void Chessman::mousePressEvent ( QGraphicsSceneMouseEvent * event ) 
{	
		QGraphicsPixmapItem::mousePressEvent(event);	
}

void Chessman::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsPixmapItem::mouseMoveEvent(event);
}

void Chessman::mouseReleaseEventChess(QGraphicsSceneMouseEvent *event)
{
	oldMousePos = this->scenePos();	

	float fx = ((( oldMousePos.x()+pixmapWidth/2)  - ( originX + rectWidth*x) )/rectWidth);
	if(fx < 0)
	{
		tempX =  (int)(fx-0.5);
	}
	else
	{
		tempX = (int )(fx+0.5);
	}
	float fy = (((oldMousePos.y()+pixmapHeight/2) - ( originY + rectHeight*y) )/rectHeight);
	if(fy < 0 )
	{
		tempY = (int )(fy - 0.5);
	}
	else
	{
		tempY = (int )(fy + 0.5);
	}	

	if( tempX == 0 && tempY == 0)
	{
		tempX = 0 ;
		tempY = 0 ;
	}
	else
	{
		if((x + tempX) < 0 || (y + tempY) < 0|| (x + tempX) > 8  || (y + tempY) > 9)
		{
			tempX = 0 ;
			tempY = 0 ;
		}
		else
		{
			if( ! moveSecCondition())
			{
				 tempX = 0 ;
				 tempY = 0 ;
			}
			else
			{
				if( ! moveConditionFormChessman())
				{
					tempX = 0 ;
					tempY = 0 ;
				}
				else
				{
                    //send a message another client
					((ChessScene*)(this->scene()))->sendMessageToAnother(x ,y ,tempX ,tempY);
				}
			}
		}
	}	
	x += tempX;
	y += tempY;
	QGraphicsPixmapItem::mouseReleaseEvent(event);
}
	
bool Chessman::handlerChessmanArrivePlace()
{
		ChessScene* cs = (ChessScene*)this->scene();
	
		if( cs->chessmanState[x+tempX][y+tempY] == true )
		{
			
			QList<QGraphicsItem*> list= cs->items(originX-pixmapWidth/2 + rectWidth*(x+tempX),originY-pixmapHeight/2+rectHeight*(y+tempY),pixmapWidth,pixmapHeight);
			Chessman* tempItem  = 0 ;
			for(int j = list.size()-1 ;j >= 0 ; j--)
			{
					tempItem= ( Chessman*)(list.at(j));
					if( tempItem  != this)
					{
						break;
					}
			}		
			
			if(tempItem == 0)
			{
				return false;
			}
			if(this ->type == tempItem->type)
			{
				return false;
			}
			else
			{
				tempItem->setVisible(false);
				//cs->removeItem(tempItem);
				cs->chessmanState[x][y] = false;				
				return true;
			}
		}
		else
		{			
				cs->chessmanState[x+tempX][y+tempY] = true;
				cs->chessmanState[x][y] = false;
				return true;
		}
}

//////////////////////////////////////////
//车
ChessmanC::ChessmanC(const QPixmap & pixmap,int x,int y):Chessman(pixmap ,x,y)
{

}
/*
void ChessmanC::mouseReleaseEventChess(QGraphicsSceneMouseEvent* event )
{	
	oldMousePos = this->scenePos();	
	moveBaseCondition();
	setPosXY();
	QGraphicsPixmapItem::mouseReleaseEvent(event);
}
*/
bool ChessmanC::moveSecCondition()
{	
	
	if((tempX == 0 && tempY != 0) || (tempX != 0 && tempY == 0) )
	{		
	}else 
	{
        QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
		return false;
	}	
	return true;
}
bool ChessmanC::moveConditionFormChessman()
{
	int i = 0 ;
	ChessScene* cs = (ChessScene*)this->scene();
	//QMainWindow *mw = new QMainWindow();
	//QMessageBox::information(mw,str,QString("cs->chessmanState[x+i][y] == true )"));
					
	if( tempX != 0 )
	{
		if(tempX < 0)
		{
			i = tempX *(-1);
			i --;
			for( ;i > 0  ; i --)
			{
				if( cs->chessmanState[x-i][y] == true )
				{
					QString str ;
					str.setNum(i);
                    QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
					return  false;					
				}
			}
			i = -1;
		}
		else
		{
			i = tempX;
			i --;
			for( ;i > 0  ; i --)
			{
				if( cs->chessmanState[x+i][y] == true )
				{
                    QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
					return  false;
				}
			}
			i =1;
		}
		if( cs->chessmanState[x+tempX][y] == true )
		{
			
			QList<QGraphicsItem*> list= cs->items(originX-pixmapWidth/2 + rectWidth*(x+tempX),originY-pixmapHeight/2+rectHeight*(y+tempY),pixmapWidth,pixmapHeight);
			Chessman* tempItem  = 0 ;
			for(int j = list.size()-1 ;j >= 0 ; j--)
			{
					tempItem= ( Chessman*)(list.at(j));
					if( tempItem  != this)
					{
						break;
					}
			}	
			
			if(tempItem == 0)
            {
                QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
				return false;
			}
			if(this ->type == tempItem->type)
			{
                QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
				return false;
			}
			else
			{
				tempItem->setVisible(false);
				cs->removeItem(tempItem);
				cs->chessmanState[x][y] = false;				
				return true;
			}

		}
		else
		{			
				cs->chessmanState[x+tempX][y] = true;
				cs->chessmanState[x][y] = false;
		}

	}
	else if(tempY != 0)
	{
		if(tempY < 0 )
		{
			i = tempY *(-1);
			i --;
			for( ;i > 0  ; i --)
			{
				if( cs->chessmanState[x][y-i] == true )
				{
                    QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
					return  false;
				}
			}
		}
		else if(tempY > 0)
		{
			i = tempY ;i --;
			for( ;i > 0  ; i --)
			{
				if( cs->chessmanState[x][y+i] == true )
				{
                    QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
					return  false;
				}
			}

		}		
		if( cs->chessmanState[x][y+tempY] == true )
		{
			
			QList<QGraphicsItem*> list= cs->items(originX-pixmapWidth/2 + rectWidth*(x+tempX),originY-pixmapHeight/2+rectHeight*(y+tempY),pixmapWidth,pixmapHeight);
			Chessman* tempItem  = 0 ;
			for(int j = list.size()-1 ;j >= 0 ; j--)
			{
					tempItem= ( Chessman*)(list.at(j));
					if( tempItem  != this)
					{
						break;
					}
			}				
			if(tempItem == 0)
			{
                QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
				return false;
			}
			if(this ->type == tempItem->type)
			{
                QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
				return false;
			}
			else
			{
				tempItem->setVisible(false);				
				cs->removeItem(tempItem);
				cs->chessmanState[x][y] = false;
				return true;
			}
		}
		else
		{
				cs->chessmanState[x][y+tempY] = true;
				cs->chessmanState[x][y] = false;
		}
	}	
return  true;
}




/////////////////////////
//马  走“日”

ChessmanM::ChessmanM(const QPixmap & pixmap,int x ,int y ):Chessman(pixmap ,x,y)
{
}

bool ChessmanM::moveSecCondition()
{
/*	int tempX ;

	int tempY ;
	
	float fx = ((( oldMousePos.x()+pixmapWidth/2)  - ( originX + rectWidth*x) )/rectWidth);
	if(fx < 0)
	{
		tempX =  (int)(fx-0.5);
	}
	else
	{
		tempX = (int )(fx+0.5);
	}

	float fy = (((oldMousePos.y()+pixmapHeight/2) - ( originY + rectHeight*y) )/rectHeight);
	if(fy < 0 )
	{
		tempY = (int )(fy - 0.5);
	}
	else
	{
		tempY = (int )(fy + 0.5);
	}
	

	if((x + tempX) < 0 || (y + tempY) < 0|| (x + tempX) > 8  || (y + tempY) > 9)
	{
		return false;
	}
*/
	if((tempX*tempX + tempY*tempY) != 5)
    {//限定马走“日”字
        QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
		return false;
	}
	
	return true;
}


bool ChessmanM::moveConditionFormChessman()
{ //马走动的时候，不能有棋子挡着
	ChessScene* cs = (ChessScene*)this->scene();
	
	if(tempX > 0 && tempY > 0)
	{
		if( cs->chessmanState[x+tempX-1][y+tempY -1] == true)
        {
            QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
			return false;
		}
	}
	else if(tempX < 0 && tempY < 0)
	{
		if( cs->chessmanState[x+tempX+1][y+tempY +1] == true)
		{
            QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
			return false;
		}

	}
	else if(tempX < 0 && tempY > 0)
	{
		if( cs->chessmanState[x+tempX+1][y+tempY -1] == true)
		{
            QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
			return false;
		}

	}
	else if(tempX > 0 && tempY < 0)
	{
		if( cs->chessmanState[x+tempX-1][y+tempY +1] == true)
		{
            QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
			return false;
		}

	}
	return handlerChessmanArrivePlace();
}







///////////////////////
//相 象 走田字

ChessmanX::ChessmanX(const QPixmap & pixmap,int x ,int y):Chessman(pixmap ,x,y)
{
	
}
bool ChessmanX::moveSecCondition()
{
	if((tempY*tempY + tempX*tempX) != 8)
	{
        QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
		return false;
	}
	if(y < 5 && (tempY+y)>4)
	{
        QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
		return false;
	}
	if(y >4 && (tempY+y)< 5)
	{
        QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
		return false;
	}
	
	return true;

}

bool ChessmanX::moveConditionFormChessman()
{	//相走的 “田”字中间不能有棋子挡着,不然走法错误
	ChessScene* cs = (ChessScene*)this->scene();
	
	if(tempX > 0 && tempY > 0)
	{
		if( cs->chessmanState[x+tempX-1][y+tempY -1] == true)
		{
            QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
			return false;
		}
	}
	else if(tempX < 0 && tempY < 0)
	{
		if( cs->chessmanState[x+tempX+1][y+tempY +1] == true)
		{
            QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
			return false;
		}

	}
	else if(tempX < 0 && tempY > 0)
	{
		if( cs->chessmanState[x+tempX+1][y+tempY -1] == true)
		{
            QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
			return false;
		}

	}
	else if(tempX > 0 && tempY < 0)
	{
		if( cs->chessmanState[x+tempX-1][y+tempY +1] == true)
		{
            QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
			return false;
		}

	}
	return handlerChessmanArrivePlace();
}
////////////////////////
//士，仕

ChessmanS::ChessmanS(const QPixmap & pixmap,int x  ,int y ):Chessman(pixmap ,x,y)
{
}
bool ChessmanS::moveSecCondition()
{
	if( ( tempX * tempX ) + ( tempY * tempY ) != 2 )
	{
        QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
		return false;
	}
	if( ( tempX + x ) > 5 || ( tempX + x ) < 3 )
	{
        QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
		return false;
	}
	if( y < 3)
	{
		if( (tempY + y ) > 2 )
		{
            QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
			return false;
		}
	}
	else if(y > 6)
	{
		if( ( tempY + y ) < 7 )
		{
            QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
			return false;
		}		
	}
	else 
	{
        QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
		return false;
	}
	
	
	return true;
}

bool ChessmanS::moveConditionFormChessman()
{
	return handlerChessmanArrivePlace();
}

/////////////////////
//将，帅
ChessmanJ::ChessmanJ(const QPixmap & pixmap,int x ,int y):Chessman(pixmap ,x,y)
{
}
bool ChessmanJ::moveSecCondition()
{
	if( ( tempX * tempX ) + ( tempY * tempY ) != 1 )
	{
        QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
		return false;
	}
	if( ( tempX + x ) > 5 || ( tempX + x ) < 3  )
	{
        QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
		return false;
	}
	
	if( y < 3  )
	{
		if( (tempY + y ) > 2  )
		{
            QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
			return false;
		}
		
	}
	else if(  y > 6  )
	{
		if( (tempY + y ) < 7 )
		{
            QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
			return false;
		}
	}else 
	{
        QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
		return false;
	}
	
	return true;
}

bool ChessmanJ::moveConditionFormChessman()
{	
	//have a handler 
	return handlerChessmanArrivePlace();
}


/////////////////////////
//炮  --- 走法规则还存在问题！！！

ChessmanP::ChessmanP(const QPixmap & pixmap,int x ,int y ):Chessman(pixmap ,x,y)
{

}
bool ChessmanP::moveSecCondition()
{
	if((tempX == 0 && tempY != 0) || (tempX != 0 && tempY == 0) )
	{		
	}else 
    {
        QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
		return false;
	}	
	return true;
}

bool ChessmanP::moveConditionFormChessman()
{	

	ChessScene* cs = (ChessScene*)this->scene();
	
	int count = 0 ;
	if(tempX > 0 )
	{
		for(int i = tempX-1 ; i > 0 ; i --)
		{
			if( cs->chessmanState[x+i][y] == true )
			{
				count++;				
			}
		}
	}
	else if(tempX < 0) 
	{
		for(int i = tempX+1 ; i < 0 ; i++)
		{
			if( cs->chessmanState[x+i][y] == true )
			{
				count++;				
			}
		}
	}
	else if(tempY > 0 )
	{
		for(int i = tempY-1 ; i > 0 ; i --)
		{
			if( cs->chessmanState[x][y+i] == true )
			{
				count++;				
			}
		}
	}
	else if(tempY < 0 )
	{
		for(int i = tempY+1 ; i < 0 ; i++)
		{
			if( cs->chessmanState[x][y+i] == true )
			{
				count++;				
			}
		}
	}

	
	if(count == 1 )
	{
		if( cs->chessmanState[x+tempX][y+tempY] == false )
        {  //炮走动时，普通走动中间不能隔着棋子
            QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
			return false;
		}
        return handlerChessmanArrivePlace();
	}
	else if (count == 0 )
	{
		if( cs->chessmanState[x+tempX][y+tempY] == true )
        {  //不能将炮放在自己的棋子上面
            QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
			return false;
		}
		else
		{				
			cs->chessmanState[x+tempX][y+tempY] =true;
			cs->chessmanState[x][y] = false;
			return true;
		}		
	}
    //不能中间没有隔着棋子就将炮放在对方棋子上面
    QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
	return false;

	
}
///////////////////////////
//兵 卒

ChessmanB::ChessmanB(const QPixmap & pixmap,int x ,int y):Chessman(pixmap ,x,y)
{
		initY = y;
}
bool ChessmanB::moveSecCondition()
{
	if( ( tempX * tempX ) + ( tempY * tempY ) != 1 )
	{

        QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
		return false;
	}
	if(initY == 3 )
	{
		if(tempY < 0)
        {
            QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
			return false;
		}
		else if( tempY == 0 )
		{
			if(y < 5 )
			{
                QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
				return false;
			}
		}
	}
	else if( initY == 6)
	{
		if(tempY > 0)
        {
            QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
			return false;
		}
		else if( tempY == 0 )
		{
			if( y > 4 )
			{
                QMessageBox::about(NULL, "Alert", "<font color='red'>走法错误！</font>");
				return false;
			}
		}
	}	
	return true;
}

bool ChessmanB::moveConditionFormChessman(){	return handlerChessmanArrivePlace();}

