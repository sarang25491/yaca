/* 
 * File:   Vigenere.h
 * Author: alex
 *
 * Created on December 21, 2010, 5:51 PM
 */

#ifndef VIGENERE_H
#define	VIGENERE_H

#include "BaseAlgo.h"
#include <QtGui>
#include <QDebug>

class Vigenere : public BaseAlgo {
public:
    Vigenere();
    virtual ~Vigenere();
    void setKey(QString key);
    QString getKey() const;
    void cipher();
    void decipher();
    void setCleanText(bool cleanText);

protected:
    QString key;

private:
    bool cleanText;
};

#endif	/* VIGENERE_H */

