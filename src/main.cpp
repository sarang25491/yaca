/*
 * File:   main.cpp
 * Author: alex
 *
 * Created on December 20, 2010, 2:22 PM
 */

#include <QtGui/QApplication>

#include "UI.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    UI win;
    win.show();
    
    return app.exec();
}
