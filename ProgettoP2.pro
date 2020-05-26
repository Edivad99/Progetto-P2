QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MainWindow.cpp \
    main.cpp \
    model/impiegato.cpp \
    model/lavoratore.cpp \
    model/operaio.cpp \
    model/persona.cpp \
    model/rappresentante.cpp \
    model/studente.cpp \
    model/studente_lavoratore.cpp \
    util/orelavorative.cpp \
    util/telefono.cpp \
    util/lista.cpp \
    view/hometab.cpp \
    view/tabellatab.cpp

HEADERS += \
    MainWindow.h \
    model/impiegato.h \
    model/lavoratore.h \
    model/operaio.h \
    model/persona.h \
    model/rappresentante.h \
    model/studente.h \
    model/studente_lavoratore.h \
    util/orelavorative.h \
    util/telefono.h \
    util/lista.h \
    view/hometab.h \
    view/tabellatab.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
