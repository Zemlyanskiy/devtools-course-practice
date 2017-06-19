// Copyright 2017 Dmitrichev Nikita

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/LengthConverterApp.h"

Application::Application() :message_("") {}

double ParseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }
    return value;
}

LengthType ParseLength(const char* arg) {
    LengthType length_name;
    if (strcmp(arg, "MICROMETRE") == 0)
        length_name = MICROMETRE;
    else if (strcmp(arg, "MILLIMETRE") == 0)
        length_name = MILLIMETRE;
    else if (strcmp(arg, "CENTIMETRE") == 0)
        length_name = CENTIMETRE;
    else if (strcmp(arg, "DECIMETRE") == 0)
        length_name = DECIMETRE;
    else if (strcmp(arg, "METRE") == 0)
        length_name = METRE;
    else if (strcmp(arg, "KILOMETRE") == 0)
        length_name = KILOMETRE;
    else if (strcmp(arg, "INCH") == 0)
        length_name = INCH;
    else if (strcmp(arg, "HAND") == 0)
        length_name = HAND;
    else if (strcmp(arg, "LINK") == 0)
        length_name = LINK;
    else if (strcmp(arg, "FOOT") == 0)
        length_name = FOOT;
    else if (strcmp(arg, "YARD") == 0)
        length_name = YARD;
    else if (strcmp(arg, "ROD") == 0)
        length_name = ROD;
    else if (strcmp(arg, "CHAIN") == 0)
        length_name = CHAIN;
    else if (strcmp(arg, "FURHLONG") == 0)
        length_name = FURHLONG;
    else if (strcmp(arg, "MILE") == 0)
        length_name = MILE;
    else if (strcmp(arg, "LEAGUE") == 0)
        length_name = LEAGUE;
    else
        throw std::string("Wrong length's name format!");
    return length_name;
}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a converter of a length application.\n\n" +
        "Please choose a size of a length, old and new length names and" +
        "provide arguments in the following format:\n\n" +

        "  $ " + appname + " <length's size> " +
        "<old length name> <new length name>\n\n" +

        "First argument should be double-precision number";
}


bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        args.old_length_size = ParseDouble(argv[1]);
        args.old_length_name = ParseLength(argv[2]);
        args.new_length_name = ParseLength(argv[3]);
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;

    length->SetValue(args.old_length_name, args.old_length_size);
    double result = length->ConvertTo(args.new_length_name);
    stream << "Result of conversation = " << result;

    message_ = stream.str();

    return message_;
}
