// Copyright 2017 Tarasov Oleg

#include "include/triangle.h"
#include "include/application.h"

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