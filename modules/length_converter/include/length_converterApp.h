// Copyright 2017 Dmitrichev Nikita

#ifndef MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTERAPP_H_
#define MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTERAPP_H_

#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTERAPP_H_