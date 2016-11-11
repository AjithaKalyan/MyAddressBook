//#include <QCoreApplication>
//#include <QApplication>
//#include <QtSql/QSql>
//#include <QtSql/QSqlDatabase>
//#include <QtSql/QSqlDriver>
//#include <QtSql/QSqlQuery>
//#include <QDebug>

#include <QtGui>
#include <QtSql>
#include<QTableView>
#include <QApplication>
#include<QTableWidget>
#include<QMessageBox>

bool createConnection();

//int main(int argc, char *argv[])
//{
  //  QApplication app(argc, argv);
    //if (!createConnection()){

      //  qDebug() << "Not connected!";
        //return 1;
   // }
    //else{

      //  qDebug() << "Connected!";

       // QSqlQuery query;
        //query.exec("SELECT * FROM contacts");

        //while (query.next()) {
          //  QString firstname = query.value(1).toString();
            //QString lastname = query.value(2).toString();
            //QString phonenum = query.value(3).toString();
            //QString  address = query.value(4).toString();
            //QString city = query.value(5).toString();
            //qDebug() << "first name:" << firstname;
            //qDebug() << "last name:" << lastname;
            //qDebug() << "phone number:" << phonenum;
            //qDebug() << "address" << address;
            //qDebug() << "city" << city;
        //}

        //return 0;
    //}
    //return app.exec();
//}

//bool createConnection(){
  // QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
 //QSqlDatabase db = QSqlDatabase::addDatabase("address");
    //db.setHostName("localhost");
    //db.setDatabaseName("address");
    //db.setUserName("root");
    //db.setPassword("root");
    //if (!db.open()) {
      //  qDebug() << "Database error occurred";
        //return false;
   // }
int main(int argc,char* argv[])
{
QApplication app(argc,argv);
QTableWidget* table = new QTableWidget();
table->setWindowTitle("Connect to Mysql Database Example");
QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
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
index++;
}
table->show();
return app.exec();
}

    //return true;
//}
