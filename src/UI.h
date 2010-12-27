/* 
 * File:   UI.h
 * Author: alex
 *
 * Created on December 20, 2010, 2:36 PM
 */

#ifndef UI_H
#define	UI_H

// TODO: Import only needed headers
#include <QtGui>

#include "VigenereUI.h"
#include "CaesarUI.h"
#include "ScytaleUI.h"

class UI : public QWidget {
public:
    UI();
    virtual ~UI();
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

