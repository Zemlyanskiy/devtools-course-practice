// Copyright 2017 Lobanov Andrey

#ifndef MODULES_INTERSECTTWOLINE_INCLUDE_LINESEGMENT_H_
#define MODULES_INTERSECTTWOLINE_INCLUDE_LINESEGMENT_H_

#include <string>
#include <sstream>

using std::string;

class LineSegment2D {
 protected:
    string str;
    double coeff_A;
    double coeff_B;
    double coeff_C;

 public:
    LineSegment2D(double A, double B, double C) {
        coeff_A = A;
        coeff_B = B;
        coeff_C = C;
    }
    void Set_A(double new_A) {
        coeff_A = new_A;
    }
    void Set_B(double new_B) {
        coeff_B = new_B;
    }
    void Set_C(double new_C) {
        coeff_C = new_C;
    }
    double Get_Coeff(int count);
    string checkIntersection(LineSegment2D line);
};
#endif  // MODULES_INTERSECTTWOLINE_INCLUDE_LINESEGMENT_H_
