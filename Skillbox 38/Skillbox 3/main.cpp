#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <iostream>
#include <QImage>
#include <QGraphicsEffect>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsBlurEffect>
#include <QFileDialog>

QString globalPath = "D:\\", startImageName = "Nagart.jpg";

QImage blurImage(QImage source, int value) {
    if (source.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));
    auto* blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(value);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(), QRectF(0, 0, source.width(), source.height()));
    return result;
}


class MyLabel : public QLabel {

    QPixmap image;

private:
    QString path;

public:
    MyLabel(QWidget* parent) {
        setParent(parent);
        path = globalPath + startImageName;
        image = QPixmap(path);
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        setGeometry(image.rect());
    }

    void paintEvent(QPaintEvent *event) override {
        QPainter p(this);
        p.drawPixmap(event->rect(), image);
    }

    QString getPath() {
        return path;
    }

    void setPath(QString _path) {
        path = _path;
        image = QPixmap(path);
        update();
    }

    void setImage(QPixmap _image) {
        image = _image;
        update();
    }

    QPixmap getImage() {
        return image;
    }

};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget widget(nullptr);
    QVBoxLayout layout(&widget);

    MyLabel label(&widget);
    QSlider slider(&widget);
    QPushButton button("Open");

    slider.setOrientation(Qt::Orientation::Horizontal);

    layout.addWidget(&label);
    layout.addWidget(&slider);
    layout.addWidget(&button);

    slider.setMinimum(0);
    slider.setMaximum(100);

    widget.resize(300, 300);

    QObject::connect(&button, &QPushButton::clicked, [&label]() {
        label.setPath(QFileDialog::getOpenFileName(nullptr, "File browser", globalPath, "images (*.jpg *.JPG)"));
    });

    QObject::connect(&slider, &QSlider::valueChanged, [&slider, &button, &label]() {
        label.setImage(QPixmap::fromImage(blurImage(QImage(label.getPath()), slider.value())));
    });

    widget.show();
    return QApplication::exec();
}
