#ifndef ENIGMAUI_H
#define	ENIGMAUI_H

#include <QtGui>
#include "algo/Enigma.h"

class EnigmaUI : public QWidget {
    Q_OBJECT

public:
    EnigmaUI(QTextEdit* field);

private slots:
    void onCipherRequest();
    void onDecipherRequest();
    void onUndoAction();

private:
    bool checkFields();
    void prepareUndo();
    bool doAction();
    QTextEdit* text;
    Enigma algo;
    QGridLayout* tabLayout;
    QFormLayout* rotorLayout;
    QSpinBox* rotor1Box;
    QSpinBox* rotor2Box;
    QSpinBox* rotor3Box;
    QSpinBox* reflectorBox;
    QPushButton* cipherButton;
    QPushButton* decipherButton;
    QPushButton* undoButton;
    QCheckBox* cleanTextOpt;
    QString backup;

};

#endif	/* ENIGMAUI_H */

