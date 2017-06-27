// Copyright 2017 Grachev Vlad

#include "include/regex_search.h"
#include "include/regex_searcher.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>

RegexSearcher::RegexSearcher() : message_("") {}

void RegexSearcher::GetHelp(const char* application_name, const char* message) {
    message_ =
        std::string(message) +
        "This is a simple regular expressions searcher. \n\n" +
        "Please provide arguments in the following format : \n\n"+

        " $ " + application_name + " <regular expression> <your text> \n\n" +

        "Supported quantifiers: *, ?, +, {n} (1<=n<=9)\n" +
        "(only after some text somewhere before)\n\n" +
        "Parentheses & quanitifiers within another parenthesis aren\'t" +
        " allowed,\n(however there can be nothing within parentheses)\n\n" +
        "\\n, \\r support, but \\<char> equals just <char>\n\n" +
        "There can be empty regular expressions\n\n";
}

bool RegexSearcher::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        GetHelp(argv[0]);
        return false;
    } else if (argc != 3) {
        GetHelp(argv[0], "ERROR: Should be 2 arguments.\n\n");
        return false;
    }
    return true;
}

std::string RegexSearcher::operator()(int argc, const char** argv) {
    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }

    std::string first_argument(argv[1]);
    std::string second_argument(argv[2]);
    std::vector<int> result;

    try {
        RegexSearch regularExpression((first_argument));
        if (second_argument.length() > RegexSearch::kMaxStringLength)
            throw RegexSearch::errorTooLongString;
        result = regularExpression.Find(second_argument);
    }
    catch (int error_code) {
        if (error_code == RegexSearch::errorTooLongRegex) {
            message_ = "Regular expression is too long!\n";
            return message_;
        }
        if (error_code == RegexSearch::errorRegExpIncorrect) {
            message_ = "Regular expression is incorrect!\n";
            return message_;
        }
        if (error_code == RegexSearch::errorTooLongString) {
            message_ = "Your text is too long!\n";
            return message_;
        }
    }

    if (result[0] == RegexSearch::errorNotFound) {
        message_ = "Not found!\n";
        return message_;
    }

    std::ostringstream stream;
    std::string temp_string = "";
    int result_size = result.size();
    stream << "Search result: \n";

    for (int i = 1; i < result_size; i += 2) {
        for (int j = result[i -1]; j < result[i - 1] + result[i]; j++)
            temp_string += second_argument[j];
        stream << temp_string << "\n";
        temp_string = "";
    }

    message_ = stream.str();

    return message_;
}
