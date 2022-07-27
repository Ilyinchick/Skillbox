#include <QApplication>
#include <QPushButton>
#include <QPaintEvent>
#include <QWidget>
#include <QPainter>
#include <QVBoxLayout>
#include <QSlider>
#include <iostream>

class Circle : public QWidget {
Q_OBJECT

public:



    Circle() = default;

    Circle(QWidget *parent);

    QSize minimumSizeHint() const override;

    void paintEvent(QPaintEvent *event) override;

    void setGreen();

    void setYellow();

    void setRed();

private:
    QPixmap current;

    QPixmap green;

    QPixmap yellow;

    QPixmap red;

};

Circle::Circle(QWidget *parent) {
    setParent(parent);
    setToolTip("Image");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    green = QPixmap(R"(C:\Users\ailyi\CLionProjects\Skillbox\Skillbox 36\Skillbox 1\src\green.png)");
    yellow = QPixmap(R"(C:\Users\ailyi\CLionProjects\Skillbox\Skillbox 36\Skillbox 1\src\yellow.png)");
    red = QPixmap(R"(C:\Users\ailyi\CLionProjects\Skillbox\Skillbox 36\Skillbox 1\src\red.png)");
    current = green;
    setGeometry(current.rect());
}

void Circle::paintEvent(QPaintEvent *event) {
    QPainter q(this);
    q.drawPixmap(event->rect(), current);
    QWidget::paintEvent(event);
}

QSize Circle::minimumSizeHint() const {
    return QSize(100, 100);
}

void Circle::setGreen() {
    current = green;
    update();
}

void Circle::setYellow() {
    current = yellow;
    update();
}

void Circle::setRed() {
    current = red;
    update();
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *window = new QWidget;
    auto *layout = new QVBoxLayout(window);
    auto *c = new Circle(window);
    auto *slider = new QSlider(Qt::Horizontal, window);

    QObject::connect(slider, &QSlider::valueChanged, c, [&slider, &c](int i) {
        if (i < 33) c->setGreen();
        else if (i < 66) c->setYellow();
        else if (i > 66) c->setRed();
    });

    window->setFixedSize(200, 250);
    layout->addWidget(c, 0, Qt::AlignmentFlag::AlignCenter);
    layout->addWidget(slider, 0, Qt::AlignmentFlag::AlignCenter);
    slider->setMinimum(0);
    slider->setMaximum(100);

    window->show();
    return QApplication::exec();
}

#include "main.moc"