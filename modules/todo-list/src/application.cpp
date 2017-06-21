// Copyright 2017 Bakalin Andrey

#include <string>
#include <fstream>

#include "include/todo_list.h"
#include "include/application.h"

Application::Application() {}

void Application::ReadList(TODOList *list, std::ifstream *fin) {
    size_t number_of_tasks;

    *fin >> number_of_tasks;
    for (size_t i = 0; i < number_of_tasks; i++) {
        std::string task_name;
        int is_done;
        *fin >> task_name;
        *fin >> is_done;

        list->NewTask(task_name);
        if (is_done == 1)
            list->SetTaskDone(i);
    }
}

void Application::WriteList(TODOList *list, std::ofstream *fout) {
    *fout << list->GetCurrentTasksValue();

    for (size_t i = 0; i < list->GetCurrentTasksValue(); i++) {
        std::string task_name = list->GetTaskName(i);
        int is_done = 0;

        if (list->GetTaskStatus(i) == DONE_TASK)
            is_done = 1;

        *fout << task_name;
        *fout << is_done;
    }
}

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

bool Application::CheckCorrectnessOfCommand(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    }

    std::string command = argv[1];

    if (command == "delete" || command == "done" || command == "undone") {
        if (argc != 3) {
            Help(argv[0], "ERROR: unknown command format!");
            return false;
        }
    } else if (command == "add") {
        if (argc == 2) {
            Help(argv[0], "ERROR: please enter a name!");
            return false;
        }
    } else if (command != "show" && command != "clear") {
        Help(argv[0], "ERROR: unknown command!");
        return false;
    }

    return true;
}

std::string Application::operator()(int argc, const char** argv) {
    TODOList list;

    std::ifstream fin("data.txt");
    if (fin.is_open()) {
        ReadList(&list, &fin);
    }
    fin.close();

    std::ofstream fout("data.txt", std::ofstream::out);
    fout.close();

    if (!CheckCorrectnessOfCommand(argc, argv)) {
        return message_;
    }

    return "";
}
