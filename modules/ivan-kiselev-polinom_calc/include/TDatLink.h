//  Copyright 2017 Ivan Kiselev

#ifndef MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_
#define MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_

#include "TRootLink.h"

class TDatLink;
typedef TDatLink *PTDatLink;

class TDatLink : public TRootLink {
protected:
 PTDatValue pValue;  //  Value
public:	TDatLink(PTDatValue pVal = NULL, PTRootLink pN = NULL) :TRootLink(pN)
 {
 pValue = pVal;
 }
 ~TDatLink() {}
 void SetDatValue(PTDatValue pVal)
 {
 pValue = pVal;
 }
 PTDatValue GetDatValue()
 {
 return pValue;
 }
 PTDatLink GetNextDatLink()
 {
 return (PTDatLink)pNext;
 }
 friend class TDatList;
};

#endif  //  MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_
