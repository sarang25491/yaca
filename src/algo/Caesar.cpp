#include "Caesar.h"

void Caesar::setKey(unsigned shift) {
    QString buildKey = (QChar)('A' + shift);
    key = buildKey;
}
