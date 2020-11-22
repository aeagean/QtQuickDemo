#include <QtGlobal>
#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))

#include <QApplication>
#include <QDeclarativeView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QDeclarativeView viewer;
    viewer.setSource(QUrl::fromLocalFile(QString("%1/%2").arg(MY_QML_DIR).arg("main.qml")));
    viewer.show();
    return app.exec();
}

#else

#include <QApplication>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQuickView viewer;
    viewer.setSource(QUrl::fromLocalFile(QString("%1/%2").arg(MY_QML_DIR).arg("main.qml")));
    viewer.show();
    return app.exec();
}

/************************************OR*********************************/

//#include <QGuiApplication>
//#include <QQmlApplicationEngine>

//int main(int argc, char *argv[])
//{
//    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    engine.load(QUrl::fromLocalFile(QString("%1/%2").arg(MY_QML_DIR).arg("main-qt5.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;

//    return app.exec();
//}

#endif
