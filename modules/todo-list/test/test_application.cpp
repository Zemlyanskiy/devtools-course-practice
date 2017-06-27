// Copyright 2017 Bakalin Andrey

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
    vector<string> args = {};

    Act(args);

    Assert("This is a simple TODO-list application.");
}

TEST_F(ApplicationTest, Application_Indicates_Incorrect_Beginning) {
    vector<string> args = {"todo", "list>"};

    Act(args);

    Assert("Wrong arguments format!");
}

TEST_F(ApplicationTest, Application_Indicates_Incorrect_End) {
    vector<string> args = {"<todo", "list"};

    Act(args);

    Assert("Wrong arguments format!");
}

TEST_F(ApplicationTest, Application_Indicates_Two_Beginnings) {
    vector<string> args = { "<example", "<list>" };

    Act(args);

    Assert("Wrong arguments format!");
}

TEST_F(ApplicationTest, Application_Indicates_Two_Ends) {
    vector<string> args = { "<example>", "list>" };

    Act(args);

    Assert("Wrong arguments format!");
}

TEST_F(ApplicationTest, Space_After_And_Before_Quotes_Works_Correctly) {
    vector<string> args = { "<", "example", "list", ">"};

    Act(args);

    Assert("TODO List Name:  example list ");
}

TEST_F(ApplicationTest, Application_Can_Name_List) {
    vector<string> args = {"<example", "list>"};

    Act(args);

    Assert("TODO List Name: example list");
}

TEST_F(ApplicationTest, Application_Can_Name_Task) {
    vector<string> args = { "<example", "list>", "<task", "name>" };

    Act(args);

    Assert("1. task name");
}
