#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

class QLineEdit;
class QPushButton;

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    FindDialog(QWidget *parent = 0);
    QString getFindText();

public slots:
    void findClicked();
  //  void accept();
//private:
  //  void fillForm();
//    QtContactForm *contactForm;
//    Contact &contactToEdit;
private:
    QPushButton *findButton;
    QLineEdit *lineEdit;
    QString findText;

};
#endif
