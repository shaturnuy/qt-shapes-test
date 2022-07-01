QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

INCLUDEPATH += include \
               src

SOURCES += \
    src/controlmenu.cpp \
    src/displayarea.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/shape.cpp \
    src/shapecounterwidget.cpp \
    src/shapepushbutton.cpp \
    src/shapesmenu.cpp

HEADERS += \
    include/controlmenu.h \
    include/displayarea.h \
    include/mainwindow.h \
    include/shape.h \
    include/shapecounterwidget.h \
    include/shapepushbutton.h \
    include/shapesmenu.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
