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
