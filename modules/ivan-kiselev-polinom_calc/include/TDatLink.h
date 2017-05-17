//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_
#define MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_
#include "TRootLink.h"
class TDatLink : public TRootLink {
 protected:
    PTDatValue pValue_;  //  Value
 public:
     explicit TDatLink(PTDatValue pVal = NULL, PTRootLink pN = NULL)
         : TRootLink(pN) {
        pValue_ = pVal;
    }
    TDatLink(TDatLink &Link) : TRootLink(Link.pNext_) {
        pValue_ = Link.GetDatValue();
    }
    ~TDatLink() {}
    virtual void SetDatValue(PTDatValue pVal) {
        pValue_ = pVal;
    }
    virtual PTDatValue GetDatValue() {
        return pValue_;
    }
    TDatLink* GetNextDatLink() {
        return reinterpret_cast<TDatLink*>(pNext_);
    }
    friend class TDatList;
};
typedef TDatLink *PTDatLink;
#endif  //  MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_
