#-------------------------------------------------
#
# Project created by QtCreator 2012-03-22T11:23:28
#
#-------------------------------------------------

QT       +=
CONFIG   += console

TARGET = OpenCVMovementTracking
TEMPLATE = app


SOURCES += main.cpp \
    pantalla1.cpp \
    pantalla2.cpp \
    pantalla3.cpp \
    pantalla4.cpp \
    pantalla0.cpp \
    globales.cpp \
    primerHilo.cpp \
    segundoHilo.cpp \
    rastreador.cpp \
    visor.cpp \
    capturador.cpp \
    pantalla5.cpp \
    tercerHilo.cpp

HEADERS  += \
    pantalla1.h \
    pantalla2.h \
    pantalla3.h \
    pantalla4.h \
    pantalla0.h \
    globales.h \
    primerHilo.h \
    segundoHilo.h \
    rastreador.h \
    visor.h \
    capturador.h \
    pantalla5.h \
    tercerHilo.h

QT += widgets


INCLUDEPATH += "C:/Program Files (x86)/Csound6/include/csound"

LIBS += -L "C:/Program Files (x86)/Csound6/bin"  # capital L for setting library path
LIBS += -lcsound64 # lowercase l for including the library
LIBS += -lcsnd6 # lowercase l for including the library


INCLUDEPATH += C:\opencv\opencv\release\install\include

CONFIG (debug, debug|release) {
    LIBS += -L"C:/opencv/opencv/release/bin"
LIBS += -llibopencv_core310 -llibopencv_objdetect310 -llibopencv_core310 -llibopencv_flann310 -llibopencv_ml310 -llibopencv_photo310 -llibopencv_shape310 -llibopencv_stitching310 -llibopencv_superres310 -llibopencv_highgui310 -llibopencv_imgproc310 -llibopencv_features2d310 -llibopencv_calib3d310 -llibopencv_imgcodecs310 -llibopencv_video310 -llibopencv_videoio310 -llibopencv_videostab310
}
CONFIG (release, debug|release) {
    LIBS += -L"C:/opencv/opencv/release/bin"
LIBS += -llibopencv_core310 -llibopencv_objdetect310 -llibopencv_core310 -llibopencv_flann310 -llibopencv_ml310 -llibopencv_photo310 -llibopencv_shape310 -llibopencv_stitching310 -llibopencv_superres310 -llibopencv_highgui310 -llibopencv_imgproc310 -llibopencv_features2d310 -llibopencv_calib3d310 -llibopencv_imgcodecs310 -llibopencv_video310 -llibopencv_videoio310 -llibopencv_videostab310
}

FORMS += \
    pantalla1.ui \
    pantalla2.ui \
    pantalla3.ui \
    pantalla4.ui \
    pantalla0.ui \
    pantalla5.ui

RESOURCES += \
    imagenes.qrc
