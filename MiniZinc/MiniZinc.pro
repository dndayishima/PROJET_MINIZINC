#-------------------------------------------------
#
# Project created by QtCreator 2020-01-23T13:41:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MiniZinc
TEMPLATE = app


SOURCES += main.cpp\
        minizinc.cpp \
    jeux_des_seaux_deau.cpp \
    traversee_de_la_riviere.cpp \
    jeu_de_saute_moutons.cpp

HEADERS  += minizinc.h \
    jeux_des_seaux_deau.h \
    traversee_de_la_riviere.h \
    jeu_de_saute_moutons.h

FORMS    += minizinc.ui \
    jeux_des_seaux_deau.ui \
    traversee_de_la_riviere.ui \
    jeu_de_saute_moutons.ui

RESOURCES += \
    resource.qrc \
    mzn_dzn.qrc
