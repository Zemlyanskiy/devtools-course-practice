//  Copyright 2017 Ivan Kiselev

#ifndef MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_THEADRING_H_
#define MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_THEADRING_H_
#include "TDatList.h"
class THeadRing : public TDatList {
public:
	THeadRing();
	virtual void InsFirst(PTDatValue pVal = NULL);
	virtual void DelFirst(void);

protected:
    PTDatLink pHead_;
};
#endif  //  MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_THEADRING_H_

