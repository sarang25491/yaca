/* 
 * File:   Scytale.h
 * Author: alex
 *
 * Created on December 27, 2010, 7:07 PM
 */

#ifndef SCYTALE_H
#define	SCYTALE_H

#include "BaseAlgo.h"
#include <QtGui>
#include <QDebug>

class Scytale : public BaseAlgo {
public:
    Scytale();
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

