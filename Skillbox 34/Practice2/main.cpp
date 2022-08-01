#include <QApplication>
#include <QPushButton>
#include <QMediaPlayer>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget window;
    auto* player = new QMediaPlayer(&window);
    window.resize(200, 100);
    window.show();
    return QApplication::exec();
}
