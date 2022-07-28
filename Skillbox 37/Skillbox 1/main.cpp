#include <QApplication>
#include <QPushButton>
#include "./ui_caller.h"
#include "CallerMainWindow.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    CallerMainWindow window(nullptr);
    Ui::MainWindow caller;
    caller.setupUi(&window);
    window.answer = caller.lineEdit_3;
    window.field1 = caller.lineEdit;
    window.field2 = caller.lineEdit_2;
    window.show();
    return QApplication::exec();

}
