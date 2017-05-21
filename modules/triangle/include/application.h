// Copyright 2017 Tarasov Oleg

#ifndef MODULES_TRIANGLE_INCLUDE_APPLICATION_H_
#define MODULES_TRIANGLE_INCLUDE_APPLICATION_H_

#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double point1_coordx;
        double point1_coordy;
        double point2_coordx;
        double point2_coordy;
        double point3_coordx;
        double point3_coordy;
        int operation;
        int num;                // for side and corner
    } Arguments;
};

#endif  // MODULES_TRIANGLE_INCLUDE_APPLICATION_H_
