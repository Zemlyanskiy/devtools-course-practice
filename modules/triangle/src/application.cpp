// Copyright 2017 Tarasov Oleg

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/triangle.h"
#include "include/application.h"

Application::Application() {}

int parseOperation(const char* arg) {
    int op = 0;
    if (strcmp(arg, "side") == 0) {
        op = 1;
    } else if (strcmp(arg, "corner") == 0) {
        op = 2;
    } else if (strcmp(arg, "perimeter") == 0) {
        op = 3;
    } else if (strcmp(arg, "square") == 0) {
        op = 4;
    } else if (strcmp(arg, "median") == 0) {
        op = 5;
    } else if (strcmp(arg, "circumscribed_circle") == 0) {
        op = 6;
    } else if (strcmp(arg, "inscribed_circle") == 0) {
        op = 7;
    } else {
        throw std::string("Wrong operation name!");
    }
    return op;
}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a triangle calculator application.\n\n" +
        "Please choose an operation and provide arguments " +
        "in the following format:\n\n" +

        "  $ " + appname + " <coord1_x> <coord1_y> " +
        "<coord2_x> <coord2_y> <coord3_x> <coord3_y> <operation> [<num>]\n\n" +

        "All arguments should be double-precision numbers\n" +
        "You can use next operations: side, corner, perimeter, square," +
        "    median, circumscribed_circle, inscribed_circle" +
        "<num> is necessary for side and corner calculation where " +
        "<num> is a number of corner/side counting from coord1 to coord3";
}


bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc < 8 || argc > 9 ||
        (parseOperation(argv[7]) >= 1 &&
        parseOperation(argv[7]) <= 2 && argc != 9)
        || (parseOperation(argv[7]) > 2 && argc != 8)) {
        help(argv[0], "ERROR: Incorrect arguments num.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    return value;
}

int parseInt(const char* arg) {
    int value = atoi(arg);

    if (value <= 0 || value > 3) {
        throw std::string("Wrong number format!");
    }
    return value;
}


std::string Application::operator()(int argc, const char** argv) {
    Arguments args;
    double result;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.point1_coordx = parseDouble(argv[1]);
        args.point1_coordy = parseDouble(argv[2]);
        args.point2_coordx = parseDouble(argv[3]);
        args.point2_coordy = parseDouble(argv[4]);
        args.point3_coordx = parseDouble(argv[5]);
        args.point3_coordy = parseDouble(argv[6]);
        args.operation = parseOperation(argv[7]);
        if (args.operation >= 1 && args.operation <= 2)
            args.num = parseInt(argv[8]);
    }
    catch (std::string& str) {
        return str;
    }

    Triangle triangle(args.point1_coordx, args.point1_coordy,
        args.point2_coordx, args.point2_coordy,
        args.point3_coordx, args.point3_coordy);

    std::ostringstream stream;
    switch (args.operation) {
    case 1:
        result = triangle.CalculateSide(args.num);
        stream << "Triangle Side #" << args.num << " = " << result;
        break;
    case 2:
        result = triangle.CalculateCorner(args.num);
        stream << "Triangle Corner #" << args.num << " = " << result;
        break;
    case 3:
        result = triangle.CalculatePerimeter();
        stream << "Triangle Perimeter = " << result;
        break;
    case 4:
        result = triangle.CalculateSquare();
        stream << "Triangle Square = " << result;
        break;
    case 5:
        stream << "Triangle Median Coords = " <<
            triangle.GetCoordXMedian() << ", " <<
            triangle.GetCoordYMedian();
        break;
    case 6:
        stream << "Triangle Circumscribed Circle Center = " <<
            triangle.GetCoordXCircumscribedCircle() << ", " <<
            triangle.GetCoordYCircumscribedCircle();
        break;
    case 7:
        stream << "Triangle Inscribed Circle Center = " <<
            triangle.GetCoordXInscribedCircle() << ", " <<
            triangle.GetCoordYInscribedCircle();
        break;
    }

    message_ = stream.str();
    return message_;
}
