// Copyright 2017 Dmitrichev Nikita

#ifndef MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_APP_H_
#define MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_APP_H_

#include <string>
#include "include/length_converter.h"

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double old_length_size;
        LengthType old_length_name;
        LengthType new_length_name;
    } Arguments;
    Length* length = new Length(CENTIMETRE, 1.0);
};

#endif  // MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_APP_H_
