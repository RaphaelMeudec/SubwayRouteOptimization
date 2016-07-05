QT += \
    widgets \
    printsupport \

DISTFILES += \
    ligne_retard.data \
    lignes.data \
    lignes_mod.data \
    lignezhu.data \
    MetroTest.pro.user \
    stations.data \
    stations_mod.data \
    stations_retard.data \
    stationzhu.data

HEADERS += \
    arc.h \
    ligne.h \
    matrice.h \
    path.h \
    read_files.h \
    reseau.h \
    station.h \
    mainwindow.h \
    resultwindow.h \
    renderarea.h \
    errorwindow.h \
    Dijkstra.h \
    choicewindow.h

SOURCES += \
    arc.cpp \
    ligne.cpp \
    matrice.cpp \
    path.cpp \
    read_files.cpp \
    reseau.cpp \
    station.cpp \
    mainwindow.cpp \
    resultwindow.cpp \
    renderarea.cpp \
    main.cpp \
    initialize.cpp \
    errorwindow.cpp \
    Dijkstra.cpp \
    choicewindow.cpp
