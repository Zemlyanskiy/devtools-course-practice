//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_LIST_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_LIST_H_
#include "Link.h"
class List {
 public:
    List();
    List(const List &list);
    ~List();
    PValue GetValue();
    virtual int IsEmpty() const;
    int GetListlength() const;
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
    PLink pfirst;
    PLink plast;
    PLink pcurrlink;
    PLink pprevlink;
    PLink pstop;
    int currpos;
    int listlen;
    PLink GetLink(PValue pVal = NULL, PLink pLink = NULL);
};
#endif  //  MODULES_POLINOM_CALCULATOR_INCLUDE_LIST_H_

