// Copyright 2017 Zemlyanskiy Nikita

#ifndef MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_APP_H_
#define MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_APP_H_

#include <string>

class MatrixCalculatorApp {
 public:
    MatrixCalculatorApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);

    std::string message_;
};

#endif  // MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_APP_H_
