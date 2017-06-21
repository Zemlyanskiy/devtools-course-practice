// Copyright 2017 Bilkovsky Alexander

#ifndef MODULES_ELASTICITY_INCLUDE_APPLICATION_H_
#define MODULES_ELASTICITY_INCLUDE_APPLICATION_H_

#include <string>
using namespace std;

class DemandApp {
 public:
     DemandApp();
     string operator()(int argc, const char** argv);
 private:
     void Help(const char* appname, const char* message = "");
     bool ArgsIsOk(int argc, const char** argv);
     struct Args {
         double oldprice;
         double newprice;
         double olddemand;
         double newdemand;
     };
     string message_;
};

#endif MODULES_ELASTICITY_INCLUDE_APPLICATION_H_