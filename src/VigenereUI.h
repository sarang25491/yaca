/* 
 * File:   VigenereUI.h
 * Author: alex
 *
 * Created on December 20, 2010, 3:44 PM
 */

#ifndef VIGENEREUI_H
#define	VIGENEREUI_H

#include <QtGui>

#include "Vigenere.h"

class VigenereUI : public QWidget {
    Q_OBJECT
    
public:
    VigenereUI(QTextEdit* field);
    virtual ~VigenereUI();
    
private slots:
    void onCipherRequest();
    void onDecipherRequest();
    void onCrackRequest();
    void onUndoAction();

private:
    void clearKey();
    bool checkFields();
    void prepareUndo();
    bool doAction();
    QTextEdit* text;
    Vigenere algo;
    QGridLayout* tabLayout;
    QLabel* legend;
    QTextEdit* keyBox;
    QPushButton* cipherButton;
    QPushButton* decipherButton;
    QPushButton* crackButton;
    QPushButton* undoButton;
    QCheckBox* cleanTextOpt;
    QString backup;
};

#endif	/* VIGENEREUI_H */

