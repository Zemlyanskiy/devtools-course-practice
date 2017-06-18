//  Copyright 2017 Ivan Kiselev
#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_MONOM_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_MONOM_H_
#include "Value.h"
#include <iostream>

class Monom : public Value {
 public:
    explicit Monom(int cval = 1, int x = 0, int y = 0, int z = 0);
    ~Monom();
    virtual Value * GetCopy();
    void SetCoeff_(int cval);
    int  GetCoeff_(void);
    void SetIndexX(int ival);
    void SetIndexY(int ival);
    void SetIndexZ(int ival);
    int GetIndexX(void);
    int GetIndexY(void);
    int GetIndexZ(void);
    Monom& operator=(const Monom &tm);
    Monom operator*(Monom mon);
    bool operator==(const Monom &tm);
    bool EqualityExponent(Monom tm);
    bool operator<(Monom tm);  //  prioritet x > y > z
    bool operator>(Monom tm);  //  prioritet x > y > z
    friend std::ostream& operator<<(std::ostream &os, Monom * tm);
    friend class Polinom;

 protected:
    int Coeff_;  //  monom's Coeff_
    int XInd_;  //  index X
    int YInd_;  //  index Y
    int ZInd_;  //  index Z
};
#endif  //  MODULES_POLINOM_CALCULATOR_INCLUDE_MONOM_H_
