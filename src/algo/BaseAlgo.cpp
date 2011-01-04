#include "BaseAlgo.h"

BaseAlgo::BaseAlgo() {
    clearMsg = "";
    cipherMsg = "";
}

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
