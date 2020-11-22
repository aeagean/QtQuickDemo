QT += core

equals (QT_MAJOR_VERSION, 4): QT += declarative

equals (QT_MAJOR_VERSION, 5): QT += qml quick quickwidgets

SOURCES += main.cpp
RC_ICONS = app.ico

equals(QT_MAJOR_VERSION, 4) {
    QT_QUICK_VERSION = 1.0
#    equals(QT_MINOR_VERSION, 7): QT_QUICK_VERSION = 1.0
#    equals(QT_MINOR_VERSION, 8): QT_QUICK_VERSION = 1.1
}

equals(QT_MAJOR_VERSION, 5): QT_QUICK_VERSION = 2.0#QT_QUICK_VERSION = 2.$${QT_MINOR_VERSION}

macx {
    !isEmpty(QT_QUICK_VERSION): QtQuickVersion.commands += "grep -rl 'QtQuick [0-9]\\.[0-9]' $$PWD/ | xargs sed -i '' 's/QtQuick [0-9]\\.[0-9]/QtQuick $${QT_QUICK_VERSION}/g';"
}

unix:!macx {
    !isEmpty(QT_QUICK_VERSION): QtQuickVersion.commands += "grep -rl 'QtQuick [0-9]\\.[0-9]' $$PWD/ | xargs sed -i 's/QtQuick [0-9]\\.[0-9]/QtQuick $${QT_QUICK_VERSION}/g';"
}

QtQuickVersion.target = FORCE

PRE_TARGETDEPS += FORCE
QMAKE_EXTRA_TARGETS += QtQuickVersion

DEFINES += MY_QML_DIR=\\\"'$$PWD'\\\"

OTHER_FILES += main.qml
