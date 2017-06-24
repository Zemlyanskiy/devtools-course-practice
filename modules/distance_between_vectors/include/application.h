// Copyright 2017 Lobanov Andrey

#ifndef MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_APPLICATION_H_
#define MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_APPLICATION_H_

#include <vector>
#include <string>
#include "include/distance_between_vectors.h"

class Application {
 public:
  Application();
  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool ValidateNumberOfArguments(int argc, const char** argv);
  std::string message_;

  struct Arguments {
    int size;
    float init1;
    float init2;
    Metric::TypeMetric typemetric;
  };
};

#endif  // MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_APPLICATION_H_
