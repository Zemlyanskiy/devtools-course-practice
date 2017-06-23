// Copyright 2017 Grachev Vlad

#include <gtest/gtest.h>

#include "include/regex_searcher.h"

TEST(RegexSearcherTest, Can_Create_Regex_Searcher) {
    ASSERT_NO_THROW(RegexSearcher _regexSearcher1);
}
