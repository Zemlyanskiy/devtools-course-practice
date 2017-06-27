// Copyright 2017 Bilkovsky Alexander

#ifndef MODULES_ELASTICITY_INCLUDE_DEMAND_APP_H_
#define MODULES_ELASTICITY_INCLUDE_DEMAND_APP_H_

#include <string>

class DemandApp {
 public:
     DemandApp();
     std::string operator()(int argc, const char** argv);
 private:
     void Help(const char* appname, const char* message = "");
     bool ArgsIsOk(int argc, const char** argv);
     struct Args {
         double oldprice;
         double newprice;
         double olddemand;
         double newdemand;
     };
     std::string message_;
};

#endif  // MODULES_ELASTICITY_INCLUDE_DEMAND_APP_H_
