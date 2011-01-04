#ifndef UI_H
#define	UI_H

#include <QtGui>

#include "VigenereUI.h"
#include "CaesarUI.h"
#include "ScytaleUI.h"

class UI : public QWidget {
public:
    UI();
    QTextEdit* textField;

private:
    QVBoxLayout* mainLayout;
    QTabWidget* algoTabs;
    QLabel* textLabel;
    VigenereUI* vigenereTab;
    CaesarUI* caesarTab;
    ScytaleUI* scytaleTab;
};

#endif	/* UI_H */

