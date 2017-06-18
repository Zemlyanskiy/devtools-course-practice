// Copyright 2017 Dmitrichev Nikita

#include "include/length_converter.h"
#include "include/length_converterApp.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

Application::Application() {}

std::string Application::operator()(int argc, const char** argv) {
    return "test";
} 
