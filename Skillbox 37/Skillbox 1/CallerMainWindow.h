#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <iostream>
#include <string>
#include <QString>

class CallerMainWindow : public QMainWindow {
    Q_OBJECT

public:

    QLineEdit *answer = nullptr;

    QLineEdit *field1 = nullptr;

    QLineEdit *field2 = nullptr;

    CallerMainWindow(QWidget* parent = nullptr) : QMainWindow(parent){}

public slots:

    void addButtonClick() {
        answer->setText(QString::number(field1->text().toInt() + field2->text().toInt()));
    };

    void subButtonClick() {
        answer->setText(QString::number(field1->text().toInt() -  field2->text().toInt()));
    };

    void multipleButtonClick() {
        answer->setText(QString::number(field1->text().toInt() *  field2->text().toInt()));
    };

    void divisionButtonClick() {
        if (field2->text().toInt() == 0) answer->setText("Error");
            else answer->setText(QString::number(field1->text().toFloat() / field2->text().toFloat()));
    };

};