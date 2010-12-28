/* 
 * File:   Vigenere.cpp
 * Author: alex
 * 
 * Created on December 21, 2010, 5:51 PM
 */

#include "Vigenere.h"

Vigenere::Vigenere() {
    key = "";
}

Vigenere::~Vigenere() { }

void Vigenere::cipher() {
    if (key.isEmpty() || clearMsg.isEmpty()) return;

    cipherMsg.clear();
    
    int i,j;
    for (i=0, j=0; i < clearMsg.length(); i++, j++) {
        if (j >= key.length()) j = 0;

        if (clearMsg.at(i) < 'A' || clearMsg.at(i) > 'Z') {
            if (cleanText) {
                j--;
                continue;
            }
            cipherMsg += clearMsg.at(i);
        } else
            cipherMsg += ((((clearMsg.at(i).toAscii()-65)+(key.at(j).toAscii()-65))%26)+65);
    }
}

void Vigenere::decipher() {
    if (key.isEmpty() || cipherMsg.isEmpty()) return;

    clearMsg.clear();

    int i,j;
    for (i=0, j=0; i < cipherMsg.length(); i++, j++) {
        if (j >= key.length()) j = 0;

        if (cipherMsg.at(i) < 'A' || cipherMsg.at(i) > 'Z') {
            clearMsg += cipherMsg.at(i);
        } else if (key.at(j) > cipherMsg.at(i))
            clearMsg += ((91-key.at(j).toAscii())+cipherMsg.at(i).toAscii());
        else
            clearMsg += (cipherMsg.at(i).toAscii()-key.at(j).toAscii()+65);
    }
}

void Vigenere::setKey(QString key) {
    this->key = key;
}

QString Vigenere::getKey() const {
    return key;
}

void Vigenere::setCleanText(bool cleanText) {
    this->cleanText = cleanText;
}
