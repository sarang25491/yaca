/* 
 * File:   BaseAlgo.h
 * Author: alex
 *
 * Created on December 22, 2010, 4:59 PM
 */

#ifndef BASEALGO_H
#define	BASEALGO_H

#include <QtGui>
#include <QDebug>

class BaseAlgo {
    
public:
    BaseAlgo();
    virtual ~BaseAlgo();
    void setClearMsg(QString clearMsg);
    QString getClearMsg() const;
    void setCipherMsg(QString cipherMsg);
    QString getCipherMsg() const;
    virtual void cipher();
    virtual void decipher();
protected:
    QString cipherMsg;
    QString clearMsg;
    
};

#endif	/* BASEALGO_H */
