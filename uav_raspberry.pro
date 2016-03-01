TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    videoreader.cpp \
    imageprocessing.cpp \
    haarcascadeclasifier.cpp

HEADERS += \
    videoreader.hh \
    imageprocessing.hh \
    colors.hh \
    haarcascadeclasifier.hh \
    settings.hh

CONFIG += c++11

LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_videoio -lopencv_imgproc -lopencv_objdetect
