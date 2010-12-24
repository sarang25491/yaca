/* 
 * File:   CaesarUI.cpp
 * Author: alex
 * 
 * Created on December 20, 2010, 3:45 PM
 */

#include "CaesarUI.h"

CaesarUI::CaesarUI(QTextEdit* field) {
    text = field;

    tabLayout = new QGridLayout;
    legend = new QLabel(tr("Key shift:"));
    tabLayout->addWidget(legend);

    shiftBox = new QSpinBox;
    tabLayout->addWidget(shiftBox);

    cipherButton = new QPushButton(tr("Cipher"));
    tabLayout->addWidget(cipherButton);
    connect(cipherButton, SIGNAL(clicked()), this, SLOT(onCypher()));

    decipherButton = new QPushButton(tr("Decipher"));
    tabLayout->addWidget(decipherButton);

    crackButton = new QPushButton(tr("Crack"));
    tabLayout->addWidget(crackButton);

    setLayout(tabLayout);
}

CaesarUI::~CaesarUI() {
}

void CaesarUI::onCypher() {
    qDebug() << "Caesar: " << text->toPlainText();
}
