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

private:
    QPushButton *findButton;
    QLineEdit *lineEdit;
    QString findText;

    FindDialog::FindDialog(QWidget *parent)        : QDialog(parent)
    {
        QLabel *findLabel = new QLabel(tr("Enter the name of a contact:"));
        lineEdit = new QLineEdit;

        findButton = new QPushButton(tr("&Find"));
        findText = "";

        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(findLabel);
        layout->addWidget(lineEdit);
        layout->addWidget(findButton);

        setLayout(layout);
        setWindowTitle(tr("Find a Contact"));
        connect(findButton, SIGNAL(clicked()), this, SLOT(findClicked()));
        connect(findButton, SIGNAL(clicked()), this, SLOT(accept()));
    }
};
