/* 
 * File:   UI.cpp
 * Author: alex
 * 
 * Created on December 20, 2010, 2:36 PM
 */

#include "UI.h"

UI::UI() {
    setWindowTitle("Yet Another Cryptography Application");
    setWindowFlags(Qt::Window);
    setMinimumSize(400, 500);

    mainLayout = new QVBoxLayout;
    
    textField = new QTextEdit;
    mainLayout->addWidget(textField);

    algoTabs = new QTabWidget;
    mainLayout->addWidget(algoTabs);

    vigenereTab = new VigenereUI(textField);
    algoTabs->addTab(vigenereTab, tr("Vigenere"));

    caesarTab = new CaesarUI(textField);
    algoTabs->addTab(caesarTab, tr("Caesar"));

    

    setLayout(mainLayout);
}

UI::~UI() {
}

