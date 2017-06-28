// Copyright 2017 Grechukhin Nikita

#include <gtest/gtest.h>

#include <vector>
#include <cmath>
#include <string>
#include <functional>

#include "../include/matrix_calculator_app.h"

using ::testing::internal::RE;

class MatrixCalculatorAppTest : public ::testing::Test {
 protected:
    void Act(const std::vector<std::string> &args_) {
        std::vector<const char *> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char **argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(const std::string &expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }
 private:
    MatrixCalculatorApp app_;
    std::string output_;
};

TEST_F(MatrixCalculatorAppTest, Do_Print_Help_Without_Arguments) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("This is a matrix calculator application\\..*");
}

TEST_F(MatrixCalculatorAppTest, Is_Checking_Number_Of_Arguments) {
    std::vector<std::string> args = { "4", "4", "4", "4", "5.5", "7.4" };

    Act(args);

    Assert("This is a matrix calculator application\\..*");
}
