//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_TDATLINK_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_TDATLINK_H_
#include "TRootLink.h"
class TDatLink : public TRootLink {
 public:
     explicit TDatLink(PValue pVal = NULL, PTRootLink pN = NULL);
     TDatLink(const TDatLink &Link);
     ~TDatLink();
     virtual void SeValue(PValue pVal);
     virtual PValue GeValue();
     TDatLink* GetNextDatLink();
    friend class TDatList;

 protected:
    PValue pValue_;  //  Value
};
typedef TDatLink *PTDatLink;
#endif  //  MODULES_POLINOM_CALCULATOR_INCLUDE_TDATLINK_H_
