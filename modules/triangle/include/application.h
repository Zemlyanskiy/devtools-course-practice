// Copyright 2017 Tarasov Oleg

#ifndef MODULES_TRIANGLE_INCLUDE_APPLICATION_H_
#define MODULES_TRIANGLE_INCLUDE_APPLICATION_H_

#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_TRIANGLE_INCLUDE_APPLICATION_H_
