// Copyright 2017 Zemlyanskiy Nikita

#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <stdexcept>

#include "../include/matrix_calculator_app.h"
#include "../include/matrix_calculator.h"

MatrixCalculatorApp::MatrixCalculatorApp() : message_("") {}
using std::vector;
using std::string;

void MatrixCalculatorApp::help(const char* appname, const char* message) {
    message_ = string(message) +
        "This is a matrix calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + "<fir_value><sec_value>"+
        "<operation>\n\n " +

        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of '+', '-', '*'.\n ";
}

bool MatrixCalculatorApp::validateNumberOfArguments(int argc,
                                                    const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc > 4) {
        help(argv[0], "ERROR: Should be not more than 3 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

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
    } else {
        throw string("Wrong operation format!");
    }
    return op;
}

string MatrixCalculatorApp::operator()(int argc, const char** argv) {
    double val_of_firmt;
    double val_of_secmt;
    char operation;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        val_of_firmt = parseDouble(argv[1]);
        val_of_secmt = parseDouble(argv[2]);
        operation = parseOperation(argv[3]);
    }
    catch (string& str) {
        return str;
    }

    MatrixCalculator z1;
    MatrixCalculator z2;
    vector<vector<double>> v1(4, vector<double>(4, val_of_firmt));
    vector<vector<double>> v2(4, vector<double>(4, val_of_secmt));
    MatrixCalculator z;
    std::ostringstream stream;
    switch (operation) {
    case '+':
        z = z1 + z2;
        stream << "Det of sum = " << z.Determinant();
        break;
    case '-':
        z = z1 - z2;
        stream << "Det of difference = " << z.Determinant();
        break;
    case '*':
        z = z1 * z2;
        stream << "Det of multiplication = " << z.Determinant();
        break;
    }

    message_ = stream.str();

    return message_;
}
