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
    setLayout(tabLayout);

    legend = new QLabel(tr("Key shift:"));
    tabLayout->addWidget(legend, 0, 0, Qt::AlignLeft);

    shiftBox = new QSpinBox;
    shiftBox->setMinimum(1);
    shiftBox->setMaximum(25);
    shiftBox->setValue(3);
    tabLayout->addWidget(shiftBox, 0, 1, 1, 3, Qt::AlignLeft);

    cleanTextOpt = new QCheckBox(tr("Remove special character on cipher"));
    tabLayout->addWidget(cleanTextOpt, 2, 0, 1, 3, Qt::AlignLeft);

    cipherButton = new QPushButton(tr("Cipher"));
    tabLayout->addWidget(cipherButton, 3, 0, Qt::AlignBottom);
    connect(cipherButton, SIGNAL(clicked()), this, SLOT(onCipherRequest()));

    decipherButton = new QPushButton(tr("Decipher"));
    tabLayout->addWidget(decipherButton, 3, 1, Qt::AlignBottom);
    connect(decipherButton, SIGNAL(clicked()), this, SLOT(onDecipherRequest()));

    crackButton = new QPushButton(tr("Crack"));
    tabLayout->addWidget(crackButton, 3, 2, Qt::AlignBottom);
    connect(crackButton, SIGNAL(clicked()), this, SLOT(onCrackRequest()));

    undoButton = new QPushButton(tr("Undo"));
    undoButton->setDisabled(true);
    tabLayout->addWidget(undoButton, 3, 3, Qt::AlignBottom);
    connect(undoButton, SIGNAL(clicked()), this, SLOT(onUndoAction()));
}

CaesarUI::~CaesarUI() { }

void CaesarUI::onCipherRequest() {
    if (!doAction()) return;

    algo.setClearMsg(text->toPlainText());
    algo.cipher();
    
    text->setText(algo.getCipherMsg());
}

void CaesarUI::onDecipherRequest() {
    if (!doAction()) return;

    algo.setCipherMsg(text->toPlainText());
    algo.decipher();

    text->setText(algo.getClearMsg());
}

void CaesarUI::onCrackRequest() {
    QMessageBox::warning(this, tr("Warning"), tr("Method not implemented yet."));
}

void CaesarUI::onUndoAction() {
    QString prev = backup;
    prepareUndo();
    text->setText(prev);
}

bool CaesarUI::doAction() {
    if (!checkFields()) return false;

    prepareUndo();
    algo.setKey(shiftBox->value());
    algo.setCleanText(cleanTextOpt->isChecked());

    return true;
}

bool CaesarUI::checkFields() {
    if (text->toPlainText().isEmpty()) {
        QMessageBox::critical(this, tr("Field error"), tr("The text field must be filled"));
        return false;
    }

    return true;
}

void CaesarUI::prepareUndo() {
    backup = text->toPlainText();
    undoButton->setEnabled(true);
}
