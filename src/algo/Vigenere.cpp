#include "Vigenere.h"

Vigenere::Vigenere() {
    key = "";
}

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

void Vigenere::findOccurences() {
    int curLetterPos, curLength, minLength=4;
    QList<int> index;
    QMap<QString, QList<int> > list;

    qDebug() << "Occurences";

    for (curLetterPos=0; curLetterPos < cipherMsg.length(); curLetterPos++) {
        curLength = minLength;
        index.clear();
        qDebug() << "pos" << curLetterPos << ":" << cipherMsg.mid(curLetterPos, curLength);
        qDebug() << cipherMsg.count(cipherMsg.mid(curLetterPos, curLength));
        while (cipherMsg.indexOf(cipherMsg.mid(curLetterPos, curLength), curLetterPos+curLength) != -1) {
            qDebug() << ">>at" << cipherMsg.indexOf(cipherMsg.mid(curLetterPos, curLength), curLetterPos+curLength);
            curLength++;
        }
        curLength--;
        index.append(cipherMsg.indexOf(cipherMsg.mid(curLetterPos, curLength)));
        index.append(cipherMsg.indexOf(cipherMsg.mid(curLetterPos, curLength), curLetterPos+curLength));
        while (cipherMsg.indexOf(cipherMsg.mid(curLetterPos, curLength), index.last()+1) != -1) {
            index.append(cipherMsg.indexOf(cipherMsg.mid(curLetterPos, curLength), index.last()+1));
        }
        if (curLength >= minLength && !list.contains(cipherMsg.mid(curLetterPos, curLength))) {
            qDebug() << "found:" << cipherMsg.mid(curLetterPos, curLength) << "at" << index;
            list[cipherMsg.mid(curLetterPos, curLength)] = index;
            curLetterPos+=curLength;
        }
    }
    
    qDebug() << "At the end:" << list;

    qDebug() << "Finding divisor:";

    QList<QList<int> > allDivisor;
    foreach (QList<int> item, list) {
        int i;
        QList<int> divisor;
        for (i = 2; i < cipherMsg.length(); i++) {
            int totalSpace = 0, e;
            for (e=1; e < item.length(); e++)
                totalSpace += (item.at(e) - item.at(e-1));
            totalSpace /= item.length();

            if ((totalSpace%i) == 0)
                divisor.append(i);
        }
        allDivisor.append(divisor);
    }

    qDebug() << "Found divisor:" << allDivisor;


    qDebug() << "Finding common divisor";

    QMap<int, int> common;
    foreach (QList<int> cur, allDivisor) {
        foreach (int it, cur) {
            common[it] = common.value(it, 0)+1;
        }
    }

    qDebug() << "Common:" << common;

    QList<int> possible = common.keys(list.count());
    qDebug() << "Possible:" << possible;

    int winner = -1;
    foreach (int elem, possible) {
        if (elem > winner)
            winner = elem;
    }
    
    qDebug() << "And the winner is:" << winner;
    
}
