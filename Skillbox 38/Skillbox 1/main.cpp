#include <QApplication>
#include <QPushButton>
#include <QPainter>
#include <QPaintEvent>
#include <iostream>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaContent>
#include <QVBoxLayout>

class MyButton : public QPushButton {
Q_OBJECT

private:
    QPixmap current;

    QPixmap pressed;

    QPixmap unpressed;

public:

    MyButton() = default;

    MyButton(QWidget *parent);

    QSize minimumSizeHint() const override;

    void setUp();

    void setDown();

protected:
    void paintEvent(QPaintEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

};

void MyButton::setUp() {
    current = unpressed;
    update();
}

void MyButton::setDown() {
    current = pressed;
    update();
    QTimer::singleShot(100, this, &MyButton::setUp);
}

MyButton::MyButton(QWidget *parent) {
    setParent(parent);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pressed = QPixmap(R"(C:\Users\ailyi\CLionProjects\Skillbox\Skillbox 38\Skillbox 1\images\pressed.png)");
    unpressed = QPixmap(R"(C:\Users\ailyi\CLionProjects\Skillbox\Skillbox 38\Skillbox 1\images\unpressed.png)");
    current = unpressed;
    setGeometry(current.rect());
    connect(this, &QPushButton::clicked, this, &MyButton::setDown);
}

QSize MyButton::minimumSizeHint() const {
    return {200, 200};
}

void MyButton::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    p.drawPixmap(event->rect(), current);
}

void MyButton::keyPressEvent(QKeyEvent *event) {
    setDown();
}


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget window;
    QVBoxLayout layout(&window);

    MyButton button(&window);
    layout.addWidget(&button);
    auto*  player = new QMediaPlayer;
    window.resize(150, 150);
    window.move(1000, 400);
    window.show();


    QObject::connect(&button, &QPushButton::clicked, [&player]() {
        player->setMedia(QUrl::fromLocalFile(R"(C:\Users\ailyi\CLionProjects\Skillbox\Skillbox 38\Skillbox 1\images\clicked.mp3)"));
        player->setVolume(70);
        player->play();
    });

    return QApplication::exec();
}


#include "main.moc"
