#include "Scytale.h"

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

unsigned Scytale::crack() {
    QMap<QString, float> bigramFR;
    QList<float> bigramStat;

    bigramFR.insert("ES", 3.15);
    bigramFR.insert("LE", 2.46);
    bigramFR.insert("EN", 2.42);
    bigramFR.insert("DE", 2.15);
    bigramFR.insert("RE", 2.09);
    bigramFR.insert("NT", 1.97);
    bigramFR.insert("ON", 1.64);
    bigramFR.insert("TE", 1.63);
    bigramFR.insert("ER", 1.63);
    bigramFR.insert("SE", 1.55);

    for (int curKey=2; curKey < cipherMsg.length()/2; curKey++) {
        QMap<QString, int> curStat;
        unsigned bigramNb = 0;
        for (int curChar=curKey; curChar < cipherMsg.length(); curChar+=curKey) {
            QString curBigram = QString("%1%2").arg(cipherMsg.at(curChar-curKey)).arg(cipherMsg.at(curChar));
            if (bigramFR.contains(curBigram)) {
                qDebug() << "got" << curBigram << "with key" << curKey;
                bigramNb++;
                curStat[curBigram] = curStat.value(curBigram, 0)+1;
            }
        }

        float total = 0;
        foreach(QString bigram, bigramFR.keys()) {
            if (!bigramNb) break;
            float diff = (float)(bigramFR.value(bigram) - (curStat.value(bigram)/bigramNb)*100);
            if (diff < 0) diff = -diff;
            total += (float)((100 - bigramFR.value(bigram)) * diff);
        }

        bigramStat.append((!total) ? INFINITY : total);
    }

    qDebug() << bigramStat;

    int key = 2;
    float min = INFINITY;
    for (int i = 0; i < bigramStat.length(); i++) {
        if (bigramStat.at(i) < min) {
            key = i+2;
            min = bigramStat.at(i);
        }
    }

    qDebug() << key;

    return key;
}
