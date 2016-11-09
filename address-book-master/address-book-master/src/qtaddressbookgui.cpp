

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFrame>
#include <QDebug>

#include "addressbookview.h"
#include "addressbookcontroller.h"
#include "addressbookmodel.h"
#include "qtaddressbookgui.h"
#include "qtaddcontactdialog.h"
#include "qtcontactlist.h"
#include "qtcontactdetailview.h"
#include "qteditcontactdialog.h"
#include "qterrordialog.h"
#include "contact.h"
#include "finddialog.h"

QtAddressBookGUI::QtAddressBookGUI(AddressBookController &controller, AddressBookModel &model,
    QWidget *parent, Qt::WindowFlags flags) : QMainWindow(parent, flags),
    appController(controller), dataSource(model)
{
    createWidgets();
    setMinimumSize(640,480);
}

QtAddressBookGUI::~QtAddressBookGUI()
{

}
void QtAddressBookGUI::updateView()
{
    emit pullDataFromModel();
}


void QtAddressBookGUI::createWidgets()
{
    detailView = new QtContactDetailView(dataSource);

    list = new QtContactList(dataSource);
    list->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    newContactButton = new QPushButton("New Contact");


    pal.setColor( QPalette::Active, QPalette::Button, Qt::red);
    newContactButton->setPalette(pal);
    newContactButton->setAutoFillBackground(true);


//QPixmap pixmap(":/gitintro/2.jpg");
//QIcon ButtonIcon(pixmap);
//newContactButton->setIcon(ButtonIcon);
//newContactButton->setIconSize(pixmap.rect().size());

//newContactButton->setObjectName(QString::fromUtf8("newContactButton"));
//newContactButton->setIcon(QIcon(QPixmap("E:/gitintro/address-book-master/address-book-master/src/2.jpg")));
//newContactButton->show();




// QPushbutton *button = new QPushbutton;
 newContactButton->setIcon(QIcon("E:/gitintro/address-book-master/address-book-master/src/1.jpg"));

 //newContactButton->setIconSize(QSize(65,65));
//newContactButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 255);"));


 editContactButton = new QPushButton("Edit");
 deleteContactButton = new QPushButton("Delete");
 findContactButton=new QPushButton("Find");


    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(newContactButton);
    buttonLayout->addWidget(editContactButton);
    buttonLayout->addWidget(deleteContactButton);
    buttonLayout->addWidget (findContactButton);

    QVBoxLayout *rightSideLayout = new QVBoxLayout();
    rightSideLayout->addWidget(detailView);
    rightSideLayout->addLayout(buttonLayout);
//    list->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 10, 25);"));

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(list);
    mainLayout->addLayout(rightSideLayout);


//widget.setStyleSheet("background-image: url(/home/asier/imagenes/fondos/14999-Midsommarblomster.jpg);background-attachment: fixed");
   //  QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    //Connect contact list to the detail form
    connect(list, 
            SIGNAL(contactSelected(Contact::ContactId)),
            detailView,
            SLOT(displayContact(Contact::ContactId)));

    connect(newContactButton, SIGNAL(clicked()),
            this, SLOT(addContact()));

    connect(deleteContactButton, SIGNAL(clicked()),
            this, SLOT(deleteContact()));

    connect(editContactButton, SIGNAL(clicked()),
            this, SLOT(editContact()));

connect(findContactButton, SIGNAL(clicked()),
        this, SLOT(findContact()));

    //tell the sub-widgets to refresh their data from
    //
    //Will be emitted when the view is notified by
    //the model that the data has changed
    connect(this, SIGNAL(pullDataFromModel()), list,
            SLOT(refreshContactList())); 

    QFrame *mainWidget = new QFrame();
    mainWidget->setLayout(mainLayout);

    //mycode
//mainWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 100, 255);"));


  //  QString style = "QMainWindow { background-color: #fff; }";  // or other color
   // this->setStyleSheet(style);

    setCentralWidget(mainWidget);

    //Needed to get the detail view form to display
    //the initial selection at startup.
    //When the list object is first created the signals / slots
    //arent yet connected so the initial selection isn't shown
    //This manual call will cause it to update
    list->refreshContactList();
}

void QtAddressBookGUI::showUI()
{
    QMainWindow::show();
}

void QtAddressBookGUI::addContact()
{
    Contact newContact;
    QtAddContactDialog *addDialog = new QtAddContactDialog(newContact, this);
    QtErrorDialog *errDialog = new QtErrorDialog("", this);

    while(addDialog->exec())
    {
        ErrorInfo e = appController.submitContact(newContact);

        if(e.code == ERR_OK)
        {
            break;
        }
    
        //display error dialog
        errDialog->setText(e.msg.c_str());
        errDialog->exec();
    
    }
    
    //Delete the dialog objects
    //Qt only deletes them when the parent is deleted
    //If I don't delete them manually here, new ones will be made 
    //every time this function is called and only deleted when the
    //program is exited.
    delete addDialog;
    delete errDialog;
}

void QtAddressBookGUI::editContact()
{


}

void QtAddressBookGUI::deleteContact()
{
    Contact::ContactId idToDelete = list->getSelectedContactId();

    bool firstRow  = list->currentRow() == 0;
    bool onlyRowLeft = list->count() == 1;
    
    if(!onlyRowLeft)
    {
        if(firstRow)
        {
            list->setCurrentRow(list->currentRow()+1,QItemSelectionModel::SelectCurrent);
        }
        else
        {
            //It is NOT the only row left AND it is not the first row.
            //So in this case, selection moves to the previous row.
            list->setCurrentRow(list->currentRow()-1,QItemSelectionModel::SelectCurrent);
        }
    }
    
    ErrorInfo deleteErrorStatus = appController.deleteContact(idToDelete);
    if(deleteErrorStatus.code != ERR_OK)
    {
        //display error dialog
        QtErrorDialog *errDialog = new QtErrorDialog(deleteErrorStatus.msg, this);
        errDialog->exec();
        delete errDialog;
        return;
    }
}

void QtAddressBookGUI::findContact()
{
 QMessageBox msgBox;
   // msgBox.setText("Example for Find Button");
    //msgBox.setWindowTitle("Find Something");
    //msgBox.exec();
    //dialog->show();

 Contact::ContactId idTofind = list->getSelectedContactId();

 Contact editingContact;
 ErrorInfo getContactErrorStatus = dataSource.getContact(idTofind, editingContact);

 QtErrorDialog *errDialog = new QtErrorDialog("", this);

 if(getContactErrorStatus.code != ERR_OK)
 {
     //The id of the Contact user wants to edit doesn't exist
     //Should never happen since they are selecting it from a list
     //of existing id
     //display error dialog
     errDialog->setText(getContactErrorStatus.msg.c_str());
     errDialog->exec();

     //Qt only automagically deletes child objects when parent is destroyed
     //If I don't delete this here more and more dialogs will build up everytime
     //this function is called, only being destroyed when the parent window
     //(i.e. the application) is terminated.
     delete errDialog;
     return;
 }

 FindDialog *findDialog = new FindDialog(this);

 while(findDialog->exec())
 {
     ErrorInfo editErrorStatus = appController.findContact(idTofind, editingContact);

     if(editErrorStatus.code == ERR_OK)
     {
         break;
     }

     //display error dialog
     errDialog->setText(editErrorStatus.msg.c_str());
     errDialog->exec();
 }

 //see comment above about manually deleting dialogs after each run
 delete errDialog;
 delete findDialog;
}

