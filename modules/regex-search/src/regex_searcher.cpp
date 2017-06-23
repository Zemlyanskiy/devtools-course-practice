// Copyright 2017 Grachev Vlad

#include "include/regex_search.h"
#include "include/regex_searcher.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

RegexSearcher::RegexSearcher() : message_("") {}

void RegexSearcher::GetHelp(const char* applicationName, const char* message) {
    message_ =
        std::string(message) +
        "This is a simple regular expressions searcher. \n\n" +
        "Please provide arguments in the following format : \n\n"+

        " $ " + applicationName + " <regular expression> <your text> \n\n" +

        "Supported quantifiers: *, ?, +, {n} (1<=n<=9)\n" +
        "(only after some text somewhere before)\n\n" +
        "Parentheses and quanitifiers within another parenthesis are not allowed,\n" +
        "(however there can be nothing within parentheses)\n\n" +
        "\\n, \\r support, but \\<char> equals just <char>\n\n" +
        "There can be empty regular expressions\n\n";
}

bool RegexSearcher::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        GetHelp(argv[0]);
        return false;
    } else if (argc != 3) {
        GetHelp(argv[0], "ERROR: Should be 2 arguments\n\n");
        return false;
    }
    return true;
}
