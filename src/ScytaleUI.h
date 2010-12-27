/* 
 * File:   ScytaleUI.h
 * Author: alex
 *
 * Created on December 27, 2010, 6:43 PM
 */

#ifndef SCYTALEUI_H
#define	SCYTALEUI_H

#include <QtGui>

#include "Scytale.h"

class ScytaleUI : public QWidget {
    Q_OBJECT
    
public:
    ScytaleUI(QTextEdit* field);
    virtual ~ScytaleUI();

private slots:
    void onCipherRequest();
    void onDecipherRequest();
    void onUndoAction();

private:
    bool checkFields();
    void prepareUndo();
    bool doAction();
    
    QTextEdit* text;
    Scytale algo;
    QGridLayout* tabLayout;
    QLabel* legend;
    QSpinBox* letterNbBox;
    QPushButton* cipherButton;
    QPushButton* decipherButton;
    QPushButton* undoButton;
    QCheckBox* cleanTextOpt;
    QString backup;
};

#endif	/* SCYTALEUI_H */

