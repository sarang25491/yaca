#ifndef VIGENERE_H
#define	VIGENERE_H

#include "BaseAlgo.h"
#include <QtGui>
#include <QDebug>

class Vigenere : public BaseAlgo {
public:
    Vigenere();
    void setKey(QString key);
    QString getKey() const;
    void cipher();
    void decipher();
    void setCleanText(bool cleanText);
    void findOccurences();

protected:
    QString key;

private:
    bool cleanText;
};

#endif	/* VIGENERE_H */
