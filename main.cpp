#include <QApplication>
#include "station.h"
#include "choicewindow.h"



int main (int argc, char * argv[]) {
    QApplication app(argc, argv);
    choicewindow window;
    window.show();
    return app.exec();
}



