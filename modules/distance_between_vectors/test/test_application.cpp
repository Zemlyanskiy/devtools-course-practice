// Copyright 2017 Lobanov Andrey

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class ApplicationTest : public ::testing::Test {
 protected:
  void Act(vector<string> args_) {
    vector<const char*> options;

    options.push_back("appname");
    for (size_t i = 0; i < args_.size(); ++i) {
      options.push_back(args_[i].c_str());
    }

    const char** argv = &options.front();
    int argc = static_cast<int>(args_.size()) + 1;

    output_ = app_(argc, argv);
  }

  void Assert(std::string expected) {
    EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
  }

 private:
  Application app_;
  string output_;
};

TEST_F(ApplicationTest, Do_Print_Help) {
  // Arrange
  vector<string> args = {};
  // Act
  Act(args);
  // Assert
  Assert(
    "This is the application for calculating the distances between vectors*");
}

TEST_F(ApplicationTest, Can_Detect_Wrong_Number_Format) {
  // Arrange
  vector<string> args = { "1", "2" };
  // Act
  Act(args);
  // Assert
  Assert("ERROR: Should be 4 arguments.");
}

TEST_F(ApplicationTest, Can_Detect_Wrong_Initial_Value) {
  // Arrange
  vector<string> args = { "7", "dva", "five", "L1" };
  // Act
  Act(args);
  // Assert
  Assert("ERROR: Wrong number format!*");
}

TEST_F(ApplicationTest, Can_Detect_Wrong_Type_Metric) {
  // Arrange
  vector<string> args = { "5", "14", "3", "tri" };
  // Act
  Act(args);
  // Assert
  Assert("ERROR: Incorrect type metric!*");
}

TEST_F(ApplicationTest, Can_Detect_Wrong_Vectors_Size) {
  // Arrange
  vector<string> args = { "-3", "14", "3", "LInf" };
  // Act
  Act(args);
  // Assert
  Assert("ERROR: Incorrect size!*");
}

TEST_F(ApplicationTest, Can_Calculate_Distance_Metric_L1) {
  // Arrange
  vector<string> args = { "4", "5", "3.3", "L1"};
  // Act
  Act(args);
  // Assert
  Assert("Distance between vectors: 33.8*");
}

TEST_F(ApplicationTest, Can_Calculate_Distance_Metric_L2) {
  // Arrange
  vector<string> args = { "4", "5", "3.3", "L2" };
  // Act
  Act(args);
  // Assert
  Assert("Distance between vectors: 19.6*");
}

TEST_F(ApplicationTest, Can_Calculate_Distance_Metric_L3) {
  // Arrange
  vector<string> args = { "4", "5", "3.3", "L3" };
  // Act
  Act(args);
  // Assert
  Assert("Distance between vectors: 17*");
}

TEST_F(ApplicationTest, Can_Calculate_Distance_Metric_L4) {
  // Arrange
  vector<string> args = { "4", "5", "3.3", "L4" };
  // Act
  Act(args);
  // Assert
  Assert("Distance between vectors: 16.14*");
}

TEST_F(ApplicationTest, Can_Calculate_Distance_Metric_LInf) {
  // Arrange
  vector<string> args = { "4", "5", "3.3", "LInf" };
  // Act
  Act(args);
  // Assert
  Assert("Distance between vectors: 15.2*");
}
