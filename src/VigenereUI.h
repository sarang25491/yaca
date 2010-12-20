/* 
 * File:   VigenereUI.h
 * Author: alex
 *
 * Created on December 20, 2010, 3:44 PM
 */

#ifndef VIGENEREUI_H
#define	VIGENEREUI_H

#include <QtGui>

class VigenereUI : public QWidget {
public:
    VigenereUI(QTextEdit* field);
    virtual ~VigenereUI();
private:
    QTextEdit* text;
};

#endif	/* VIGENEREUI_H */

