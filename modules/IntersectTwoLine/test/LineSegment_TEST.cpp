// Copyright 2017 Lobanov Andrey

#include "include/LineSegment.h"
#include <gtest/gtest.h>
#include <string>

using std::string;

TEST(LineSegment, Can_Create_LineSegment_With_Initial_Values) {
  ASSERT_NO_THROW(LineSegment2D line(2.0, 3.1, 4.2));
}

TEST(LineSegment, Can_Create_LineSegment_With_Negative_Values) {
  ASSERT_NO_THROW(LineSegment2D line(-13.17, -31.09, -44.229));
}

TEST(LineSegment, Can_Create_Zero_Segment_) {
  ASSERT_NO_THROW(LineSegment2D line(0.0, 0.0, 0.0));
}

TEST(LineSegment, Can_Get_A_Value) {
  // Arrange
  LineSegment2D line(-33.8, -4.8, 5.1);
  double coeff;
  // Act
  coeff = line.Get_Coeff(1);
  // Assert
  ASSERT_DOUBLE_EQ(-33.8, coeff);
}

TEST(LineSegment, Can_Get_B_Value) {
  // Arrange
  LineSegment2D line(-3.0, -4.47, 5.39);
  double coeff;
  // Act
  coeff = line.Get_Coeff(2);
  // Assert
  ASSERT_DOUBLE_EQ(-4.47, coeff);
}

TEST(LineSegment, Can_Get_C_Value) {
  // Arrange
  LineSegment2D line(-3.0, -4.0, 5.28);
  double coeff;
  // Act
  coeff = line.Get_Coeff(3);
  // Assert
  ASSERT_DOUBLE_EQ(5.28, coeff);
}

TEST(LineSegment, Cant_Get_With_Incorrect_Initialization) {
  // Arrange
  LineSegment2D line(1.0, -4.0, 5.2);
  // Act and Assert
  ASSERT_ANY_THROW(line.Get_Coeff(10));
}

TEST(LineSegment, Get_Value_Works_Correctly) {
  // Arrange
  LineSegment2D line(2.22, 2.22, 2.22);
  double a, b, c;
  // Act
  a = line.Get_Coeff(1);
  b = line.Get_Coeff(2);
  c = line.Get_Coeff(3);
  // Assert
  ASSERT_TRUE(a == b && a == c);
}

TEST(LineSegment, Can_Set_Initial_A_Value) {
  // Arrange
  LineSegment2D line(0.0, 13.4, 11.3);
  double coeff;
  // Act
  line.Set_A(3.3);
  coeff = line.Get_Coeff(1);
  // Assert
  ASSERT_DOUBLE_EQ(coeff, 3.3);
}

TEST(LineSegment, Can_Set_Initial_B_Value) {
  // Arrange
  LineSegment2D line(3.3, 0.0, 11.3);
  double coeff;
  // Act
  line.Set_B(13.7);
  coeff = line.Get_Coeff(2);
  // Assert
  ASSERT_DOUBLE_EQ(coeff, 13.7);
}

TEST(LineSegment, Can_Set_Initial_C_Value) {
  // Arrange
  LineSegment2D line(3.3, 7.4, 0.0);
  double coeff;
  // Act
  line.Set_C(13.7);
  coeff = line.Get_Coeff(3);
  // Assert
  ASSERT_DOUBLE_EQ(coeff, 13.7);
}

TEST(LineSegment, Set_Initial_Value_Works_Correctly) {
  // Arrange
  LineSegment2D line(0.0, 0.0, 0.0);
  double a, b, c;
  // Act
  line.Set_A(1.1);
  line.Set_B(10.3);
  line.Set_C(-3.5);
  a = line.Get_Coeff(1);
  b = line.Get_Coeff(2);
  c = line.Get_Coeff(3);
  // Assert
  EXPECT_TRUE((1.1 == a) && (10.3 == b) && (-3.5 == c));
}

TEST(LineSegment, Show_That_Lines_Are_Coincide) {
  // Arrange
  string str, str1 = "Lines are coincide";
  LineSegment2D line(2.0, 3.1, 4.2);
  LineSegment2D line1(4.0, 6.2, 8.4);
  // Act
  str = line.checkIntersection(line1);
  // Assert
  ASSERT_EQ(str, str1);
}

TEST(LineSegment, Show_That_Lines_Are_Parallel) {
  // Arrange
  string str, str1 = "Lines are parallel";
  LineSegment2D line(31.28, 3.1, 4.2);
  LineSegment2D line1(62.56, 6.2, 1.4);
  // Act
  str = line.checkIntersection(line1);
  // Assert
  ASSERT_EQ(str, str1);
}

TEST(LineSegment, Can_Create_Point_Intersect_Two_LineSegment) {
  // Arrange
  LineSegment2D line(2.23, 3.1, 4.2);
  LineSegment2D line1(4.46, 3.2, 1.4);
  // Act and Assert
  ASSERT_NO_THROW(line.checkIntersection(line1));
}

TEST(LineSegment, Show_Point_Intersect_Two_LineSegment) {
  // Arrange
  string str, str1 = "Intersection point: (-4.73866; 2.61343)";
  LineSegment2D line(8.2, 10.2, 12.2);
  LineSegment2D line1(3.1, 5.2, 1.1);
  // Act
  str = line.checkIntersection(line1);
  // Assert
  ASSERT_EQ(str, str1);
}
