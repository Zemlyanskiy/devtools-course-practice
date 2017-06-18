//  Copyright 2017 Ivan Kiselev
#include "../include/Monom.h"
#include <iostream>
Monom::Monom(int cval, int x, int y, int z) {
    Coeff_ = cval;
    XInd_ = x;
    YInd_ = y;
    ZInd_ = z;
}

Monom::~Monom() {}

void Monom::SetCoeff_(int cval) {
    Coeff_ = cval;
}

int Monom::GetCoeff_(void) {
    return Coeff_;
}

void Monom::SetIndexX(int ival) {
    XInd_ = ival;
}

void Monom::SetIndexY(int ival) {
    YInd_ = ival;
}

void Monom::SetIndexZ(int ival) {
    ZInd_ = ival;
}

int Monom::GetIndexX(void) {
    return XInd_;
}

int Monom::GetIndexY(void) {
    return YInd_;
}

int Monom::GetIndexZ(void) {
    return ZInd_;
}

Monom& Monom::operator=(const Monom &tm) {
    Coeff_ = tm.Coeff_;
    XInd_ = tm.XInd_;
    YInd_ = tm.YInd_;
    ZInd_ = tm.ZInd_;
    return *this;
}

std::ostream& operator<<(std::ostream &os, Monom * tm) {
    if (tm->GetCoeff_() > 0)
        os << " + " << tm->GetCoeff_();
    else
        os << " - " << -tm->GetCoeff_();
    if (tm->GetIndexX() != 0) os << " * x^" << tm->GetIndexX();
    if (tm->GetIndexY() != 0) os << " * y^" << tm->GetIndexY();
    if (tm->GetIndexZ() != 0) os << " * z^" << tm->GetIndexZ();
    return os;
}

Monom Monom::operator*(Monom mon) {
    Monom* that = new Monom(0, 0, 0, 0);
    that->Coeff_ = this->Coeff_ * mon.Coeff_;
    that->SetIndexX(this->GetIndexX() + mon.GetIndexX());
    that->SetIndexY(this->GetIndexY() + mon.GetIndexY());
    that->SetIndexZ(this->GetIndexZ() + mon.GetIndexZ());
    return *that;
}

bool Monom::operator==(const Monom &tm) {
    return ((Coeff_ == tm.Coeff_) && (XInd_ == tm.XInd_)
        && (YInd_ == tm.YInd_) && (ZInd_ == tm.ZInd_));
}

bool Monom::EqualityExponent(Monom tm) {
    return (XInd_ == tm.XInd_) && (YInd_ == tm.YInd_)
        && (ZInd_ == tm.ZInd_);
}

bool Monom::operator<(Monom tm) {  //  prioritet x > y > z
    if (EqualityExponent(tm)) return false;
    if (XInd_ > tm.XInd_)
        return false;
    else if (XInd_ < tm.XInd_)
        return true;
    // XInd_ == tm.XInd_
    if (YInd_ > tm.YInd_)
        return false;
    else if (YInd_ < tm.YInd_)
        return true;
    // & YInd_ == tm.YInd_
    if (ZInd_ > tm.ZInd_)
        return false;
    return true;
}

bool Monom::operator>(Monom tm) {  //  prioritet x > y > z
    if (EqualityExponent(tm)) return false;
    if (XInd_ < tm.XInd_)
        return false;
    else if (XInd_ > tm.XInd_)
        return true;
    // XInd_ == tm.XInd_
    if (YInd_ < tm.YInd_)
        return false;
    else if (YInd_ > tm.YInd_)
        return true;
    // & YInd_ == tm.YInd_
    if (ZInd_ < tm.ZInd_)
        return false;
    return true;
}

Value* Monom::GetCopy() {
    return new Monom(Coeff_, XInd_, YInd_, ZInd_);
}
