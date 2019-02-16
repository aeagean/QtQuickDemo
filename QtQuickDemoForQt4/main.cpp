#include <QApplication>
#include <QDeclarativeView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QDeclarativeView viewer;
    viewer.setSource(QUrl::fromLocalFile(QLatin1String("main.qml")));
    viewer.show();
    return app.exec();
}
