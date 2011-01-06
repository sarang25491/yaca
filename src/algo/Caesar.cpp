#include "Caesar.h"

void Caesar::setKey(unsigned shift) {
    QString buildKey = (QChar)('A' + shift);
    key = buildKey;
}

int Caesar::crack (){
    QList<float> frequenciesStat;
    QList<float> frequencies;
    QList<float> keyScores;

    // French letter frequency
    frequencies << 9.42 << 1.02 << 2.64 << 3.39 << 15.87 << 0.95 << 1.04 << 0.77;
    frequencies << 8.41 << 0.89 << 0.001 << 5.34 << 3.24 << 7.15 << 5.14 << 2.86;
    frequencies << 1.06 << 6.46 << 7.90 << 7.26 << 6.24 << 2.15 << 0.01 << 0.30;
    frequencies << 0.24 << 0.32;

    // Cipher text stats
    for (int i = 0; i < 25; i++)
        frequenciesStat.append((float) ((float) cipherMsg.count((QChar) ('A' + i)) / cipherMsg.length())*100);

    // Get stat for each get
    for (int key = 0; key < 25; key++) {
        float total = 0.0;
        for (int letter = 0; letter < 25; letter++) {
            float diff = (float)(frequenciesStat.at((letter + key)%25) - frequencies.at(letter));
            if (diff < 0) diff = -diff;
            total += (float)((100 - frequencies.at(letter)) * diff);
        }

        keyScores.append(total);
    }


    int key = 0;
    float min = INFINITY;
    for (int i = 0; i < 25; i++) {
        if (keyScores.at(i) < min) {
            min = keyScores.at(i);
            key = i;
        }
    }

    return key;
}
