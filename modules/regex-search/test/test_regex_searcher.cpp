// Copyright 2017 Grachev Vlad

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/regex_search.h"
#include "include/regex_searcher.h"
#include "src/regex_searcher.cpp"

using ::testing::internal::RE;
using std::vector;
using std::string;

class RegexSearcherTest : public ::testing::Test {
 protected:
    // virtual void SetUp() {}

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

    std::string GetResultString() {
        return output_;
    }

 private:
    RegexSearcher app_;
    string output_;
};

TEST_F(RegexSearcherTest, Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a simple regular expressions searcher\\..*");
}

TEST_F(RegexSearcherTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "avc" };

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(RegexSearcherTest, Can_Detect_Too_Long_Regular_Exp) {
    std::string regular_expression;
    for (int i = 0; i < 51; i++)
        regular_expression += "aaa";

    vector<string> args = { regular_expression, "abc"};
    Act(args);

    Assert("Regular expression is too long!.*");
}

TEST_F(RegexSearcherTest, Can_Detect_Incorrect_Regular_Expression) {
    std::string regular_expression = "ds{3}{2}";
    vector<string> args = { regular_expression, "abc" };

    Act(args);

    Assert("Regular expression is incorrect!.*");
}

TEST_F(RegexSearcherTest, Can_Detect_Too_Long_Text) {
    std::string user_text;
    for (int i = 0; i < 1005; i++)
        user_text += "a";

    vector<string> args = { "a", user_text };
    Act(args);

    Assert("Your text is too long!*.");
}

TEST_F(RegexSearcherTest, Dont_Find_Not_Contained_Expression) {
    std::string regular_expression = "abc";

    vector<string> args = { regular_expression, "bcacba" };
    Act(args);

    Assert("Not found!\n");
}

TEST_F(RegexSearcherTest, Can_Find_Contained_Expression) {
    std::string regular_expression = "(vc){2}";

    vector<string> args = { regular_expression, "aabvcvcfjs" };
    Act(args);

    Assert("vcvc");
}
