#include "chess.h"

//test
#include <QMessageBox>
chess::chess(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	
	gameWidgetBase = new GameWidgetBase();

	communicate = new Communicate();
	
	connect(communicate ,SIGNAL(errorMeg(QString ) ) , this ,SLOT(errorMeg(QString)));

    connect(communicate ,SIGNAL(dataShow(QString  )) ,this ,SLOT(dataShow(QString )));

	connect(communicate ,SIGNAL(invite(QString  )) ,this ,SLOT(invite(QString )));

	connect(communicate ,SIGNAL(isInvite(QString)) ,this ,SLOT(isInvite(QString)));

	connect(communicate ,SIGNAL(showMessage(QString) ) ,gameWidgetBase ,SLOT(showMessage(QString)));

	connect(gameWidgetBase->scene,SIGNAL(sendMegToAnother(int  ,int , int ,int )) ,communicate ,SLOT(sendGameData(int ,int ,int ,int )));
	connect(gameWidgetBase->scene,SIGNAL(sendMegToAnother(int  ,int , int ,int )) ,gameWidgetBase ,SLOT(stepLCDNumber(int ,int ,int ,int )));

	connect(communicate ,SIGNAL(gameDate(QString ) ), gameWidgetBase->scene ,SLOT(handlerAnotherData(QString)));
	connect(communicate ,SIGNAL(gameDate(QString ) ), gameWidgetBase ,SLOT(handlerAnotherData(QString)));

	connect(gameWidgetBase,SIGNAL(sendChatMessage(QString )) ,communicate,SLOT(sendChatMessage(QString )));
	
	connect(gameWidgetBase->scene,SIGNAL(result(int )) ,gameWidgetBase ,SLOT(result(int )));
    connect(gameWidgetBase->scene,SIGNAL(result(int )) ,this , SLOT(result(int )));

	communicate->sendBroadcastMeg();	
}

chess::~chess()
{

}




void chess::dataShow(QString str)
{
//    QFont font;
//    font.setBold('#000');
//    ui.listWidget->setFont(font);
    QFont font;
    font.setStyleHint(QFont::Serif);
    font.setFamily(str);
    ui.listWidget->setFont(font);
    ui.listWidget->addItem(str);
    qDebug()<<str;
}

void chess::on_pushButton_3_clicked()
{
	//刷新
	ui.listWidget->clear();
	communicate->sendBroadcastMeg();
	
}

void chess::on_listWidget_itemDoubleClicked(QListWidgetItem* item)
{
/*       //不能邀请自己
	if(communicate->hostAddress.toString() ==  item->text().split("--").at(1))
	{
		QMessageBox::information(this ,tr("title"),tr("you invite yourself!!!!"));
		return ;
	}
*/
	QMessageBox::information(this ,tr("title"),tr("you invite %1").arg(item->text()));
	
	communicate->sendGameComSend(item->text().split("--").at(1));
}

void chess::invite(QString str)
{
    int i = QMessageBox::question(this , tr("invite"),tr("now start play chess!") ,QMessageBox::Ok, QMessageBox::Cancel);
	if(QMessageBox::Ok == i)
	{
		
		///QMessageBox::information(this ,tr("invite"),tr("you invite success"));
		
		//red
		gameWidgetBase->scene->clear();
		gameWidgetBase->scene->initialChessmanState();
		gameWidgetBase->scene->userState = true;
		gameWidgetBase->scene->userType = Chessman::RED;		
		gameWidgetBase->scene->initialRedChessman();
        gameWidgetBase->timer->start(1000);
		gameWidgetBase->showFullScreen();
		communicate->sendGameConRec("ok");
	}
	else 
	{
		communicate->sendGameConRec("cancel");
	}	
}

//邀请结果反馈
void chess::isInvite(QString str)
{
    //对方接受邀请
	if(str == "ok")
	{
		//black
		gameWidgetBase->scene->clear();	
		gameWidgetBase->scene->initialChessmanState();
		gameWidgetBase->scene->userState = false;
		gameWidgetBase->scene->userType = Chessman::BLACK;			
		gameWidgetBase->scene->initialBlackChessman();
        gameWidgetBase->timer->start(1000);

		gameWidgetBase->showFullScreen();
        QMessageBox::about(NULL, "Alert", "<font color='red'>红棋先走！礼貌谦让！O(∩_∩)O~</font>");
		
	}
	else
    {//对方拒绝接受
		QMessageBox::information(this ,tr("invite failed"),tr("your invite was refused"));
	}
}

//错误提示
void chess::errorMeg(QString str)
{
	QMessageBox::information(this ,tr("error"),str);
}

//结果提示
void chess::result (int i)
{
	if(i == 0 )
	{//you win
        QMessageBox::information(gameWidgetBase ,tr("result"),tr("你赢了 !"));
	}
	else if(i == 1)
	{//you loss
        QMessageBox::information(gameWidgetBase ,tr("result"),tr("对方赢了 !"));
	}
}

