// Copyright 2017 Bilkovsky Alexander

#include "include\Demand_app.h"
#include "include\Demand.h"
#include <sstream>
#include <stdio.h>

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
    }
    else if (argc != 5) {
        Help(argv[0], "ERROR: Incorrect number of arguments\n\n");
        return false;
    }
    return true;
}
double ParseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);
    if (end[0])
        throw string("Wrong number format");
    return value;
}
string DemandApp::operator()(int argc, const char** argv){
    Args args;
    if (!ArgsIsOk(argc, argv))
        return message_;
    try {
        args.newprice = ParseDouble(argv[1]);
        args.oldprice = ParseDouble(argv[2]);
        args.newdemand = ParseDouble(argv[3]);
        args.olddemand = ParseDouble(argv[4]);
    }
    catch (string &str) {
        return str;
    }
    Demand dem(args.oldprice,args.newprice,args.olddemand,args.newdemand);
    dem.CheckForElasticity();
    ostringstream stream;
    stream << "Delta price: " << dem.GetDeltaPrice() << "\nDelta demand :" << dem.GetDeltaDemand() << "\nElasticity : " << dem.GetElasticity();
    message_ = stream.str();
    return message_;
}