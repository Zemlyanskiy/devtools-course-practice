// Copyright 2017 Zemlyanskiy Nikita

#include "../include/matrix_calculator.h"
#include "../include/matrix_calculator_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

MatrixCalculatorApp::MatrixCalculatorApp() : message_("") {}

void MatrixCalculatorApp::help(const char* appname, const char* message) {
    message_ = std::string(message) +
        "This is a matrix calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        
        "  $ " + appname + "<columns_of_firmt><rows_of_firmt>\n" +
        "<columns_of_secmt><rows_of_secmt>"+
        "<fir_value><sec_value><operation>\n\n " +

        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of '+', '-', '*','det'.\n ";
}

bool MatrixCalculatorApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    else if (argc == 7) {
        help(argv[0], "ERROR: Should be more than 7 arguments\n\n");
        return false;
    }
    return true;
}

double parseDouble(const std::string &arg) {
    char *end;
    double value = strtod(arg.c_str(), &end);

    if (end[0]) {
        throw std::invalid_argument("Wrong number format!");
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
    }
    else if (strcmp(arg, "-") == 0) {
        op = '-';
    }
    else if (strcmp(arg, "*") == 0) {
        op = '*';
    }
    else if (strcmp(arg, "det") == 0) {
        op = 'det';
    }
    else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string MatrixCalculatorApp::operator()(int argc, const char** argv) {
    Arguments args;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.columns_of_firmt = parseInt(argv[1]);
        args.rows_of_firmt = parseInt(argv[2]);
        args.columns_of_secmt = parseInt(argv[3]);
        args.rows_of_secmt = parseInt(argv[4]);
        args.fir_value = parseDouble(argv[5]);
        args.sec_value = parseDouble(argv[6]);
        args.operation = parseOperation(argv[7]);
    }
    catch (std::string& str) {
        return str;
    }

    MatrixCalculator z1;
    MatrixCalculator z2;
    std::vector<std::vector<double>> input_1(args.columns_of_firmt, std::vector<double>(args.rows_of_firmt, args.fir_value));
    std::vector<std::vector<double>> input_2(args.columns_of_secmt, std::vector<double>(args.rows_of_secmt, args.sec_value));

    z1.SetMatrix(input_1);
    z2.SetMatrix(input_2);

    MatrixCalculator z;
    std::ostringstream stream;
    switch (args.operation) {
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
    case 'det':
        stream<< "Determinant_of_first_matrix = "<< z1.Determinant();
        stream << "Determinant_of_second_matrix = " << z2.Determinant();
    }

    message_ = stream.str();

    return message_;
}
