#include <QtGui>
#include <QtSql>
#include<QTableView>
#include <QApplication>
#include<QTableWidget>
#include<QMessageBox>

#include "testmysqlexample.h"

void  TestMySQLExample::test()
{
    table = new QTableWidget();
    table->setWindowTitle("Connect to Mysql Database Example");
    db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("address");
    db.setUserName("root");
    db.setPassword("root");
    if (!db.open())
    {
    QMessageBox::critical(0, QObject::tr("Database Error"),
    db.lastError().text());
    }
    QSqlQuery query("SELECT * FROM contacts");
    table->setColumnCount(query.record().count());
    table->setRowCount(query.size());
    int index=0;
    while (query.next())
    {
    table->setItem(index,0,new QTableWidgetItem(query.value(0).toString()));
    table->setItem(index,1,new QTableWidgetItem(query.value(1).toString()));
    table->setItem(index,2,new QTableWidgetItem(query.value(2).toString()));
    table->setItem(index,3,new QTableWidgetItem(query.value(3).toString()));
    table->setItem(index,4,new QTableWidgetItem(query.value(4).toString()));
    table->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 100, 255);"));
    table->item(0,0)->setBackgroundColor(Qt::red);
    table->item(0,1)->setBackgroundColor(Qt::green);
    table->item(0,2)->setBackgroundColor(Qt::blue);

    index++;
    }
    table->show();
}

