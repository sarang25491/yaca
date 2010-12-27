/* 
 * File:   Caesar.cpp
 * Author: alex
 * 
 * Created on December 24, 2010, 1:28 PM
 */

#include "Caesar.h"

Caesar::Caesar() { }

Caesar::~Caesar() { }

void Caesar::setKey(unsigned shift) {
    QString buildKey = (QChar)('A' + shift);
    key = buildKey;
}
