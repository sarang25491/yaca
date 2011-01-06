/* 
 * File:   EnigmaUI.cpp
 * Author: alex
 * 
 * Created on January 6, 2011, 12:28 AM
 */

#include "EnigmaUI.h"

EnigmaUI::EnigmaUI(QTextEdit* field) {
    text = field;

    tabLayout = new QGridLayout;
    setLayout(tabLayout);

    rotorLayout = new QFormLayout;
    tabLayout->addLayout(rotorLayout, 0, 0, Qt::AlignLeft);

    rotor1Box = new QSpinBox;
    rotor1Box->setMaximum(25);
    rotor1Box->setMinimum(1);
    rotor1Box->setValue(4);
    rotorLayout->addRow(tr("Rotor 1:"), rotor1Box);

    rotor2Box = new QSpinBox;
    rotor2Box->setMaximum(25);
    rotor2Box->setMinimum(1);
    rotor2Box->setValue(3);
    rotorLayout->addRow(tr("Rotor 2:"), rotor2Box);

    rotor3Box = new QSpinBox;
    rotor3Box->setMaximum(25);
    rotor3Box->setMinimum(1);
    rotor3Box->setValue(1);
    rotorLayout->addRow(tr("Rotor 3:"), rotor3Box);

    reflectorBox = new QSpinBox;
    reflectorBox->setMaximum(25);
    reflectorBox->setMinimum(1);
    reflectorBox->setValue(9);
    rotorLayout->addRow(tr("Reflector:"), reflectorBox);

    cleanTextOpt = new QCheckBox(tr("Remove special character on cipher"));
    tabLayout->addWidget(cleanTextOpt, 1, 0, 1, 3, Qt::AlignLeft);

    cipherButton = new QPushButton(tr("Cipher"));
    tabLayout->addWidget(cipherButton, 2, 0, Qt::AlignBottom);
    connect(cipherButton, SIGNAL(clicked()), this, SLOT(onCipherRequest()));

    decipherButton = new QPushButton(tr("Decipher"));
    tabLayout->addWidget(decipherButton, 2, 1, Qt::AlignBottom);
    connect(decipherButton, SIGNAL(clicked()), this, SLOT(onDecipherRequest()));

    undoButton = new QPushButton(tr("Undo"));
    undoButton->setDisabled(true);
    tabLayout->addWidget(undoButton, 2, 2, Qt::AlignBottom);
    connect(undoButton, SIGNAL(clicked()), this, SLOT(onUndoAction()));
}

void EnigmaUI::onCipherRequest() {
    if (!doAction()) return;

    algo.setClearMsg(text->toPlainText());
    algo.cipher();

    text->setText(algo.getCipherMsg());
}

void EnigmaUI::onDecipherRequest() {
    if (!doAction()) return;

    algo.setCipherMsg(text->toPlainText());
    algo.decipher();

    text->setText(algo.getClearMsg());
}

void EnigmaUI::onUndoAction() {
    QString prev = backup;
    prepareUndo();
    text->setText(prev);
}

bool EnigmaUI::doAction() {
    if (!checkFields()) return false;

    prepareUndo();
    algo.setRotor1Pos(rotor1Box->value());
    algo.setRotor2Pos(rotor2Box->value());
    algo.setRotor3Pos(rotor3Box->value());
    algo.setReflectorPos(reflectorBox->value());
    algo.setCleanText(cleanTextOpt->isChecked());


    return true;
}

bool EnigmaUI::checkFields() {
    if (text->toPlainText().isEmpty()) {
        QMessageBox::critical(this, tr("Field error"), tr("The text field must be filled"));
        return false;
    }

    return true;
}

void EnigmaUI::prepareUndo() {
    backup = text->toPlainText();
    undoButton->setEnabled(true);
}

