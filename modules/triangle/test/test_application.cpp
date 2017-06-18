// Copyright 2017 Tarasov Oleg

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
        // std::cout << output_ << std::endl;
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    Application app_;
    string output_;
};

TEST_F(ApplicationTest, Do_Print_Help) {
    vector<string> args = {};

    Act(args);

    Assert("This is a triangle calculator application.*");
}

TEST_F(ApplicationTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "1", "2", "3", "4" };

    Act(args);

    Assert("ERROR: Incorrect arguments num.*");
}

TEST_F(ApplicationTest, Can_Detect_Wrong_Number_Format_8args) {
    vector<string> args = { "1.1", "2.0", "3.4", "4.1", "8.0", "-1.9", "side" };

    Act(args);

    Assert("ERROR: Incorrect arguments num.*");
}

TEST_F(ApplicationTest, Can_Detect_Wrong_Number_Format_7args) {
    vector<string> args = { "1.1", "2.0", "3.4", "4.1", "8.0", "-1.9",
        "median", "2" };

    Act(args);

    Assert("ERROR: Incorrect arguments num.*");
}

TEST_F(ApplicationTest, Can_Calculate_Triangle_Side) {
    vector<string> args = { "0.0", "0.0", "3.0", "0.0", "0.0", "4.0",
        "side", "1" };

    Act(args);

    Assert("Triangle Side #1 = 5.*");
}

TEST_F(ApplicationTest, Can_Calculate_Triangle_Corner) {
    vector<string> args = { "0.0", "0.0", "3.0", "0.0", "0.0", "4.0",
        "corner", "1" };

    Act(args);

    Assert("Triangle Corner #1 = 1.5708.*");  // 90 degrees in radians
}

TEST_F(ApplicationTest, Can_Calculate_Triangle_Square) {
    vector<string> args = { "0.0", "0.0", "3.0", "0.0", "0.0", "4.0",
        "square" };

    Act(args);

    Assert("Triangle Square = 6.*");
}

TEST_F(ApplicationTest, Can_Calculate_Triangle_Perimeter) {
    vector<string> args = { "0.0", "0.0", "3.0", "0.0", "0.0", "4.0",
        "perimeter" };

    Act(args);

    Assert("Triangle Perimeter = 12.*");
}

TEST_F(ApplicationTest, Can_Calculate_Triangle_Median) {
    vector<string> args = { "0.0", "0.0", "3.0", "0.0", "0.0", "4.0",
        "median" };

    Act(args);

    Assert("Triangle Median Coords = 1, 1.33*");
}

TEST_F(ApplicationTest, Can_Calculate_Triangle_Circumscribed_Circle) {
    vector<string> args = { "0.0", "0.0", "3.0", "0.0", "0.0", "4.0",
        "circumscribed_circle" };

    Act(args);

    Assert("Triangle Circumscribed Circle Center = 1.5, 2*");
}

TEST_F(ApplicationTest, Can_Calculate_Triangle_Inscribed_Circle) {
    vector<string> args = { "0.0", "0.0", "3.0", "0.0", "0.0", "4.0",
        "inscribed_circle" };

    Act(args);

    Assert("Triangle Inscribed Circle Center = 1, 1*");
}

TEST_F(ApplicationTest, Can_Throw_Exception) {
    vector<string> args = { "0.0", "0.0", "3.0", "0.0", "0.0", "4.0",
        "incorrect_type" };

    EXPECT_ANY_THROW(Act(args));
}

TEST_F(ApplicationTest, Can_Throw_Exception_Parse_Int) {
    vector<string> args = { "0.0", "0.0", "3.0", "0.0", "0.0", "4.0",
        "side", "none" };

    Act(args);

    Assert("Wrong number format*");
}
