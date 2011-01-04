#include "ScytaleUI.h"

ScytaleUI::ScytaleUI(QTextEdit* field) {
    text = field;

    tabLayout = new QGridLayout;
    setLayout(tabLayout);

    legend = new QLabel(tr("Number of letter arround the diameter:"));
    tabLayout->addWidget(legend, 0, 0, 1, 2, Qt::AlignLeft);

    letterNbBox = new QSpinBox;
    letterNbBox->setMinimum(3);
    letterNbBox->setMaximum(42);
    tabLayout->addWidget(letterNbBox, 0, 2, Qt::AlignLeft);

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

void ScytaleUI::onCipherRequest() {
    if (!doAction()) return;

    algo.setClearMsg(text->toPlainText());
    algo.cipher();
    
    text->setText(algo.getCipherMsg());
}

void ScytaleUI::onDecipherRequest() {
    if (!doAction()) return;

    algo.setCipherMsg(text->toPlainText());
    algo.decipher();

    text->setText(algo.getClearMsg());
}

void ScytaleUI::onUndoAction() {
    QString prev = backup;
    prepareUndo();
    text->setText(prev);
}

bool ScytaleUI::doAction() {
    if (!checkFields()) return false;

    prepareUndo();
    algo.setLetterOnDiameter(letterNbBox->value());
    algo.setCleanText(cleanTextOpt->isChecked());


    return true;
}

bool ScytaleUI::checkFields() {
    if (text->toPlainText().isEmpty()) {
        QMessageBox::critical(this, tr("Field error"), tr("The text field must be filled"));
        return false;
    }

    if (letterNbBox->value() >= text->toPlainText().length()) {
        QMessageBox::critical(this, tr("key error"), tr("The number of letter around the cylinder \
be lesser than message lenth otherwise the message will remain uncrypted."));
        return false;
    }

    return true;
}

void ScytaleUI::prepareUndo() {
    backup = text->toPlainText();
    undoButton->setEnabled(true);
}
