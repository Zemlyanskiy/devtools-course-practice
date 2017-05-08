// Copyright 2017 Lobanov Andrey

#include "include/LineSegment.h"
#include <iostream>
#include <string>

using std::string;
using std::stringstream;

double LineSegment2D::Get_Coeff(int count) {
  switch (count) {
    case 1: return coeff_A;
    case 2: return coeff_B;
    case 3: return coeff_C;
    default: throw "Invalid value";
  }
}

string LineSegment2D::checkIntersection(LineSegment2D line) {
  string str1, str2, str3;
  stringstream stream1, stream2;
  if ((line.Get_Coeff(1) / Get_Coeff(1) ==
      line.Get_Coeff(2) / Get_Coeff(2)) &&
      (line.Get_Coeff(1) / Get_Coeff(1) ==
      line.Get_Coeff(3) / Get_Coeff(3))) {
        str = "Lines are coincide";
  } else if (line.Get_Coeff(1)/Get_Coeff(1) == line.Get_Coeff(2)/Get_Coeff(2)) {
    str = "Lines are parallel";
  } else {
      double coord_X = (-1) * (Get_Coeff(3) * line.Get_Coeff(2) -
                line.Get_Coeff(3) * Get_Coeff(2)) /
                (Get_Coeff(1) * line.Get_Coeff(2) -
                Get_Coeff(2) * line.Get_Coeff(1));
      double coord_Y = (-1) * (Get_Coeff(1) * line.Get_Coeff(3) -
                line.Get_Coeff(1) * Get_Coeff(3)) /
                (Get_Coeff(1) * line.Get_Coeff(2) -
                line.Get_Coeff(1) * Get_Coeff(2));
    str1 = "Intersection point: (";
    stream1 << coord_X;
    stream1 >> str2;
    str2 += "; ";
    stream2 << coord_Y;
    stream2 >> str3;
    str3 += ")";
    str = str1 + str2 + str3;
  }
  return str;
}
