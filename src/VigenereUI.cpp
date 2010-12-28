/* 
 * File:   VigenereUI.cpp
 * Author: alex
 * 
 * Created on December 20, 2010, 3:44 PM
 */

#include "VigenereUI.h"

VigenereUI::VigenereUI(QTextEdit* field) {
    text = field;

    tabLayout = new QGridLayout;
    setLayout(tabLayout);

    legend = new QLabel(tr("Key:"));
    tabLayout->addWidget(legend);

    keyBox = new QTextEdit;
    tabLayout->addWidget(keyBox, 1, 0, 1, 4);

    cleanTextOpt = new QCheckBox(tr("Remove special character"));
    tabLayout->addWidget(cleanTextOpt, 2, 0, 1, 4, Qt::AlignLeft);

    cipherButton = new QPushButton(tr("Cipher"));
    tabLayout->addWidget(cipherButton, 3, 0);
    connect(cipherButton, SIGNAL(clicked()), this, SLOT(onCipherRequest()));

    decipherButton = new QPushButton(tr("Decipher"));
    tabLayout->addWidget(decipherButton, 3, 1);
    connect(decipherButton, SIGNAL(clicked()), this, SLOT(onDecipherRequest()));

    crackButton = new QPushButton(tr("Crack"));
    tabLayout->addWidget(crackButton, 3, 2);
    connect(crackButton, SIGNAL(clicked()), this, SLOT(onCrackRequest()));

    undoButton = new QPushButton(tr("Undo"));
    undoButton->setDisabled(true);
    tabLayout->addWidget(undoButton, 3, 3);
    connect(undoButton, SIGNAL(clicked()), this, SLOT(onUndoAction()));
}

VigenereUI::~VigenereUI() { }

void VigenereUI::onCipherRequest() {
    if (!doAction()) return;

    algo.setClearMsg(text->toPlainText());
    algo.cipher();
    
    text->setText(algo.getCipherMsg());
}

void VigenereUI::onDecipherRequest() {
    if (!doAction()) return;

    algo.setCipherMsg(text->toPlainText());
    algo.decipher();

    text->setText(algo.getClearMsg());
}

void VigenereUI::onCrackRequest() {
    QMessageBox::warning(this, tr("Warning"), tr("Function not implemented yet."));
}

void VigenereUI::onUndoAction() {
    QString prev = backup;
    prepareUndo();
    text->setText(prev);
}

bool VigenereUI::doAction() {
    if (!checkFields()) return false;

    prepareUndo();
    algo.setKey(keyBox->toPlainText());
    algo.setCleanText(cleanTextOpt->isChecked());

    return true;
}

bool VigenereUI::checkFields() {
    clearKey();

    if (text->toPlainText().isEmpty() || keyBox->toPlainText().isEmpty()) {
        QMessageBox::critical(this, tr("Field error"), tr("The key and the text field must be filled"));
        return false;
    }

    return true;
}

void VigenereUI::clearKey() {
    keyBox->setText(keyBox->toPlainText().toUpper().remove(QRegExp("[^A-Z]")));
}

void VigenereUI::prepareUndo() {
    backup = text->toPlainText();
    undoButton->setEnabled(true);
}
