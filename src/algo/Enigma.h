#ifndef ENIGMA_H
#define	ENIGMA_H

#include "BaseAlgo.h"


class Enigma : public BaseAlgo {

public:
    Enigma();
    void enigma(bool cipher);
    void cipher();
    void decipher();
    void setCleanText(bool cleanText);
    void setReflectorPos(unsigned reflectorPos);
    unsigned getReflectorPos() const;
    void setRotor3Pos(unsigned rotor3Pos);
    unsigned getRotor3Pos() const;
    void setRotor2Pos(unsigned rotor2Pos);
    unsigned getRotor2Pos() const;
    void setRotor1Pos(unsigned rotor1Pos);
    unsigned getRotor1Pos() const;
    void setConnectionPos(unsigned connectionPos);
    unsigned getConnectionPos() const;

private:
    void clearText();
    void generateConnectionsTable();
    bool cleanText;
    unsigned connectionPos;
    unsigned rotor1Pos;
    unsigned rotor2Pos;
    unsigned rotor3Pos;
    unsigned reflectorPos;
    QList<QString> rotors;
    QString reflector;
    QMap<int, QList<int> > connectionTable;

};

#endif	/* ENIGMA_H */

