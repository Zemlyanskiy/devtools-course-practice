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
  ASSERT_NO_THROW(LineSegment2D line(0, 0, 0));
}

TEST(LineSegment, Can_Get_A_Value) {
  LineSegment2D line(-33.8, -4.8, 5.1);
  ASSERT_DOUBLE_EQ(-33.8, line.Get_A());
}

TEST(LineSegment, Can_Get_B_Value) {
  LineSegment2D line(-3.0, -4.47, 5.39);
  ASSERT_DOUBLE_EQ(-4.47, line.Get_B());
}

TEST(LineSegment, Can_Get_C_Value) {
  LineSegment2D line(-3.0, -4.0, 5.28);
  ASSERT_DOUBLE_EQ(5.28, line.Get_C());
}

TEST(LineSegment, Get_Value_Works_Correctly) {
  LineSegment2D line(2.22, 2.22, 2.22);
  ASSERT_TRUE(line.Get_A() == line.Get_B() &&
              line.Get_A() == line.Get_C());
}

TEST(LineSegment, Can_Set_Initial_A_Value) {
  LineSegment2D line(0, 13.4, 11);
  line.Set_A(3.3);
  ASSERT_DOUBLE_EQ(line.Get_A(), 3.3);
}

TEST(LineSegment, Can_Set_Initial_B_Value) {
  LineSegment2D line(3.3, 0, 11);
  line.Set_B(13.7);
  ASSERT_DOUBLE_EQ(line.Get_B(), 13.7);
}

TEST(LineSegment, Can_Set_Initial_C_Value) {
  LineSegment2D line(0, 0, 0);
  line.Set_C(-73.7);
  ASSERT_DOUBLE_EQ(line.Get_C(), -73.7);
}

TEST(LineSegment, Set_Initial_Value_Works_Correctly) {
  LineSegment2D line(0, 0, 0);
  line.Set_A(1.1);
  line.Set_B(10.3);
  line.Set_C(-3.5);
  EXPECT_TRUE((1.1 == line.Get_A()) &&
             (10.3 == line.Get_B()) &&
             (-3.5 == line.Get_C()));
}

TEST(LineSegmentFunction, Show_That_Lines_Are_Coincide) {
  string str = "Lines are coincide";
  LineSegment2D line(2.0, 3.1, 4.2);
  LineSegment2D line1(4.0, 6.2, 8.4);
  ASSERT_EQ(str, line.checkIntersection(line1));
}

TEST(LineSegment, Show_That_Lines_Are_Parallel) {
  string str = "Lines are parallel";
  LineSegment2D line(31.28, 3.1, 4.2);
  LineSegment2D line1(62.56, 6.2, 1.4);
  ASSERT_EQ(str, line.checkIntersection(line1));
}

TEST(LineSegment, Can_Create_Point_Intersect_Two_LineSegment) {
  LineSegment2D line(2.23, 3.1, 4.2);
  LineSegment2D line1(4.46, 3.2, 1.4);
  ASSERT_NO_THROW(line.checkIntersection(line1));
}

TEST(LineSegment, Show_Point_Intersect_Two_LineSegment) {
  string str = "Intersection point: (-4.73866; 2.61343)";
  LineSegment2D line(8.2, 10.2, 12.2);
  LineSegment2D line1(3.1, 5.2, 1.1);
  ASSERT_EQ(str, line.checkIntersection(line1));
}
