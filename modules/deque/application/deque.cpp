// Copyright 2017 Nazarov Aleksandr

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/deque_text_editor_app.h"

int main(int argc, const char** argv) {
    DequeTextEditorApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
