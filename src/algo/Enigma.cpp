/* 
 * File:   Enigma.cpp
 * Author: alex
 * 
 * Created on January 5, 2011, 9:27 PM
 */

#include "Enigma.h"

Enigma::Enigma() {
    rotors.append("JGDQOXUSCAMIFRVTPNEWKBLZYH");
    rotors.append("NTZPSFBOKMWRCJDIVLAEYUXHGQ");
    rotors.append("JVIUBHTCDYAKEQZPOSGXNRMWFL");
    reflector = "QWERTZUIOASDFGHJKPYXCVBNML";
}

void Enigma::enigma(bool cipher) {
    QString msg, out = "";
    msg = (cipher) ? clearMsg : cipherMsg;
    
    int posR2, posR3, curChar, forward, backward, kbLength = rotors.at(0).length()-1;
    
    for (curChar=0, posR2=0, posR3=0; curChar < msg.length(); curChar++) {
        if (curChar > 0 && (curChar%kbLength) == 0) {
            if ((posR2%kbLength) == 0)
                posR3 = (posR3+1)%kbLength;
            
            posR2 = (posR2+1)%kbLength;
        }

        QString deb = "";
        deb += msg.at(curChar);
        int pos = (msg.at(curChar).toAscii()-'A'+curChar+rotor1Pos)%kbLength;
        deb += QString(" -> %1").arg(rotors.at(0).at(pos));
        pos = (rotor2Pos+posR2+rotors.at(0).at(pos).toAscii()-'A') % kbLength;
        deb += QString(" -> %1").arg(rotors.at(1).at(pos));
        pos = (rotor3Pos+posR3+rotors.at(1).at(pos).toAscii()-'A') % kbLength;
        deb += QString(" -> %1").arg(rotors.at(2).at(pos));
        pos = (reflectorPos+rotors.at(2).at(pos).toAscii()-'A') % kbLength;
        deb += QString(" <-> %1").arg(reflector.at(pos));
        pos = (rotor3Pos+posR3+reflector.at(pos).toAscii()-'A') % kbLength;
        deb += QString(" -> %1").arg(rotors.at(2).at(pos));
        pos = (rotor2Pos+posR2+rotors.at(2).at(pos).toAscii()-'A') % kbLength;
        deb += QString(" -> %1").arg(rotors.at(1).at(pos));
        pos = (rotor1Pos+(curChar % kbLength)+rotors.at(1).at(pos).toAscii()-'A') % kbLength;
        deb += QString(" -> %1").arg(rotors.at(0).at(pos));

        qDebug() << deb;



        forward = reflector.at(
                    (reflectorPos+rotors.at(2).at(
                        (rotor3Pos+posR3+rotors.at(1).at(
                            (rotor2Pos+posR2+rotors.at(0).at(
                                (msg.at(curChar).toAscii()-'A'+curChar+rotor1Pos)%kbLength
                            ).toAscii()-'A')%kbLength
                        ).toAscii()-'A')%kbLength
                    ).toAscii()-'A')%kbLength
                ).toAscii()-'A';

        backward = rotors.at(0).at(
                    (rotor1Pos+(curChar%kbLength)+rotors.at(1).at(
                        (rotor2Pos+posR2+rotors.at(2).at(
                            (forward+posR3+rotor3Pos)%kbLength
                        ).toAscii()-'A')%kbLength
                    ).toAscii()-'A')%kbLength
                ).toAscii();

        out += backward;
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
