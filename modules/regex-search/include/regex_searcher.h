// Copyright 2017 Grachev Vlad

#ifndef MODULES_REGEX_SEARCH_INCLUDE_REGEX_SEARCHER_H_
#define MODULES_REGEX_SEARCH_INCLUDE_REGEX_SEARCHER_H_

#include <string>

class RegexSearcher {
 public:
    RegexSearcher();
    std::string operator()(int argc, const char** argv);

 private:
    void GetHelp(const char* applicationName, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);

    std::string message_;
};

#endif  // MODULES_REGEX_SEARCH_INCLUDE_REGEX_SEARCHER_H_
