#ifndef CAESAR_H
#define	CAESAR_H

#include "Vigenere.h"
#include <QtGui>

class Caesar : public Vigenere {

public:
    void setKey(unsigned shift);
    int crack ( );
private:


};

#endif	/* CAESAR_H */
