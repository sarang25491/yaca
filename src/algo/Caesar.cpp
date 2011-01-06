#include "Caesar.h"

void Caesar::setKey(unsigned shift) {
    QString buildKey = (QChar)('A' + shift);
    key = buildKey;
}
int Caesar::frequentialAnalyse (){
    QMap<QChar,float> pourcent;
    QMap<QChar,float> pourcentFR;
    QList<float> res;
    float val;

    pourcentFR['A'] = 9.42;
    pourcentFR['B'] = 1.02;
    pourcentFR['C'] = 2.64;
    pourcentFR['D'] = 3.39;
    pourcentFR['E'] = 15.87;
    pourcentFR['F'] = 0.95;
    pourcentFR['G'] = 1.04;
    pourcentFR['H'] = 0.77;
    pourcentFR['I'] = 8.41;
    pourcentFR['J'] = 0.89;
    pourcentFR['K'] = 0.001;
    pourcentFR['L'] = 5.34;
    pourcentFR['M'] = 3.24;
    pourcentFR['N'] = 7.15;
    pourcentFR['O'] = 5.14;
    pourcentFR['P'] = 2.86;
    pourcentFR['Q'] = 1.06;
    pourcentFR['R'] = 6.46;
    pourcentFR['S'] = 7.90;
    pourcentFR['T'] = 7.26;
    pourcentFR['U'] = 6.24;
    pourcentFR['V'] = 2.15;
    pourcentFR['W'] = 0.01;
    pourcentFR['X'] = 0.30;
    pourcentFR['Y'] = 0.24;
    pourcentFR['Z'] = 0.32;

    for ( int i = 0 ; i < 25; i++ )
    {
        pourcent[(QChar)('A'+i)] = (cipherMsg.count((QChar)('A'+i))/cipherMsg.length())*100;

    }

    for ( int i = 0 ; i < 25; i++ )
    {
        res.insert(i, 0);
        for ( int j = 0 ; j < 25; j++ )
        {
            val = abs(pourcent[(QChar)('A'+j)]-pourcentFR[(QChar)('A'+j)]);
            res.replace(i, res.at(i) + (100 - pourcentFR[(QChar)('A'+j)]) * val);
        }
    }

    float min = INFINITY;
    int decalage = 541;
    for ( int i = 0 ; i < 25; i++ )
    {
        if(res.at(i)<min){
            min = res.at( i );
            decalage = i;
        }

    }
    

    return decalage;
}
