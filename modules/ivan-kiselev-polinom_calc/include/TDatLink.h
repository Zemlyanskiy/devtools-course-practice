//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_
#define MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_
#include "TRootLink.h"
class TDatLink : public TRootLink {
 protected:
    PTDatValue pValue;  //  Value
 public:
    TDatLink(PTDatValue pVal = NULL, PTRootLink pN = NULL) :TRootLink(pN) {
        pValue = pVal;
    }
    TDatLink(TDatLink &Link) : TRootLink(Link.pNext) {
        pValue = Link.GetDatValue();
    }
    ~TDatLink() {}
    virtual void SetDatValue(PTDatValue pVal) {
        pValue = pVal;
    }
    virtual PTDatValue GetDatValue() {
        return pValue;
    }
    TDatLink* GetNextDatLink() {
        return reinterpret_cast<TDatLink*>(pNext);
    }
    friend class TDatList;
};
typedef TDatLink *PTDatLink;
#endif  //  MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_
