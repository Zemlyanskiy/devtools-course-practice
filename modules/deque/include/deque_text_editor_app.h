// Copyright 2017 Nazarov Aleksandr

#ifndef MODULES_DEQUE_INCLUDE_DEQUE_TEXT_EDITOR_APP_H_
#define MODULES_DEQUE_INCLUDE_DEQUE_TEXT_EDITOR_APP_H_

#include <string>
#include <iostream>

class DequeTextEditorApp {
 public:
    DequeTextEditorApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool argValidate(int argc, const char** argv);
    std::string message_;
    // flags
    bool load_, save_, front_, write_;
    bool second_arguments_, sec_arg_load_, sec_arg_save_;
    bool sec_arg_front_, sec_arg_write_;
};

#endif  // MODULES_DEQUE_INCLUDE_DEQUE_TEXT_EDITOR_APP_H_
