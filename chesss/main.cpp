#include <QtGui/QApplication>
#include "chess.h"
#include<QTextCodec>
int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(chess);

	QApplication a(argc, argv);

    //解决中文乱码问题
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    //end
	chess w;
	w.show();
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
	return a.exec();
}
