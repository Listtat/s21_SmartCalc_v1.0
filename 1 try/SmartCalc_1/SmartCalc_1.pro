QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../s21_smart_calc_1.0.c \
    credit.cpp \
    credit_result.cpp \
    deposit.cpp \
    graphics.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    ../s21_credit_calc.c

HEADERS += \
    credit.h \
    credit_result.h \
    deposit.h \
    graphics.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    credit.ui \
    credit_result.ui \
    deposit.ui \
    graphics.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
