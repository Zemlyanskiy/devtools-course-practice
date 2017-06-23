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