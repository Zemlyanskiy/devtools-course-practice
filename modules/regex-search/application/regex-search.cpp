// Copyright 2017 Grachev Vlad

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/regex_searcher.h"

int main(int argc, const char** argv) {
    RegexSearcher application;
    std::string output = application(argc, argv);
    printf("%s", output.c_str());
    return 0;
}
