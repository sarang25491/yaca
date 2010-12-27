/* 
 * File:   Caesar.h
 * Author: alex
 *
 * Created on December 24, 2010, 1:28 PM
 */

#ifndef CAESAR_H
#define	CAESAR_H

#include "Vigenere.h"
#include <QtGui>

class Caesar : public Vigenere {
public:
    Caesar();
    virtual ~Caesar();
    void setKey(unsigned shift);
private:

};

#endif	/* CAESAR_H */

