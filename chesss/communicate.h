#ifndef COMMUNICATE_H
#define COMMUNICATE_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
#include <QString>

class Communicate : public QObject
{
	Q_OBJECT
public:
	enum DataType{ SendBroadcast =1 , ReceiveBroadcast , MegData ,GameConSend ,GameConRec ,GameData };

public:
	Communicate(QObject *parent = 0);
	~Communicate();

private:
	QUdpSocket *udp;
	int port ;
	QHostAddress sendAddress;
public:
	QList<QHostAddress> onlineAddress; 
	QHostAddress hostAddress;
	QString username;

public:
	bool sendMessage(const QString &str);
	QString getUsername();
	bool getIP();
	void sendBroadcastMeg();
	void recBroadcastMeg();

	void sendGameComSend(const QString &str);
	void sendGameConRec(const QString &str);


public slots:
	void receiveMessage();
	void sendChatMessage(QString );
	void sendGameData(int x ,int y ,int offsetX ,int offsetY);

signals:
	void dataShow(QString str);
	void invite(QString str);
	void isInvite(QString str);

	void recChatMeg(QString);

	void showMessage(QString str);
	
	void gameDate(QString str);

	void errorMeg(QString str);
};

#endif // COMMUNICATE_H
