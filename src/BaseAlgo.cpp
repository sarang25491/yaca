/* 
 * File:   BaseAlgo.cpp
 * Author: alex
 * 
 * Created on December 22, 2010, 4:59 PM
 */

#include "BaseAlgo.h"

BaseAlgo::BaseAlgo() {
    clearMsg = "";
    cipherMsg = "";
}

BaseAlgo::~BaseAlgo() { }

void BaseAlgo::cipher() { }
void BaseAlgo::decipher() { }

void BaseAlgo::setClearMsg(QString clearMsg) {
    this->clearMsg = clearMsg.toUpper();
}

QString BaseAlgo::getClearMsg() const {
    return clearMsg;
}

void BaseAlgo::setCipherMsg(QString cipherMsg) {
    this->cipherMsg = cipherMsg.toUpper();
}

QString BaseAlgo::getCipherMsg() const {
    return cipherMsg;
}
