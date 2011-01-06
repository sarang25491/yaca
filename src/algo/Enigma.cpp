/* 
 * File:   Enigma.cpp
 * Author: alex
 * 
 * Created on January 5, 2011, 9:27 PM
 */

#include "Enigma.h"

Enigma::Enigma() {
    rotors.append("DMTWSILRUYQNKFEJCAZBPGXOHV");
    rotors.append("HQZGPJTMOBLNCIFDYAWVEUSRKX");
    rotors.append("UQNTLSZFMREHDPXKIBVYGJCWOA");
    reflector = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
}

void Enigma::enigma(bool cipher) {
    QString msg, out = "";
    msg = (cipher) ? clearMsg : cipherMsg;
    
    int posR1, posR2, curChar, forward, backward;
    
    for (curChar=0, posR1=0, posR2=0; curChar < msg.length(); curChar++) {
        if ((curChar %26) == 0) {
            if ((posR1 %26) == 0)
                posR2 = (posR2+1) %26;
            
            posR1 = (posR1+1) %26;
        }

        forward = reflector.at(
                    (reflectorPos+rotors.at(2).at(
                        (rotor3Pos+posR2+rotors.at(1).at(
                            (rotor2Pos+posR1+rotors.at(0).at(
                                (msg.at(curChar).toAscii()-'A'+curChar+rotor1Pos) %26
                                                            ).toAscii()) %26
                                                        ).toAscii()) %26
                                                  ).toAscii()) %26
                               ).toAscii()-'A';
        backward = rotors.at(0).at(
                        (rotor1Pos+(curChar % 26)+rotors.at(1).at(
                            (rotor2Pos+posR1+rotors.at(2).at(
                                (forward+posR2+rotor3Pos) %26
                                                            ).toAscii()) %26
                                                       ).toAscii()) %26
                                   ).toAscii()-'A';

        out += (QChar)('A'+backward);
    }

    if (cipher)
        cipherMsg = out;
    else
        clearMsg = out;
}

void Enigma::cipher() {
    enigma(true);
}

void Enigma::decipher() {
    enigma(false);
}

void Enigma::setReflectorPos(unsigned reflectorPos) {
    this->reflectorPos = reflectorPos;
}

unsigned Enigma::getReflectorPos() const {
    return reflectorPos;
}

void Enigma::setRotor3Pos(unsigned rotor3Pos) {
    this->rotor3Pos = rotor3Pos;
}

unsigned Enigma::getRotor3Pos() const {
    return rotor3Pos;
}

void Enigma::setRotor2Pos(unsigned rotor2Pos) {
    this->rotor2Pos = rotor2Pos;
}

unsigned Enigma::getRotor2Pos() const {
    return rotor2Pos;
}

void Enigma::setRotor1Pos(unsigned rotor1Pos) {
    this->rotor1Pos = rotor1Pos;
}

unsigned Enigma::getRotor1Pos() const {
    return rotor1Pos;
}

void Enigma::setConnectionPos(unsigned connectionPos) {
    this->connectionPos = connectionPos;
}

unsigned Enigma::getConnectionPos() const {
    return connectionPos;
}

void Enigma::setCleanText(bool cleanText) {
    this->cleanText = cleanText;
}

void Enigma::clearText() {
    clearMsg.remove(QRegExp("[^A-Z]"));
}

void Enigma::generateConnectionsTable() {

}
