#ifndef SCYTALE_H
#define	SCYTALE_H

#include "BaseAlgo.h"
#include <QtGui>
#include <QDebug>

class Scytale : public BaseAlgo {
public:
    void cipher();
    void decipher();
    void setLetterOnDiameter(unsigned nb);
    void setCleanText(bool cleanText);
    
private:
    void clearText();
    unsigned letterOnDiameter;
    bool cleanText;
};

#endif	/* SCYTALE_H */

