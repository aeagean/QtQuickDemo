QT += core

equals (QT_MAJOR_VERSION, 5) {
    QT += qml quick
}
else {
    QT += declarative
}


SOURCES += main.cpp

