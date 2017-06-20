// Copyright 2017 Bakalin Andrey

#include <string>
#include <fstream>

#include "include/todo_list.h"
#include "include/application.h"

Application::Application() {}

void Application::ReadList(TODOList *list, std::ifstream *fin) {
    int number_of_tasks;

    *fin >> number_of_tasks;
    for (int i = 0; i < number_of_tasks; i++) {
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

    for (int i = 0; i < list->GetCurrentTasksValue(); i++) {
        std::string task_name = list->GetTaskName(i);
        int is_done = 0;

        if (list->GetTaskStatus(i) == DONE_TASK)
            is_done = 1;

        *fout << task_name;
        *fout << is_done;
    }
}

void Application::help(const char* appname, const char* message) {}

std::string Application::operator()(int argc, const char** argv) {
    TODOList list();

    std::ifstream fin("data.txt");
    
    
    fin.close();
    return "";
}
