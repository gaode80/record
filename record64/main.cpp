#include "record64.h"
#include <QtWidgets/QApplication>

#include <QTextCodec>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QCoreApplication::addLibraryPath("./");

	//QTextCodec* codec = QTextCodec::codecForName("UTF-8");//ַי¿צ2
	//QTextCodec::setCodecForTr(codec);
	//QTextCodec::setCodecForLocale(codec);
	//QTextCodec::setCodecForCStrings(codec);
	
	record64 w;
	w.show();
	return a.exec();
}
