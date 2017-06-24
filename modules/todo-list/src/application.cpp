// Copyright 2017 Bakalin Andrey

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <fstream>

#include "include/todo_list.h"
#include "include/application.h"

Application::Application() : message_("") {}

void Application::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a TODO-list application.\n\n" +
          "You can choose one of this commands:\n\n"+

          "  $ " + appname + " show \n"+
          "  $ " + appname + " add <task name> \n"+
          "  $ " + appname + " delete <task index> \n"+
          "  $ " + appname + " done <task index> \n"+
          "  $ " + appname + " undone <task index> \n"+
          "  $ " + appname + " clear";
}

std::string Application::operator()(int argc, const char** argv) {
    TODOList list;

    Help(argv[0]);

    return message_;
}
