// Copyright 2017 Bakalin Andrey

#ifndef MODULES_TODO_LIST_INCLUDE_APPLICATION_H_
#define MODULES_TODO_LIST_INCLUDE_APPLICATION_H_

#include <string>
#include "include/toto_list.h"

class Application {
  public:
    Application();
    std::string operator()(int argc, const char** argv);

  private:
    std::string message_;
};

#endif  // MODULES_TODO_LIST_INCLUDE_APPLICATION_H_
