#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include "qtcontactform.h"



QtContactForm::QtContactForm(QWidget *parent) : 
        QFormLayout(parent), firstNameField(new QLineEdit()),
        lastNameField(new QLineEdit()),
        addressField(new QLineEdit()),
        phoneNumberField(new QLineEdit()),
        emailField(new QLineEdit()),
      bgField(new QLineEdit())
{




        //Set Label Alignment
       // label->setAlignment(Qt::AlignCenter);

         //   rightlayout->addWidget(label);

       // textLabel->
    addRow("First Name  <font color='red'>*</font>", firstNameField);
firstNameField->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 255);"));
firstNameField->setPlaceholderText("Enter First Name");
        addRow("Last Name #", lastNameField);
        lastNameField->setPlaceholderText("Enter Last Name");
    addRow("Address <font color='red'>*</font>", addressField);
    addressField->setPlaceholderText("Enter Address");
    addRow("Phone Number ", phoneNumberField);
    phoneNumberField->setPlaceholderText("Enter Phone Number");
    addRow("Email", emailField);
    emailField->setPlaceholderText("Enter Email");
    addRow("bg",bgField);
bgField->setPlaceholderText("Enter Blood Group Data");

   }

void QtContactForm::clear()
{
    firstNameField->setText("");
    lastNameField->setText("");
    addressField->setText("");
    phoneNumberField->setText("");
    emailField->setText("");
   bgField->setText("");

}
