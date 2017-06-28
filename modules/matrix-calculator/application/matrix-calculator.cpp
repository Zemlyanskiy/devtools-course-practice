// Copyright 2017 Zemlyanskiy Nikita

#include <stdlib.h>
#include <iostream>
#include <string>

#include "../include/matrix_calculator_app.h"

int main(int argc, const char** argv) {
    MatrixCalculatorApp app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;

    return 0;
}
