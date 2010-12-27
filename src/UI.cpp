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
    setMinimumSize(600, 400);

    mainLayout = new QVBoxLayout;
    setLayout(mainLayout);

    textLabel = new QLabel(tr("Text to cipher/decipher:"));
    mainLayout->addWidget(textLabel);
    
    textField = new QTextEdit;
    textField->setMinimumHeight(250);
    mainLayout->addWidget(textField);

    algoTabs = new QTabWidget;
    mainLayout->addWidget(algoTabs);

    /*
     * Available algorithm tabs
     */

    vigenereTab = new VigenereUI(textField);
    algoTabs->addTab(vigenereTab, tr("Vigenere"));

    caesarTab = new CaesarUI(textField);
    algoTabs->addTab(caesarTab, tr("Caesar"));

    scytaleTab = new ScytaleUI(textField);
    algoTabs->addTab(scytaleTab, tr("Scytale"));
}

UI::~UI() { }
