    QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calcview.cc \
    ../calc_model/calc_model.cc \
    ../calc_model/parser.cc \
    ../calc_model/converter.cc \
    ../calc_model/calculator.cc \
    ../calc_controller/calc_controller.cc \
    main.cc \
    qcustomplot.cc

HEADERS += \
    calcview.h \
    ../calc_model/calc_model.h \
    ../calc_model/parser.h \
    ../calc_model/converter.h \
    ../calc_model/calculator.h \
    ../calc_model/data.h \
    ../calc_controller/calc_controller.h \
    qcustomplot.h

FORMS += \
    calcview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
