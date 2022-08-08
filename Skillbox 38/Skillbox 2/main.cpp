#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPlainTextEdit>

#include <QWebEngineView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    QHBoxLayout layout(&w);
    QWebEngineView view;
    QPlainTextEdit text;

    layout.addWidget(&text, 1);
    layout.addWidget(&view, 1);

    view.setMinimumSize(100, 100);
    text.setMinimumSize(100, 100);

    layout.setContentsMargins(10, 10, 10, 10);

    text.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    view.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QObject::connect(&text, &QPlainTextEdit::textChanged, [&text, &view] () {
        view.setHtml(text.toPlainText());
        view.update();
    });

    view.setHtml("<h1> Start typing </h1>");

    w.show();
    return a.exec();
}
