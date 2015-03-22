#include "gamewidgetbase.h"

#include <QScrollBar>
#include <QMessageBox>
#include <QGridLayout>


GameWidgetBase::GameWidgetBase(QWidget *parent)
	: QWidget(parent)
{
	GameWidgetUi.setupUi(this);
	GameWidgetUi.textEditReciveMessge->setReadOnly(true);
	QScrollBar *bar = GameWidgetUi.textEditReciveMessge->verticalScrollBar();
	bar->setValue(bar->maximum());
	
	scene=new ChessScene();
	view = new QGraphicsView(scene);
	QGridLayout *layout  = new QGridLayout();
	layout->addWidget(view);
	this->GameWidgetUi.widgetChessboard->setLayout(layout);

	timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(updateLCD()));
    
}

GameWidgetBase::~GameWidgetBase()
{
}

void GameWidgetBase::keyPressEvent ( QKeyEvent * event )
{
	if( 1 == event->nativeScanCode())
	{
		QString s;
		s.setNum(1);
		QMessageBox::information(this,tr("aa"),s);
	}	
}


void GameWidgetBase::on_lineEditSendmesage_returnPressed()
{
	//send a message 
	QString str = GameWidgetUi.lineEditSendmesage->text();
	//send a signal
	emit sendChatMessage(str);
    GameWidgetUi.textEditReciveMessge->append(QString("我发言 : ")+str);
	GameWidgetUi.lineEditSendmesage->clear();	
}


void GameWidgetBase::showMessage(QString str)
{
    GameWidgetUi.textEditReciveMessge->append(QString("对方发言 :")+str);
}


void GameWidgetBase::updateLCD()
{
	//GameWidgetUi.lcdNumber_step->display(0);
	GameWidgetUi.lcdNumber_alltime->display( GameWidgetUi.lcdNumber_alltime->intValue() +1);
	if(GameWidgetUi.lcdNumber_current->intValue() -1> 0 )
	{
		GameWidgetUi.lcdNumber_current->display( GameWidgetUi.lcdNumber_current->intValue() -1);			
	}
	else if(GameWidgetUi.lcdNumber_current->intValue() -1 == 0)
	{
		//changel state
		this->scene->userState = false;
		this->scene->sendMessageToAnother(-1,-1 ,0,0 ) ;
		GameWidgetUi.lcdNumber_current->display(-1);
	}
	else
	{		
	}
}
void GameWidgetBase::initLCDNumber()
{
	GameWidgetUi.lcdNumber_step->display(0);
	GameWidgetUi.lcdNumber_alltime->display(0);
	if(this->scene->userType == Chessman::BLACK)
	{
		GameWidgetUi.lcdNumber_current->display(-1);
	}
	else
	{
		GameWidgetUi.lcdNumber_current->display(-1);
	}
	
}

void GameWidgetBase::handlerAnotherData(QString str)
{
	this->scene->userState = true;
	QStringList list = str.split("=");
	int x = list.at(0).toInt();	
	if(x == -1)
	{
        GameWidgetUi.textEditReciveMessge->append(QString("系统信息     ： 对方超时,默认放弃控制权."));
		//return ;
	}	
    GameWidgetUi.lcdNumber_current->display( 10 );
}

void GameWidgetBase::stepLCDNumber(int , int ,int ,int )
{
	GameWidgetUi.lcdNumber_step->display(GameWidgetUi.lcdNumber_step->intValue() +1);	
	GameWidgetUi.lcdNumber_current->display(-1);
}

void GameWidgetBase::on_pushButton_clicked()
{
    //back;返回
	this->setVisible(false);
}


void GameWidgetBase::result (int i)
{
	timer->stop();
	if(i == 0 )
	{//you win
        GameWidgetUi.textEditReciveMessge->append(QString("SYSTEM         : you win ! "));
		//QMessageBox::Information(this ,tr("result"),tr("you win !"));
	}
	else if(i == 1)
	{//you loss
        GameWidgetUi.textEditReciveMessge->append(QString("SYSTEM        : you loss ! "));
		//QMessageBox::Information(this ,tr("result"),tr("you loss !"));
	}
}


void GameWidgetBase::on_pushButton_2_clicked()
{

    //new game 重新开始游戏 ？？ todo 还得继续做
    this->scene->clear();//清除屏幕现有棋谱，再重新绘制棋子
//    this->scene->initialChessmanState();
//    this->scene->initialRedChessman();
//    this->scene->initialBlackChessman();
//    this->showFullScreen();
}

