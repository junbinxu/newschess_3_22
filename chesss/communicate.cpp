#include "communicate.h"
#include <QStringList>
#include <QNetworkInterface>
#include <QNetworkAddressEntry>
#include <QProcess>
#include <QList>

#include <iostream>
using namespace std;
#include <QString>

Communicate::Communicate(QObject *parent)
	: QObject(parent)
{
    port = 8989;
	udp = new QUdpSocket();
    //qDebug()<<udp;
    //if(! udp->bind(port))//xujunbin
    if(! udp->bind(port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint))
	{
		emit errorMeg("port is used or have a application");
		exit(0);
	}
	connect(udp ,SIGNAL(readyRead()),this,SLOT(receiveMessage()));	
    getIP();
    username = getUsername();

}

Communicate::~Communicate()
{

}

bool Communicate::sendMessage(const QString &str)
{
	QByteArray datagram = str.toUtf8() ;
  //  qDebug()<<datagram;

	if(udp->writeDatagram(datagram.data(),datagram.size(),sendAddress,port) ==datagram.size())
	{
		return true;
	}			
	else
	{
		return false; 
	}	
}


void Communicate::receiveMessage()
{
	//enum DataType{ SendBroadcast =1 , ReceiveBroadcast , MegData ,GameConSend ,GameConRec,GameData };
	while(udp->hasPendingDatagrams())
	{
		QByteArray datagram;
		datagram.resize(udp->pendingDatagramSize());
		udp->readDatagram(datagram.data(),datagram.size());	

		QString recStr(datagram);
		
		QStringList list = recStr. split("###");
        int temp = list.at(0).toInt();
       //qDebug()<<SendBroadcast;
       // qDebug()<<ReceiveBroadcast;

		if(temp == GameData)
		{
			emit gameDate(list.at(1));
		}
		else if(temp == MegData)
		{
			emit showMessage(list.at(1));
		}
		else if(temp == SendBroadcast)
		{
			
			if( list.at(1).split("--").at(1) == hostAddress.toString())
			{
				return ;
			}
			else
			{				
				sendAddress = QHostAddress(list.at(1).split("--").at(1));

				recBroadcastMeg();
				bool b = true;
				foreach( QHostAddress addr , onlineAddress)
				{
					if( list.at(1).split("--").at(1) == addr.toString() )
					{	
						b =  false;					
					}										
				}
				if(b)
				{
					onlineAddress.append(QHostAddress(list.at(1).split("--").at(1)));
                    emit ( list.at(1));
				}
			}			
		}
		else if(temp == ReceiveBroadcast)
		{

			bool b = true;
			
			//foreach( QHostAddress addr , onlineAddress)

			QHostAddress addr ;
			for(int i = 0 ; i< onlineAddress.size() ; i++)
			{
				addr = onlineAddress.at(i);
				
				if( QString ::compare(list.at(1).split("--").at(1) , addr.toString(),Qt::CaseInsensitive) == 0)
				{		
					b =  false;
				}
				/*if( list.at(1).split("--").at(1) == addr.toString() )
				{	
					b =  false;
					
				}*/
			}
			if(b)
			{
				onlineAddress.append(QHostAddress(list.at(1).split("--").at(1)));
                emit ( list.at(1));
			}
			
		}		
		else if(temp == GameConSend)
		{
			emit invite(list.at(1));
            //emit ( list.at(1));
		}
		else if(temp == GameConRec)
		{
			emit isInvite(list.at(1));
		}
	}
} 

QString Communicate::getUsername()
{
	QString username;

	QStringList envVariables;
    envVariables << "USERNAME.*" << "USER.*" << "USERDOMAIN.*"
                 << "HOSTNAME.*" << "DOMAINNAME.*";
	QStringList environment = QProcess::systemEnvironment();
    foreach (QString string, envVariables) {
        int index = environment.indexOf(QRegExp(string));
        if (index != -1) {
            QStringList stringList = environment.at(index).split("=");
            if (stringList.size() == 2) {
                username = stringList.at(1).toUtf8();
                break;
            }
        }
    }
    if (username.isEmpty())
        username = "unknown";

	return username;
}

bool Communicate::getIP()
{
	QList<QHostAddress> broadcastAddresses;
    QList<QHostAddress> ipAddresses;

	 foreach (QNetworkInterface interface, QNetworkInterface::allInterfaces()) {
        foreach (QNetworkAddressEntry entry, interface.addressEntries()) {
            QHostAddress broadcastAddress = entry.broadcast();
            if (broadcastAddress != QHostAddress::Null &&
                entry.ip() != QHostAddress::LocalHost) {					
                broadcastAddresses << broadcastAddress;
                ipAddresses << entry.ip();		
					
            }
        }
    }

	hostAddress =  ipAddresses.at(0);
/*
    QList<QNetworkInterface> interface = QNetworkInterface::allInterfaces();

     for (int i = 0; i < interface.size(); i++)

        {

          qDebug() << interface.at(i);

           QNetworkInterface item = interface.at(i);
             QList<QNetworkAddressEntry> entryList = item.addressEntries();

        for (int j = 0; j < entryList.size(); j++)
         {

               qDebug() << 'Item #' << j << entryList.at(j).ip();
            }
        }

*/
/*    QList<QHostAddress> list = QNetworkInterface::allAddresses();

      foreach (QHostAddress address, list)
      {
         if(address.protocol() == QAbstractSocket::IPv4Protocol) //我们使用IPv4地址
             qDebug()<< address.toString();

      }
*/

    //qDebug()<<ipAddresses;
	return false;
}

void Communicate::sendBroadcastMeg()
{
	onlineAddress.clear();
	onlineAddress.append(hostAddress);
                     //  qDebug()<<onlineAddress;//这里调用显示在线的玩家ip
    emit dataShow( username+QString("--")+hostAddress.toString());
	//发送一个广播消息
	QString sendStr;
	sendStr.setNum(SendBroadcast);
	sendStr.append("###");
	sendStr.append(username);
	sendStr.append("--");
	sendStr.append(hostAddress.toString());
	sendAddress = QHostAddress::Broadcast;
	sendMessage(sendStr);
    qDebug()<<sendStr;

}

void Communicate::recBroadcastMeg()
{
	//返回一个广播消息
	QString sendStr;
	sendStr.setNum(ReceiveBroadcast);
	sendStr.append("###");
	sendStr.append(username);
	sendStr.append("--");
	sendStr.append(hostAddress.toString());
	sendMessage(sendStr);
    qDebug()<<sendStr;
}

void Communicate::sendGameComSend(const QString &str)
{
    /*GameConSend
    如果发送这个消息则相当该客户端为红子，收到这样的消息则为黑子并返回一个GameConRec消息
    */
	QString sendStr;
    sendStr.setNum(GameConSend);
	sendStr.append("###");
	sendStr.append(username);
	sendStr.append(":");
	sendStr.append(hostAddress.toString());
	sendAddress = QHostAddress(str);
	sendMessage(sendStr);
}

void Communicate::sendGameConRec(const QString &str)
{
	QString sendStr;
	sendStr.setNum(GameConRec);
	sendStr.append("###");
	sendStr.append(str);	
	//sendAddress = QHostAddress(str);
	sendMessage(sendStr);
}


void Communicate::sendChatMessage(QString str)
{
	QString sendStr;
	sendStr.setNum(MegData);
	sendStr.append("###");
	sendStr.append(str);	
	sendMessage(sendStr);
}
	
void Communicate::sendGameData(int x ,int y ,int offsetX ,int offsetY)
{
	QString sendStr;
	sendStr.setNum(GameData);
	sendStr.append("###");

	sendStr.append(QString("%1").arg(x));
	sendStr.append("=");
	sendStr.append(QString("%1").arg(y));
	sendStr.append("=");
	sendStr.append(QString("%1").arg(offsetX));
	sendStr.append("=");
	sendStr.append(QString("%1").arg(offsetY));

	sendMessage(sendStr);
}


