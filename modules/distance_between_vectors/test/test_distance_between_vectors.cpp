// Copyright 2017 Gorozhanin Mihail

#include <gtest/gtest.h>
#include <vector>
#include "include/distance_between_vectors.h"

TEST(DistanceBetweenVectors, Different_Size_Vectors) {
  std::vector<float> V1(4);
  std::vector<float> V2(5);
  Metric::TypeMetric Type = Metric::L2;

  for (int i = 0; i < 4; i++) {
    V1[i] = static_cast<float>(i*(0.3+0.01*i));
  }
  for (int i = 0; i < 5; i++) {
    V2[i] = static_cast<float>(i+2);
  }
  float result = DistanceBetweenVectors::CalculateDistance(V1, V2, Type);

  EXPECT_FLOAT_EQ(result, 0.0f);
}

TEST(DistanceBetweenVectors, Different_Size_Vectors_With_Different_Metric) {
  std::vector<float> V1(4);
  std::vector<float> V2(5);
  Metric::TypeMetric Type1 = Metric::L2;
  Metric::TypeMetric Type2 = Metric::LInf;

  for (int i = 0; i < 4; i++) {
    V1[i] = static_cast<float>(i*(0.3+0.01*i));
  }
  for (int i = 0; i < 5; i++) {
    V2[i] = static_cast<float>(i+2);
  }
  float result1 = DistanceBetweenVectors::CalculateDistance(V1, V2, Type1);
  float result2 = DistanceBetweenVectors::CalculateDistance(V1, V2, Type2);

  EXPECT_FLOAT_EQ(result1, result2);
}

TEST(DistanceBetweenVectors, Equal_Size_Vectors_Final) {
  std::vector<float> V1(4);
  std::vector<float> V2(4);
  Metric::TypeMetric Type = Metric::L1;

  for (int i = 0; i < 4; i++) {
    V1[i] = static_cast<float>(i+2);
  }
  for (int i = 0; i < 4; i++) {
    V2[i] = static_cast<float>(i);
  }
  float result = DistanceBetweenVectors::CalculateDistance(V1, V2, Type);

  EXPECT_FLOAT_EQ(result, 8.0f);
}

TEST(DistanceBetweenVectors, Equal_Size_Vectors_Inf) {
  std::vector<float> V1(4);
  std::vector<float> V2(4);
  Metric::TypeMetric Type = Metric::LInf;

  for (int i = 0; i < 4; i++) {
    V1[i] = static_cast<float>(i+2);
  }
  for (int i = 0; i < 4; i++) {
    V2[i] = static_cast<float>(i);
  }
  float result = DistanceBetweenVectors::CalculateDistance(V1, V2, Type);

  EXPECT_FLOAT_EQ(result, 2.0f);
}
