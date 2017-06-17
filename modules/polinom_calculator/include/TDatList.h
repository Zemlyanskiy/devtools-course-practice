//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_TDATLIST_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_TDATLIST_H_
#include "TDatLink.h"
class TDatList {
 public:
    TDatList();
    TDatList(const TDatList &list);
    ~TDatList();
    PValue GeValue();
    virtual int IsEmpty() const;
    int GetListLength() const;
    virtual void Reset(void);
    virtual bool IsListEnded(void) const;
    int GoNext(void);
    virtual void InsFirst(PValue pVal = NULL);
    virtual void InsLast(PValue pVal = NULL);
    virtual void InsCurrent(PValue pVal = NULL);
    virtual void DelFirst(void);
    virtual void DelCurrent(void);
    virtual void DelList(void);

 protected:
    PTDatLink pFirst;
    PTDatLink pLast;
    PTDatLink pCurrLink;
    PTDatLink pPrevLink;
    PTDatLink pStop;
    int CurrPos;
    int ListLen;
    PTDatLink GetLink(PValue pVal = NULL, PTDatLink pLink = NULL);
};
#endif  //  MODULES_POLINOM_CALCULATOR_INCLUDE_TDATLIST_H_

