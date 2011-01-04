#ifndef CAESARUI_H
#define	CAESARUI_H

#include <QtGui>
#include "algo/Caesar.h"

class CaesarUI : public QWidget {
    Q_OBJECT
    
public:
    CaesarUI(QTextEdit* field);

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
    Caesar algo;
    QGridLayout* tabLayout;
    QLabel* legend;
    QSpinBox* shiftBox;
    QPushButton* cipherButton;
    QPushButton* decipherButton;
    QPushButton* crackButton;
    QPushButton* undoButton;
    QCheckBox* cleanTextOpt;
    QString backup;
};

#endif	/* CAESARUI_H */
