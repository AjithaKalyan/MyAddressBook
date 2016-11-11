#include <QtGui>
#include <QtSql>
#include<QTableView>
#include <QApplication>
#include<QTableWidget>
#include<QMessageBox>

#include "testmysqlexample.h"

int main(int argc,char* argv[])
{
QApplication app(argc,argv);
TestMySQLExample *t=new TestMySQLExample();
t->test();
return app.exec();
}


