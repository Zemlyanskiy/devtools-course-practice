//  Copyright 2017 Ivan Kiselev

#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_THEADRING_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_THEADRING_H_
#include "List.h"
class THeadRing : public List {
 public:
    THeadRing();
    virtual void InsFirst(PValue pVal = NULL);
    virtual void DelFirst(void);

 protected:
    PLink pHead_;
};
#endif  //  MODULES_POLINOM_CALCULATOR_INCLUDE_THEADRING_H_

