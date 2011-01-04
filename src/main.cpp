#include <QtGui/QApplication>
#include "ui/UI.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    UI win;
    win.show();
    
    return app.exec();
}
