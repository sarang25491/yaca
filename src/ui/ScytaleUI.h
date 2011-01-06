#ifndef SCYTALEUI_H
#define	SCYTALEUI_H

#include <QtGui>
#include "algo/Scytale.h"

class ScytaleUI : public QWidget {
    Q_OBJECT
    
public:
    ScytaleUI(QTextEdit* field);

private slots:
    void onCipherRequest();
    void onDecipherRequest();
    void onCrackRequest();
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
    QPushButton* crackButton;
    QPushButton* undoButton;
    QCheckBox* cleanTextOpt;
    QString backup;
};

#endif	/* SCYTALEUI_H */
