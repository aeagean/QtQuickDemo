#include <QApplication>

#define IS_QT_4 (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))

#if IS_QT_4 /* Qt4 */
    #include <QDeclarativeView>
#else /* Qt5 more */
    #include <QQuickView>
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

#if IS_QT_4
    QDeclarativeView viewer;
#else
    QQuickView viewer;
#endif
    viewer.setSource(QUrl::fromLocalFile(QString("%1/%2").arg(MY_QML_DIR).arg("main.qml")));
    viewer.show();
    return app.exec();
}
