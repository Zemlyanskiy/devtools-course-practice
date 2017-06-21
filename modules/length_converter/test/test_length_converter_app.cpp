// Copyright 2017 Dmitrichev Nikita

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/length_converter_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class LengthConverterAppTest : public ::testing::Test {
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

TEST_F(LengthConverterAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a converter of a length application\\..*");
}

TEST_F(LengthConverterAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1", "CENTIMETRE" };

    Act(args);

    Assert("ERROR: Should be 3 arguments.*");
}

TEST_F(LengthConverterAppTest, If_Arguments_Are_Right_Is_All_Right) {
    vector<string> args = { "1", "DECIMETRE", "METRE"};

    Act(args);

    Assert("Result of conversation = 0.1");
}

TEST_F(LengthConverterAppTest, Can_Detect_Wrong_Length_Name_Format) {
    vector<string> args = { "2", "MILLIMETRE", "MC"};

    Act(args);

    Assert("Wrong length's name format!");
}

TEST_F(LengthConverterAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "two", "MICROMETRE", "KILOMETRE" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(LengthConverterAppTest, Can_Detect_Negative_Length) {
    vector<string> args = { "-1", "MICROMETRE", "KILOMETRE" };

    Act(args);

    Assert("The length can't be less than 0!");
}

TEST_F(LengthConverterAppTest, Can_Convert_INCH_to_HAND) {
    vector<string> args = { "1", "INCH", "HAND" };

    Act(args);

    Assert("Result of conversation = 0.25");
}

TEST_F(LengthConverterAppTest, Can_Convert_LINK_to_FOOT) {
    vector<string> args = { "1", "LINK", "FOOT" };

    Act(args);

    Assert("Result of conversation = 0.66");
}

TEST_F(LengthConverterAppTest, Can_Convert_YARD_to_ROD) {
    vector<string> args = { "0", "YARD", "ROD" };

    Act(args);

    Assert("Result of conversation = 0");
}

TEST_F(LengthConverterAppTest, Can_Convert_CHAIN_to_FURHLONG) {
    vector<string> args = { "15", "CHAIN", "FURHLONG" };

    Act(args);

    Assert("Result of conversation = 1.5");
}

TEST_F(LengthConverterAppTest, Can_Convert_MILE_to_LEAGUE) {
    vector<string> args = { "0.131", "MILE", "LEAGUE" };

    Act(args);

    Assert("Result of conversation = 0.0436667");
}

TEST_F(LengthConverterAppTest, Can_Convert_MICROMETRE_to_CENTIMETRE) {
    vector<string> args = { "500", "MICROMETRE", "CENTIMETRE" };

    Act(args);

    Assert("Result of conversation = 0.05");
}

TEST_F(LengthConverterAppTest, Can_Convert_CENTIMETRE_to_KILOMETRE) {
    vector<string> args = { "100000", "CENTIMETRE", "KILOMETRE" };

    Act(args);

    Assert("Result of conversation = 1");
}
