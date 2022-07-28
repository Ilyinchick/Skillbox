#include <QApplication>
#include <QPushButton>
#include "./ui_control.h"
#include "CommadHadler.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CommandHandler window(nullptr);
    Ui::MainWindow caller;
    caller.setupUi(&window);
    window.setFixedSize(240, 680);
    window.channel = caller.lineEdit;
    window.volume = caller.lineEdit_2;
    window.printValues();
    window.show();
    return QApplication::exec();
}
