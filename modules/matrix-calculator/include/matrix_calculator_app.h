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
    typedef struct {
        int rows_of_firmt;
        int columns_of_firmt;
        int rows_of_secmt;
        int columns_of_secmt;
        double fir_value;
        double sec_value;
        char operation;
    } Arguments;
};

#endif  // MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_H_
