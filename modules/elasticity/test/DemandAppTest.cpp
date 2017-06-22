// Copyright 2017 Bilkovsky Alexander

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/Demand_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;


class DemandAppTest : public ::testing::Test {
protected:
	void Act(vector<string> args_) {
		vector<const char *> options;

		options.push_back("appname");
		for (size_t i = 0; i < args_.size(); ++i) {
			options.push_back(args_[i].c_str());
		}

		const char **argv = &options.front();
		int argc = static_cast<int>(args_.size()) + 1;

		output_ = app_(argc, argv);
	}

	void Assert(std::string expected) {
		EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
	}

private:
	DemandApp app_;
	string output_;
};

TEST_F(DemandAppTest, Do_Print_Help_Without_Arguments) {
	std::vector<std::string> args = {};

	Act(args);

	Assert("This is an elasticity calculator*");
}

TEST_F(DemandAppTest, Is_Checking_Number_Of_Arguments) {
	vector<string> args = { "0.5", "3.0" };

	Act(args);

	Assert("ERROR: Incorrect number of arguments");
}

TEST_F(DemandAppTest, Is_Checking_Argument) {
	vector<string> args = { "0.4", "0.9", "G", "7" };

	Act(args);

	Assert("Wrong number format");
}
