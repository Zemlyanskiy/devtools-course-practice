// Copyright 2017 Bilkovsky Alexander

#include "include/Demand_app.h"
#include "include/Demand.h"
#include <stdio.h>
#include <sstream>
#include <string>

DemandApp::DemandApp() : message_("") {}

void DemandApp::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is an elasticity calculator\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <old price> " + "<new price> " + "<old demand> "
        "<new demand>\n\n";
}
bool DemandApp::ArgsIsOk(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 5) {
        Help(argv[0], "ERROR: Incorrect number of arguments\n\n");
        return false;
    }
    return true;
}
double ParseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);
    if (end[0])
        throw std::string("Wrong number format");
    return value;
}
std::string DemandApp::operator()(int argc, const char** argv) {
    Args args;
    if (!ArgsIsOk(argc, argv))
        return message_;
    try {
        args.newprice = ParseDouble(argv[1]);
        args.oldprice = ParseDouble(argv[2]);
        args.newdemand = ParseDouble(argv[3]);
        args.olddemand = ParseDouble(argv[4]);
    }
    catch (std::string &str) {
        return str;
    }
    Demand dem(args.oldprice, args.newprice, args.olddemand, args.newdemand);
    dem.CheckForElasticity();
    std::ostringstream stream;
    stream << "Elasticity: " << dem.GetElasticity();
    message_ = stream.str();
    return message_;
}
