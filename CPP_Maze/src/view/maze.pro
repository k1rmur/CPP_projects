QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cc \
    ../model/model.cc \
    ../model/file_writer.cc \
    ../model/file_reader.cc \
    ../model/maze_solver.cc \
    ../model/maze_generator.cc \
    ../controller/controller.cc \
    ../modules/matrix.cc \
    maze_view.cc \
    renderer.cc

HEADERS += \
    ../model/model.h \
    ../model/maze_data.h \
    ../model/exceptions.h \
    ../model/file_writer.h \
    ../model/file_reader.h \
    ../model/maze_solver.h \
    ../model/maze_generator.h \
    ../controller/controller.h \
    ../modules/matrix.h \
    maze_view.h \
    renderer.h

FORMS += \
    ../ui/maze_view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
