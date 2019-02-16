#include <QtGlobal>
#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))

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

#else

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl::fromLocalFile(QLatin1String("main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

#endif
