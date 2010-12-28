/* 
 * File:   Scytale.cpp
 * Author: alex
 * 
 * Created on December 27, 2010, 7:07 PM
 */

#include "Scytale.h"

Scytale::Scytale() { }

void Scytale::cipher() {
    if (cleanText) clearText();

    int colNb = ceil((double)clearMsg.length()/letterOnDiameter);
    int curChar, curLine, curCol;

    cipherMsg.clear();
    cipherMsg.fill(' ', letterOnDiameter*colNb);

    for (curChar=0, curLine=0, curCol=0; curChar < clearMsg.length(); curChar++, curCol++) {
        if (curCol == colNb) {
            curCol = 0;
            curLine++;
        }
        cipherMsg.replace(curCol*letterOnDiameter+curLine, 1, clearMsg.at(curChar));
    }
}

void Scytale::decipher() {
    int colNb = ceil(cipherMsg.length()/letterOnDiameter);
    int curChar, curLine, curCol;

    clearMsg.clear();

    for (curChar=0, curLine=0, curCol=0; curChar < cipherMsg.length(); curChar++, curCol++) {
        if (curCol == colNb) {
            curCol = 0;
            curLine++;
        }

        clearMsg += cipherMsg.at(curCol*letterOnDiameter+curLine);
    }
}

void Scytale::setLetterOnDiameter(unsigned nb) {
    letterOnDiameter = nb;
}

void Scytale::setCleanText(bool cleanText) {
    this->cleanText = cleanText;
}

void Scytale::clearText() {
    clearMsg.remove(QRegExp("[^A-Z]"));
}
