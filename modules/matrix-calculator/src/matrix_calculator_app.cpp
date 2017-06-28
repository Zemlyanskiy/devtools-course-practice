// Copyright 2017 Zemlyanskiy Nikita

#include "../include/matrix_calculator.h"
#include "../include/matrix_calculator_app.h"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>

MatrixCalculatorApp::MatrixCalculatorApp() : message_("") {}

void MatrixCalculatorApp::help(const char* appname, const char* message) {
    message_ = std::string(message) +
        "This is a matrix calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + "<columns_of_firmt><rows_of_firmt>\n" +
        "<columns_of_secmt><rows_of_secmt>"+
        "<fir_value><sec_value><operation>\n\n " +

        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of '+', '-', '*','d'.\n ";
}

bool MatrixCalculatorApp::validateNumberOfArguments(int argc,
                                                    const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 8) {
        help(argv[0], "ERROR: Should be not more than 7 arguments\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end = 0;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

double parseInt(const char* args) {
    char* end = 0;
    int value = strtol(args, &end, 10);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "d") == 0) {
        op = 'd';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string MatrixCalculatorApp::operator()(int argc, const char** argv) {
    int col1;
    int col2;
    int row1;
    int row2;
    double val1; 
    double val2;
    char operation;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        col1 = parseInt(argv[1]);
        row1 = parseInt(argv[2]);
        col2 = parseInt(argv[3]);
        row2 = parseInt(argv[4]);
        val1 = parseDouble(argv[5]);
        val2 = parseDouble(argv[6]);
        operation = parseOperation(argv[7]);
    }
    catch (std::string& str) {
        return str;
    }

    MatrixCalculator z1;
    MatrixCalculator z2;

    std::vector<std::vector<double>> input_1(col1,
                                             std::vector<double>(row1, val1));
    std::vector<std::vector<double>> input_2(col2,
                                             std::vector<double>(row2, val2));

    z1.SetMatrix(input_1);
    z2.SetMatrix(input_2);

    MatrixCalculator z;
    std::ostringstream stream;
    switch (operation) {
    case '+':
        z = z1 + z2;
        stream << "Sum = " << z;
        break;
    case '-':
        z = z1 - z2;
        stream << "Difference= " << z;
        break;
    case '*':
        z = z1 * z2;
        stream << "Multiplication = " << z;
        break;
    case 'd':
        stream << "Determinant_of_first_matrix = "<< z1.Determinant();
        stream << "Determinant_of_second_matrix = " << z2.Determinant();
    }

    message_ = stream.str();

    return message_;
}
