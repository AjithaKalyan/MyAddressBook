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
      testField(new QLineEdit())
{




        //Set Label Alignment
       // label->setAlignment(Qt::AlignCenter);

         //   rightlayout->addWidget(label);

       // textLabel->
    addRow("First Name  <font color='red'>*</font>", firstNameField);
firstNameField->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 255);"));

        addRow("Last Name #", lastNameField);
        lastNameField->setPlaceholderText("Enter Last Name");
    addRow("Address <font color='red'>*</font>", addressField);
    addRow("Phone Number ", phoneNumberField);
    addRow("Email", emailField);
    addRow("Test",testField);


   }

void QtContactForm::clear()
{
    firstNameField->setText("");
    lastNameField->setText("");
    addressField->setText("");
    phoneNumberField->setText("");
    emailField->setText("");
    testField->setAutoFillBackground(true);
}
