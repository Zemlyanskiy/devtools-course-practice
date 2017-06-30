// Copyright 2017 Zemlyanskiy Nikita

#include <gtest/gtest.h>
#include <string.h>
#include <vector>
#include <cmath>
#include <string>
#include <functional>

#include "../include/matrix_calculator_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class MatrixCalculatorAppTest : public ::testing::Test {
 protected:
    void Act(const vector<string> &args_) {
        vector<const char *> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char **argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(const string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }
 private:
    MatrixCalculatorApp app_;
    string output_;
};

TEST_F(MatrixCalculatorAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a matrix calculator application\\..*");
}

TEST_F(MatrixCalculatorAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "4", "4", "+", "5" };

    Act(args);

    Assert("ERROR: Should be not more than 3 arguments\\..*");
}

TEST_F(MatrixCalculatorAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"3f", "2", "+"};

    Act(args);

    Assert("Wrong number format!*");
}

TEST_F(MatrixCalculatorAppTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "2.3", "3.2", "d" };

    Act(args);

    Assert("Wrong operation format!*");
}

TEST_F(MatrixCalculatorAppTest, Can_Search_Det_Of_Sum) {
    vector<string> args = {"4.4", "5.5", "+"};

    Act(args);

    Assert("Det of sum = *");
}

TEST_F(MatrixCalculatorAppTest, Can_Search_Det_Of_Dif) {
    vector<string> args = { "4.4", "5.5", "-" };

    Act(args);

    Assert("Det of difference = *");
}

TEST_F(MatrixCalculatorAppTest, Can_Search_Det_Of_Mul) {
    vector<string> args = { "4.4", "5.5", "*" };

    Act(args);

    Assert("Det of multiplication = *");
}
