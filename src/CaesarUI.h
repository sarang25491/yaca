/* 
 * File:   CaesarUI.h
 * Author: alex
 *
 * Created on December 20, 2010, 3:45 PM
 */

#ifndef CAESARUI_H
#define	CAESARUI_H

#include <QtGui>
#include <QDebug>

class CaesarUI : public QWidget {
    Q_OBJECT
    
public:
    CaesarUI(QTextEdit* field);
    virtual ~CaesarUI();

private slots:
    void onCypher();

private:
    QGridLayout* tabLayout;
    QLabel* legend;
    QTextEdit* text;
    QPushButton* cipherButton;
    QPushButton* decipherButton;
    QPushButton* crackButton;
    QSpinBox* shiftBox;
};

#endif	/* CAESARUI_H */

